### For reading profile outputs.

read.prof <- function(file.name, lib.type = .PROF.CT$lib.type, ...){
  if(! file.exists(file.name[1])){
    stop("The input file is not exists")
  }

  lib.type <- match.arg(tolower(lib.type[1]), .PROF.LIB)
 
  if(lib.type[1] == "fpmpi"){
    ret <- readLines(file.name[1], ...)
    class(ret) <- "fpmpi.read"
  } else if(lib.type[1] == "mpip"){
    ret <- readLines(file.name[1], ...)
    class(ret) <- "mpip.read"
  } else if(lib.type[1] == "tau"){
    ret <- readLines(file.name[1], ...)
    class(ret) <- "tau.read" 
  } else{
    stop("The reading function is not implemented.")
  }

  ret
} # End of read.prof().

