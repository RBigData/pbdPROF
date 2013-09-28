\name{Example datasets}

\alias{allreduce.fpmpi}
\alias{masterslavePI.fpmpi}
\alias{svd.fpmpi}
\alias{allreduce.mpip}
\alias{masterslavePI.mpip}
\alias{svd.mpip}
\alias{fpmpi_example}
\alias{mpip_example}

\docType{data}
\title{Small example datasets}

\description{
  Sample profiler outputs for testing and package demonstration.
}
\format{
  Each dataset contains information profiled by \pkg{fpmpi}
  for \code{pbdMPI/demo/allreduce.fpmpi.r}, \code{pbdDMAT/demo/svd.fpmpi.r}, and
  \code{Rmpi/demo/masterslavePI.fpmpi.r}.

  Each dataset contains information profiled by \pkg{mpiP}
  for \code{pbdMPI/demo/allreduce.mpip.r}, \code{pbdDMAT/demo/svd.mpip.r}, and
  \code{Rmpi/demo/masterslavePI.mpip.r}.
}
\details{
  Several sample profiler outputs are provided with the package, and utilized
  in the package demos to show off the functionality of the parsing and 
  plotting methods provided by the package.  These small datasets are 
  located in the \code{pbdPROF/extdata/} folder of the installed package
  (and \code{pbdPROF/inst/extdata/} in the package source).
  
  The example datasets are profiled in 2 processors.
}
\keyword{data}
