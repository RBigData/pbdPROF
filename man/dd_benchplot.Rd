\name{benchplot}
\alias{benchplot}
\title{Benchmark Plotter}
\description{
  Simple benchmarks plotter.
}
\usage{
  benchplot(cores, timings, plot.type="speedup", title=NULL)
}
\arguments{
  \item{cores}{Numeric vector containing the cores used in each benchmark.}
  \item{timings}{A dataframe containing the wall-clock timings of each
    benchmark.}
  \item{plot.type}{character; determines what kind of plot to produce.
    options are "runtime", "speedup", or "both".}
  \item{title}{character or NULL; plot title.}
}
\details{
  \code{benchplot()} produces simple benchmark plots. If multiple benchmarks
  are given (i.e., multiple columns are present in the \code{timings} dataframe)
  then the generated plot will automatically plot them against each other,
  separated by color.
}
\examples{
\dontrun{
library(pbdPROF)

x <- c(1, 2, 4, 6, 8, 10, 12, 16)
y <- c(111.424, 80.696, 42.832, 29.468, 24.060, 19.390, 15.938, 11.860)

benchplot(x, y, "both")
}
}
\seealso{
  \code{
    \link{prof-class}
  }
}  
\keyword{utility}

