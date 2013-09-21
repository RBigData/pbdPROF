### Virtual classes
setClass("rawprof", representation="VIRTUAL")
setClass("fpmpi", contains="rawprof", representation="VIRTUAL")
setClass("mpip", contains="rawprof", representation="VIRTUAL")
setClass("tau", contains="rawprof", representation="VIRTUAL")


### Profiler class checker
valid_prof <- function(object)
{
  profilers <- c("fpmpi", "mpip", "tau")
  
  if ( !(object@profiler %in% profilers) )
    return("Invalid profiler")
  
  if (object@profiler != class(object@raw))
    return("'profiler' slot does not match class of 'raw' slot")
  
  return( TRUE )
}


### Profiler class 'prof'
setClass(
         "prof", 
          representation(
                         profiler="character",
                         raw="rawprof",
                         parsed="list"
          ),
          validity=valid_prof
)

