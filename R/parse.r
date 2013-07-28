### For parsing profile outputs.

parse.prof <- function(x, ...){
  UseMethod("parse.prof")
} # End of parse.prof().


### S3 methods.
parse.prof.default <- function(x, ...){
  ret.class <- class(x)
  stop(paste("Function for class (", ret.class, ") is not found", sep = ""))
  invisible()
} # End of parse.prof.default()


parse.prof.fpmpi.read <- function(x, ...){
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

  # For return
  class(ret) <- "fpmpi.parse"
  ret
} # End of parse.prof.fpmpi.read().


parse.prof.mpip.read <- function(x, ...){
  # For return
  ret <- list()
  
  
  
  #Rscript for profiling mpiP
  #adding the function 

  #x<-readLines("mpip.allreduce",n=-1,warn=TRUE)

  id.start <- grep("@--- MPI Time", x)
    id.end <- grep("@--- Callsites:", x)
    x.sub <- x[(id.start + 2):(id.end - 2)]
  loop<-(id.end-1)-(id.start+2)

    l <- lapply(seq.int(loop), function(i) { tmp <- unlist(strsplit(x.sub[i], split=" ")); tmp[which(tmp!="")] })

  head<-as.list(l[[1]])
  cloop<-loop-1
	
  first_stat<-matrix(ncol=4,nrow=loop-1,0)
  colnames(first_stat)<-c(head)


  for(j in 1:cloop)first_stat[j,]<-as.double(copyl[[j]])







  # NTD

  # For return
  class(ret) <- "mpip.parse"
  ret
} # End of parse.prof.mpip.read().


parse.prof.tau.read <- function(x, ...){
  # For return
  ret <- list()

  # NTD

  # For return
  class(ret) <- "tau.parse"
  ret
} # End of parse.prof.tau.read().


