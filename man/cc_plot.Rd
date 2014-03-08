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
  \S4method{plot}{prof}(x, ..., which=1L:4L, show.title=TRUE, 
                        plot.type="timing", label, bar.label=FALSE)
  \S3method{autoplot}{prof}(object, ...)
}
\arguments{
  \item{x}{\code{prof} class object}
  \item{object}{\code{prof} class object}
  \item{...}{extra arguments}
  \item{which}{Vector consisting of a subset of the integers 1, 2, 3, 4.
      Determines which plots will be produced.}
  \item{show.title}{Logical; determines whether or not the plot title
      will be shown.}
  \item{plot.type}{for profiling mpiP including "timing", "stats1", "stats2",
      "messages1", and "messages2".}
  \item{label}{The label for the plot title. Should be a character string or
      left missing for the default.}
  \item{bar.label}{logical; indicates whether or not numeric values of 
      heights of barplots should be included should .}
}
\seealso{
  \code{
    \link{prof-class}, 
    \link{read.prof}
  }
}
\keyword{Methods}

