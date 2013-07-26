\name{parse prof}
\alias{parse.prof}
\alias{parse.prof.default}
\alias{parse.prof.fpmpi.read}
\alias{parse.prof.mpip.read}
\alias{parse.prof.tau.read}
\title{ Parsing Profiling Outputs }
\description{
  These functions parse profiling outputs.
}
\usage{
\method{parse.prof}{fpmpi.read}(x, ...)
\method{parse.prof}{mpip.read}(x, ...)
\method{parse.prof}{tau.read}(x, ...)
}
\arguments{
  \item{x}{input for parsing (returns of \code{read.prof()}.)}
  \item{...}{extra options to parse.}
}
\details{
  These functions take in the output of \code{read.prof()} and parse it
  into dataset which is useful and easier to utlize and analyze in R.
}
\value{
  A list contains summarized information, and the list has a class
  attribute, 'fpmpi.parse', 'mpip.parse', or 'tau.parse'.
}
\references{
  Programming with Big Data in R Website:
  \url{http://r-pbd.org/}

  fpmpi website:
  \url{http://www.mcs.anl.gov/research/projects/fpmpi/WWW/}

  mpiP website:
  \url{http://mpip.sourceforge.net/}

  TAU website:
  \url{http://www.cs.uoregon.edu/research/tau/home.php}
}
\examples{
\dontrun{
library(pbdPROF)

fn <- system.file("data/fpmpi.allreduce", package = "pbdPROF")
da <- read.prof(fn, lib.type = "fpmpi")
(da.out <- parse.prof(da))
}
}
\keyword{utility}

