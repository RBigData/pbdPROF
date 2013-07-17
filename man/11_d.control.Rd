\name{PROF Control}
\alias{.PROF.CT}
\alias{.PROF.LIB}
\docType{data}
\title{A set of controls in pbdPROF}
\description{
  This set of controls is used to provide default values in this package.
}
\format{
  Objects contain several parameters for communicators and methods.
}
\details{
  The elements of \code{.PROF.CT} are default values
\tabular{lcl}{
  Elements              \tab Default \tab Usage \cr
  \code{lib.type}       \tab "fpmpi" \tab a profiling library \cr
}

  The elements of \code{.PROF.LIB} list possible incorporated profiling
  libraries. Currently, three libraries are implemented "fpmpi", "mpiP",
  and "TAU".
}
\references{
  Programming with Big Data in R Website:
  \url{http://r-pbd.org/}
}
\author{
  Gaurav Sehrawat, Wei-Chen Chen, Drew Schmidt, Pragneshkumar Patel, and
  George Ostrouchov.
}
\keyword{global variables}
