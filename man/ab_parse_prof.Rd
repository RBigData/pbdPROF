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
  These functions take in the output of \code{read.prof()} and parse it
  into dataset which is useful and easier to utlize and analyze in R.
}
\value{
  A summarized data matrix.
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
str(da)
(da.out <- parse.prof(da))
}
}
\keyword{utility}

