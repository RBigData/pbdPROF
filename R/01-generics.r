setGeneric(name = "print", useAsDefault = base::print, package="pbdPROF")
setGeneric(name = "show", useAsDefault = methods::show, package="pbdPROF")

setGeneric(name = "plot", function(x, ...) standardGeneric("plot"), package="pbdPROF")
