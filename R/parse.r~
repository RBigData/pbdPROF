### Internal parsing methods

parse.prof <- function(x, ...)
{
  UseMethod("parse.prof")
}


# fpmpi
parse.prof.fpmpi <- function(x, ...)
{
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
}



# mpiP
parse.prof.mpip <- function(x, ...)
{
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
  
  
  for (j in 1:cloop)
    first_stat[j,] <- as.double(copyl[[j]])
  
  #second_part
  id2.start <- grep("@--- Aggregate Time", x)
  id2.end <- grep("@--- Aggregate Sent", x)
  x.sub <- x[(id2.start + 2):(id2.end - 2)]
  loop <- (id2.end-1)-(id2.start+2)
  
  #for subsetting the valid #expressions leaving out the spaces
  l2 <- lapply(seq.int(loop), 
    function(i) 
    { 
      tmp <- unlist(strsplit(x.sub[i], split=" "))
      tmp[which(tmp!="")] 
    }
  )
  
  head <- as.list(l2[[1]])
  copyl2 <- l2[2:loop] #separate subset for handling the numeric
  
  cloop2 <- loop-1 #loop limit
  
  second_stat <- matrix(ncol=5,nrow=loop-1,0)
  colnames(second_stat) <- l2[[1]][-1]
  rownames(second_stat) <- c(1:cloop2)
  
  
  
  
  
  
  for (j in 1:cloop2)
    second_stat[j,] <- as.vector(as.numeric(copyl2[[j]][-1])) #could be [-1] if character are removed
  
  second <- as.data.frame(second_stat) #converted to data.frame for handling the plotting #second stat
  
  
  
  id3.start <- grep("@--- Callsite Time statistics", x)
  id3.end <- grep("@--- Callsite Message Sent statistics", x)
  x.sub <- x[(id3.start + 2):(id3.end - 2)]
  loop3<-(id3.end-1)-(id3.start+2)
  
  l3 <- lapply(seq.int(loop), function(i) { tmp <- unlist(strsplit(x.sub[i], split=" ")); tmp[which(tmp!="")] }) #for subsetting the valid #expressions leaving out the spaces
  
  head<-as.list(l3[[1]])
  copyl3<-l3[2:loop] #separate subset for handling the numeric
  
  cloop3<-loop3-1 #loop limit
  
  third_stat<-matrix(ncol=8,nrow=loop-1,0)
  colnames(third_stat)<-l3[[1]][-1]
  rownames(third_stat)<-c(1:cloop3)
  
  
  
  #putting the extracted data into matrix
  
  
  for (j in 1:cloop3){
    if (!identical(copyl3[[j]],character(0))){
      third_stat[j,] <- as.vector(as.numeric(copyl2[[j]][-1]))
    } #could be [-1] if character are removed
  }
  
  third_stat[is.na(third_stat)] <- 0
  third <- as.data.frame(third_stat) #converted to data.frame for handling the plots
  
  
#-------------------------
  
  
  # NTD
  
  # For return
  class(ret) <- "mpip.parse"
  ret
}



# tau
parse.prof.tau <- function(x, ...)
{
  # For return
  ret <- list()

  # NTD

  # For return
  class(ret) <- "tau.parse"
  ret
}


