### Internal parsing methods

parse.prof <- function(x, ...){
  UseMethod("parse.prof")
}


### default method (Don't delete/change this.)
parse.prof.default <- function(x, ...){
  stop("Profiler type is not found.")
}


### fpmpi
parse.prof.fpmpi <- function(x, ...){
  # For return
  ret <- list()
  
  # Get informative region
  id.start <- grep("^Details for each MPI", x)
  id.end <- grep("Summary of target processes for point-to-point", x)
  x.sub <- x[(id.start + 5):(id.end - 2)]
  
  # Get functions
  id.func <- grep("^\\t", x.sub, invert = TRUE)
  
  j <- 0
  for(i in id.func){
    j <- j + 1
    ret[[j]] <- list(Routine = NULL,
                     Calls = NULL,
                     Time = NULL,
                     Data.Sent = NULL,
                     SyncTime = NULL)
    
    # Get MPI routine name
    k <- i
    ret[[j]]$Routine <- gsub("^(.*):", "\\1", x.sub[k])
    
    # Get Calls if any
    k <- k + 1
    if(length(grep("^\\tCalls", x.sub[k])) > 0){
      tmp <- strsplit(x.sub[k], ":") 
      tmp <- strsplit(tmp[[1]][2], " ") 
      id.tmp <- which(tmp[[1]] != "")
      ret[[j]]$Calls <- as.integer(tmp[[1]][id.tmp[1]])
    }
    
    # Get Time if any
    k <- k + 1
    if(length(grep("^\\tTime", x.sub[k])) > 0){
      tmp <- strsplit(x.sub[k], ":") 
      tmp <- strsplit(tmp[[1]][2], " ") 
      id.tmp <- which(tmp[[1]] != "")
      ret[[j]]$Time <- as.double(tmp[[1]][id.tmp[1]])
    }
    
    # Get Data Sent if any
    k <- k + 1
    if(length(grep("^\\tData Sent", x.sub[k])) > 0){
      tmp <- strsplit(x.sub[k], ":") 
      tmp <- strsplit(tmp[[1]][2], " ") 
      id.tmp <- which(tmp[[1]] != "")
      ret[[j]]$Data.Sent <- as.integer(tmp[[1]][id.tmp[1]])
    }
    
    # Get SyncTime if any
    k <- k + 1
    if(length(grep("^\\tSyncTime", x.sub[k])) > 0){
      tmp <- strsplit(x.sub[k], ":") 
      tmp <- strsplit(tmp[[1]][2], " ") 
      id.tmp <- which(tmp[[1]] != "")
      ret[[j]]$SyncTime <- as.double(tmp[[1]][id.tmp[1]])
    }
  }
  
  # Cast return as dataframe
  ret <- parsed_fpmpi_2_df(ret)
  
  return( ret )
} # End of parse.prof.fpmpi().


### mpiP
parse.prof.mpip <- function(x, ...){
  #Rscript for profiling mpiP
  
  ret_mpip <- list()

  #lines <- readLines("12-null-null.exe.1.24393.1.mpiP")
  lines <- x 
  #selection the region between ---- and --- putting it in time series space using embed
  regions <- t(t(embed(grep("@---", lines), 2)) + c(-2, 2)) 
  #mapply on set of regions
  ret_mpip <- mapply(function(start,stop) {
    #converting to character without having to worry about spaces and empty lines
    chunk <- paste(lines[start:stop], collapse = "\n")
    #resusing the chunk
    chunk <- gsub("Line Parent_Funct", "Line_Parent_Funct", chunk)
    #making a text file connection to read it as table since it follows pattern
    tc <- textConnection(chunk)
    #reading as table
    df <- read.table(tc, header = T)
    #closing connection
    close(tc)
    #returning the result
    ret_mpip <- df
    return(ret_mpip)
    #arguments of mapply
  }, regions[,2], regions[,1])

  return(ret_mpip)
} # End of parse.prof.mpip().


### tau
parse.prof.tau <- function(x, ...){
  stop("parse.prof for TAU is not implemented yet.")
} # End of parse.prof.tau().

