# plot method
setMethod("plot", signature(x="prof"),
  function(x, ..., which=1L:4L, show.title=TRUE, plot.type="timing", label, bar.label=FALSE)
  {
    if (missing(label))
      show.title <- TRUE
    else if (is.null(label))
      show.title <- FALSE
    
    if (x@profiler == 'fpmpi')
      plot_fpmpi(x, ..., which = which, show.title = show.title,
                 plot.type = plot.type, label = label, bar.label = bar.label)
    else if (x@profiler == 'mpip')
      plot_mpip(x, ..., which = which, show.title = show.title,
                plot.type = plot.type, label = label, bar.label = bar.label)
    else if (x@profiler == 'tau')
      plot_tau(x, ..., which = which, show.title = show.title,
               plot.type = plot.type, label = label, bar.label = bar.label)
    else
      stop("Unknown profiler")
  }
)



# autoplot compatibility
autoplot.prof <- function(object, ...)
{ 
  plot(object, ...)
}
