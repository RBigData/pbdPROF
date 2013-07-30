\name{prof-class}
\docType{class}
\alias{prof}
\alias{prof-class}

\title{Class prof}
\description{Class for Profiler Output}

\section{Slots}{
\describe{
\item{\code{profiler}:}{the profiler used; \code{character}}
\item{\code{raw}:}{raw profiler output (read in via \code{readLines()}
  cast as the virtual class \code{rawprof}}
\item{\code{parsed}:}{a dataframe containing the parsed version of
  the \code{raw} slot}
}
}
\section{Details}{
  The \code{prof} class is a simple container for managin profiler output
  via R.  Unless you really think you know what you are doing, you 
  probably shouldn't directly mess around with this class.
}
\seealso{
  \code{\link{read.prof}}
}
\keyword{Classes}

