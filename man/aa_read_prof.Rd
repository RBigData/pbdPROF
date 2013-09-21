\name{read prof}
\alias{read.prof}
\title{ Reading Profiling Outputs }
\description{
  Reader for profiler outputs.
}
\usage{
  read.prof(file.name, ...)
}
\arguments{
  \item{file.name}{a full file name.}
  \item{...}{options for \code{readLines}}
}
\details{
  This function reads in profiling outputs from MPI-using R code and
  stores the output in a \code{prof} class object.  The reading is managed
  by the \code{base::readLines()} function.  The user does not need to 
  specify the type of profiler output being used (e.g., whether the profiler
  text is from \pkg{fpmpi}, \pkg{mpiP}, etc.).  

  Additionally, this method automatically parses the output into a condensed,
  manageable dataframe (the \code{parsed} slot of the \code{prof} class).
}
\value{
  A \code{prof} class object.
}
\examples{
\dontrun{
library(pbdPROF)

fn <- system.file("data/allreduce.fpmpi", package = "pbdPROF")
da <- read.prof(fn, lib.type = "fpmpi")

da
}
}
\seealso{
  \code{
    \link{prof-class}
  }
}  
\keyword{utility}

