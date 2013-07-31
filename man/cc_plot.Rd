\name{Plot}
\docType{methods}

\alias{plot-method}
\alias{plot,prof-method}
\alias{plot}

\alias{autoplot.prof}

\title{ Plotting }
\description{
  Plot methods for \code{prof} class objects.
}
\section{Methods}{
\describe{
\item{\code{signature(x = "prof")}}{}
}
}
\usage{
  \S4method{plot}{prof}(x, ...)
  \S3method{autoplot}{prof}(object, ..., which=1L:4L, show.title=TRUE, 
                            label="FPMPI Profiler Output")
}
\arguments{
  \item{x, object}{\code{prof} class object}
  \item{...}{extra arguments}
  \item{which}{Vector consisting of a subset of the integers 1, 2, 3, 4.
  Determines which plots will be produced.}
  \item{show.title}{Logical; determines whether or not the plot title
  will be shown.}
  \item{label}{The label for the plot title.}
}
\seealso{
  \code{
    \link{prof-class}, 
    \link{read.prof}
  }
}
\keyword{Methods}

