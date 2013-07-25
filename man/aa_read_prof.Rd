\name{read prof}
\alias{read.prof}
\title{ Reading Profiling Outputs }
\description{
  These function read profiling outputs.
}
\usage{
  read.prof(file.name, lib.type = .PROF.CT$lib.type)
}
\arguments{
  \item{file.name}{a full file name.}
  \item{lib.type}{type of profiling library.}
}
\details{
??
}
\value{
??
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
}
}
\keyword{utility}

