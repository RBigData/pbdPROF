\name{pbdPROF-package}
\alias{pbdPROF}
\alias{pbdPROF-package}
\alias{pbdPROF}
\docType{package}
\title{MPI Profiling Tools}
\description{
  This package contains several libraries for profiling MPI codes, as well as 
  some R tools for parsing, analyzing, and plotting their outputs.
}
\details{
\tabular{ll}{
  Package: \tab pbdPROF\cr
  Type: \tab Package\cr
  License: \tab MPL\cr
  LazyLoad: \tab yes\cr
}
  This package requires an MPI library (OpenMPI, MPICH2, or LAM/MPI).
}
\references{
  Programming with Big Data in R Website:
  \url{http://r-pbd.org/}
}
\author{
  Wei-Chen Chen, Drew Schmidt, Gaurav Sehrawat, Pragneshkumar Patel, and
  George Ostrouchov.
}
\examples{
\dontrun{
demo(allreduce, "pbdPROF")
demo(svd, "pbdPROF")
demo(masterslavePI, "pbdPROF")
}
}
\keyword{Package}
