### For reading profile outputs.
which.profiler <- function(file.name)
{
  test <- readLines(file.name, n=1)
  
  if (length(grep(pattern="FPMPI", x=test)) > 0)
    return( 'fpmpi' )
  else
    stop("This profiler is not implemented at this time.")
}


read.prof <- function(file.name, ...)
{
  if(! file.exists(file.name[1L])){
    stop("The input file does not exist")
  }
  
  profiler <- which.profiler(file.name)
  
  raw <- readLines(file.name[1L], ...)
  
  if (profiler == 'fpmpi')
    parsed <- parse.prof.fpmpi(x=raw)
  
  ret <- new("prof", profiler=profiler, raw=raw, parsed=parsed)
  
  return( ret )
} # End of read.prof().





