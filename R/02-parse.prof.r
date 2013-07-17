### For parsing profile outputs.

parse.prof <- function(x, ...){
  UseMethod("parse.prof")
} # End of parse.prof().


### Internal library.
parse.prof.default <- function(x, ...){
  ret.class <- class(x)
  stop(paste("Function for class (", ret.class, ") is not found", sep = ""))
  invisible()
} # End of parse.prof.default()

parse.prof.fpmpi <- function(x, ...){

} # End of parse.prof.fpmpi().

parse.prof.mpip <- function(x, ...){

} # End of parse.prof.mpip().

parse.prof.tau <- function(x, ...){

} # End of parse.prof.tau().

