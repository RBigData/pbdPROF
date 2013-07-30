### print and show methods
which.article <- function(profiler)
{
  if (profiler == 'fpmpi' || profiler == 'mpiP')
    return( "An" )
  else if (profiler == 'tau' )
    return( "A" )
  else
    stop("Unknown profiler")
}

setMethod("print", signature(x="prof"),
  function(x, ...)
  {
    cat(sprintf(paste(which.article(x@profiler), x@profiler, "profiler object:\n")))
    print(x@parsed)
  }
)


setMethod("show", signature(object="prof"),
  function(object){
    print(object)
  }
)

