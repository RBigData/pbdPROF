### For S3 class.

print.fpmpi.parse <- function(x, digits = max(4, getOption("digits") - 3), ...){
  op.org <- options()
  options(digits = digits)

  x <- do.call("rbind", x)
  x <- as.data.frame(x)
  print(x)

  options(op.org)
  invisible()
} # End of print.fpmpi.parse().

summary.fpmpi.parse <- function(object, ...){
  cat("FPMPI Output\n")
  print.fpmpi.parse(object)
} # End of summary.fpmpi.parse().


print.mpip.parse <- function(x, digits = max(4, getOption("digits") - 3), ...){
  op.org <- options()
  options(digits = digits)

  # NTD

  options(op.org)
  invisible()
} # End of print.mpip.parse().

summary.mpip.parse <- function(object, ...){
  cat("mpiP Output\n")
  print.mpip.parse(object)
} # End of summary.mpip.parse().


print.tau.parse <- function(x, digits = max(4, getOption("digits") - 3), ...){
  op.org <- options()
  options(digits = digits)

  # NTD

  options(op.org)
  invisible()
} # End of print.tau.parse().

summary.tau.parse <- function(object, ...){
  cat("TAU Output\n")
  print.tau.parse(object)
} # End of summary.tau.parse().

