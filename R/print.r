#' Printing
#' 
#' Print and show methods for \code{prof} class objects.
#' 
#' @docType methods
#' @param x,object
#' A \code{prof} class object
#' @param ...
#' extra arguments
#' 
#' @seealso \code{ \link{prof-class}, \link{read.prof} }
#' @keywords Methods
#' @name prof-print
#' @rdname prof-print
NULL

#' @rdname prof-print
#' @export
setMethod("print", signature(x="prof"),
  function(x, ...) printprof(x)
)

#' @rdname prof-print
#' @export
setMethod("show", signature(object="prof"),
  function(object) printprof(object)
)



which.article <- function(profiler)
{
  if (profiler == 'fpmpi' || profiler == 'mpip')
    return("An")
  else if (profiler == 'tau')
    return("A")
  else
    stop("Unknown profiler")
}



title_case <- function(x) gsub(x, pattern="(^|[[:space:]])([[:alpha:]])", replacement="\\1\\U\\2", perl=TRUE)



printprof <- function(x)
{
  cat(sprintf(paste(which.article(x@profiler), x@profiler, "profiler object:\n")))
  
  x <- attr(x@parsed, "Metadata")
  maxlen <- max(sapply(names(x), nchar))
  names <- gsub(names(x), pattern="_", replacement=" ")
  names <- title_case(x=names)
  spacenames <- simplify2array(lapply(names, function(str) paste0(str, ":", paste0(rep(" ", maxlen-nchar(str)), collapse=""))))
  
  maxlen <- max(sapply(x, function(y) nchar(paste(y))))
  
  lapply(1:length(x), function(i) cat(paste("  ", spacenames[i], x[[i]], sep=" ", collapse="\n"), "\n"))
  
  invisible()
}
