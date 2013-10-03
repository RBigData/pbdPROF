### This file implements SPMD parallel framework.
### No distinguish for manster or worker, and everyone does the same jobs.

### Load library.
library(pbdMPI, quietly = TRUE)
init()

### Check # of processors.
if(comm.size() != 3){
  comm.stop("3 processors are requried.")
}

### Generate data.
comm.set.seed(1234)
n <- 100
X <- runif(n * comm.size())
X <- X[(1:n) + n * comm.rank()]                          # each owns 100 samples

### Define quantile function in SPMD.
quantile.spmd <- function(x.gbd, prob = 0.5){
  if(sum(prob < 0 | prob > 1) > 0){
    stop("prob should be in (0, 1)")
  }

  ### Get information from everyone to everyone.
  N <- allreduce(length(x.gbd), op = "sum")              # global sample size
  x.min <- allreduce(min(x.gbd), op = "min")             # global leftest data
  x.max <- allreduce(max(x.gbd), op = "max")             # global rightest data
  # comm.print(c(x.min, x.max), quiet = TRUE)              # debug

  f.quantile <- function(x, prob = 0.5){
    # comm.print(x, quiet = TRUE)                          # debug
    allreduce(sum(x.gbd <= x), op = "sum") / N - prob    # bisection
  }
  uniroot(f.quantile, c(x.min, x.max), prob = prob[1])$root
} # End of quantile.spmd().

### Run.
q50.X <- quantile.spmd(X)
comm.print(q50.X)

### Finish.
finalize()
