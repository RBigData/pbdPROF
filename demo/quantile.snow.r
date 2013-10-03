### This file implements parallel framework in snow-like cluster.
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
  X <- X[(1:n) + n * (comm.rank() - 1)]               # each owns 100 samples
}

### Define quantile function in SPMD.
quantile.snow <- function(x.gbd, prob = 0.5){
  if(sum(prob < 0 | prob > 1) > 0){
    stop("prob should be in (0, 1)")
  }

  ### The master function.
  master <- function(prob = 0.5){
    ### Get information from workers who own data.
    N <- 0L                                           # global sample size
    for(i in 1:(comm.size() - 1)){
      N <- N + recv(x.buffer = 0L, rank.source = i)
    }
    x.min <- Inf                                      # global leftest data
    for(i in 1:(comm.size() - 1)){
      x.min <- min(x.min, recv(x.buffer = 0.0, rank.source = i))
    }
    x.max <- -Inf                                     # global rightest data
    for(i in 1:(comm.size() - 1)){
      x.max <- max(x.max, recv(x.buffer = 0.0, rank.source = i))
    }
    # print(c(x.min, x.max))                            # debug

    ### The master handles optimization.
    f.quantile <- function(x, prob = 0.5){
      for(i in 1:(comm.size() - 1)){
        send(TRUE, rank.dest = i)                     # keep workers running
      }
      for(i in 1:(comm.size() - 1)){
        send(x, rank.dest = i)                        # new bisection x
      }
      # print(x)                                        # debug
      n <- 0L
      for(i in 1:(comm.size() - 1)){                  # global # less than new x
        n <- n + recv(x.buffer = 0L, rank.source = i)
      }
      return(n / N - prob)                            # proportion to prob
    }
    ret <- uniroot(f.quantile,
                   c(x.min, x.max),
                   prob = prob[1])$root               # bisection
    for(i in 1:(comm.size() - 1)){
      send(FALSE, rank.dest = i)                      # to stop workers
    }
    return(ret)
  } # End of master().

  ### The workers function.
  workers <- function(x.gbd){
    ### Send information to master who don't own data.
    send(length(x.gbd), rank.dest = 0L)               # new bisection x
    send(min(x.gbd), rank.dest = 0L)                  # local leftest
    send(max(x.gbd), rank.dest = 0L)                  # local rightest

    ### The workers summarize data and reduce to the master.
    repeat{
      flag <- recv(x.buffer = TRUE, rank.source = 0L) # workers run
      if(! flag){
        break
      }
      x <- recv(x.buffer = 0.0, rank.source = 0L)     # get new bisection x
      send(sum(x.gbd <= x), rank.dest = 0L)           # local # less than new x
    }
  }

  ### Run
  if(comm.rank() == 0){
    master(prob = prob)
  } else{
    workers(x.gbd)
  }
} # End of quantile.snow().

### Run.
q50.X <- quantile.snow(X)
comm.print(q50.X)

### Finish.
finalize()
