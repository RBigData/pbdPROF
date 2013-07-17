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
}
}
\keyword{utility}

