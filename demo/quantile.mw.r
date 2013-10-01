### This file implements master/workers parallel framework.
### Rank 0 is the manster and controls jobs.
### Rank 1, 2, and 3 are the workers and process jobs.

### Load library.
library(pbdMPI, quietly = TRUE)
init()

### Check # of processors.
if(comm.size() != 4){
  comm.stop("4 processors are requried.")
}

### Generate fake data for rank 1, 2, and 3.
X <- NULL
if(comm.rank() != 0){
  comm.set.seed(1234)
  n <- 100
  X <- runif(n * (comm.size() - 1))
  X <- X[(1:n) + n * (comm.rank() - 1)]                # each owns 100 samples
}

### Define quantile function in SPMD.
quantile.mw <- function(x.gbd, prob = 0.5){
  if(sum(prob < 0 | prob > 1) > 0){
    stop("prob should be in (0, 1)")
  }

  ### The master function.
  master <- function(prob = 0.5){
    ### Get information from workers who own data.
    N <- reduce(0L, op = "sum")                        # global sample size
    x.max <- reduce(-Inf, op = "max")                  # global rightest data
    x.min <- reduce(Inf, op = "min")                   # global leftest data
    # print(c(x.min, x.max))                            # debug

    ### The master handles optimization.
    f.quantile <- function(x, prob = 0.5){
      bcast(TRUE)                                      # keep workers running
      bcast(x)                                         # new bisection x
      # print(x)                                         # debug
      n <- reduce(0L)                                  # global # less than new x
      return(n / N - prob)                             # proportion to prob
    }
    ret <- uniroot(f.quantile,
                   c(x.max, x.min),
                   prob = prob[1])$root                # bisection
    bcast(FALSE)                                       # to stop workers
    return(ret)
  } # End of master().

  ### The workers function.
  workers <- function(x.gbd){
    ### Send information to master who don't own data.
    reduce(length(x.gbd), op = "sum")                  # local same size
    reduce(max(x.gbd), op = "max")                     # local rightest
    reduce(min(x.gbd), op = "min")                     # local leftest

    ### The workers summarize data and reduce to the master.
    repeat{
      flag <- bcast(TRUE)                              # workers run
      if(! flag){
        break
      }
      x <- bcast(0.0)                                  # get new bisection x
      reduce(sum(x.gbd <= x))                          # local # less than new x
    }
  }

  ### Run
  if(comm.rank() == 0){
    master(prob = prob)
  } else{
    workers(x.gbd)
  }
} # End of quantile.mw().

### Run.
q50.X <- quantile.mw(X)
comm.print(q50.X)

### Finish.
finalize()
