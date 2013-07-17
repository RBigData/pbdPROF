\name{parse prof}
\alias{parse.prof}
\alias{parse.prof.default}
\alias{parse.prof.fpmpi}
\alias{parse.prof.mpip}
\alias{parse.prof.tau}
\title{ Parsing Profiling Outputs }
\description{
  These function parse profiling outputs.
}
\usage{
\method{parse.prof}{fpmpi}(x, ...)
\method{parse.prof}{mpip}(x, ...)
\method{parse.prof}{tau}(x, ...)
}
\arguments{
  \item{x}{input for parsing (returns of \code{read.prof()}.)}
  \item{...}{extra options to parse.}
}
\details{
??
}
\value{
??
}
\references{
  fpmpi website:
  \url{http://??}

  mpiP website:
  \url{http://??}

  TAU website:
  \url{http://??}

  Programming with Big Data in R Website:
  \url{http://r-pbd.org/}
}
\author{
  Gaurav Sehrawat, Wei-Chen Chen, Drew Schmidt, Pragneshkumar Patel, and
  George Ostrouchov.
}
\examples{
\dontrun{
library(pbdPROF)

fn <- system.file("data/fpmpi.allreduce", package = "pbdPROF")
da <- read.prof(fn, lib.type = "fpmpi")
str(da)
parse.prof(da)
}
}
\keyword{utility}

