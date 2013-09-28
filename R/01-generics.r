setGeneric(name = "print", useAsDefault = base::print, package="pbdPROF")
setGeneric(name = "plot", function(x, ...) standardGeneric("plot"), package="pbdPROF")

### This is already S4 in the methods package, imports from NAMESPACE.
### While print and plot are both S3 rather than S4, so the above turns
### them into S4.
# setGeneric(name = "show", useAsDefault = methods::show, package="pbdPROF")

