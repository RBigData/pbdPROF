\name{summary print}
\alias{print.fpmpi.parse}
\alias{print.mpip.parse}
\alias{print.tau.parse}
\alias{summary.fpmpi.parse}
\alias{summary.mpip.parse}
\alias{summary.tau.parse}
\title{ Summarize and Print Profiling Outputs }
\description{
  These functions summarize and print profiling outputs.
}
\usage{
\method{print}{fpmpi.parse}(x, digits = max(4, getOption("digits") - 3), ...)
\method{print}{mpip.parse}(x, digits = max(4, getOption("digits") - 3), ...)
\method{print}{tau.parse}(x, digits = max(4, getOption("digits") - 3), ...)
\method{summary}{fpmpi.parse}(object, ...)
\method{summary}{mpip.parse}(object, ...)
\method{summary}{tau.parse}(object, ...)
}
\arguments{
  \item{x}{input for summarizing or printing (returns of \code{parse.prof()}.)}
  \item{digits}{as digits argument in \code{print}.}
  \item{object}{as object argument in \code{summary}.}
  \item{...}{extra options to \code{summary} and \code{print}.}
}
\details{
  These functions take in the output of \code{parse.prof()} and summarize
  or print on screen.
}
\value{
  An output on screen.
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
da.out <- parse.prof(da)
print(da.out)
summary(da.out)
}
}
\keyword{utility}

