\name{prof-class}
\docType{class}
\alias{prof}
\alias{prof-class}

\title{Class prof}
\description{Class for Profiler Output}

\section{Slots}{
\describe{
\item{\code{profiler}:}{the profiler used stored as \code{character} data.}
\item{\code{raw}:}{raw profiler output (read in via \code{readLines()}
  cast as the virtual class \code{rawprof}.}
\item{\code{parsed}:}{a dataframe containing the parsed version of
  the \code{raw} slot.}
}
}
\section{Details}{
  The \code{prof} class is a simple container for managing profiler output
  via R.  

  The slots are \code{profiler}, \code{raw}, and \code{parsed}.  The first, 
  \code{profiler}, is just a character string consisting of the profiler used 
  to generate the output (e.g., "fpmpi", "mpiP", etc.).  
  
  Next, the slot \code{raw} contains the raw output from the profiling library, 
  stored in R as a vector of character data (strings) directly from a 
  \code{readLines()} call, and cast as the virtual class \code{rawprof}.  In 
  reality, we will cast the raw data as a virtual class of the same name as 
  that found in the \code{profiler} slot, and \code{rawprof} is a superclass 
  of each of these classes.  This is for internal S3 dispatch.  You should not 
  mess around with this.  
  
  The final slot, \code{parsed}, contains a condensed version of the
  information from the \code{raw} slot, stored as a dataframe.  This is the
  representation used for plotting.
  
  Unless you really think you know what you are doing, you probably shouldn't 
  directly mess around with the elements of this class.  Instead, simply 
  use the \code{read.prof()} function.
}
\seealso{
  \code{\link{read.prof}}
}
\keyword{Classes}

