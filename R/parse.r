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

parse.prof.mpip(x, ...){
#Rscript for profiling mpiP

ret_mpip<-list()
#x<-readLines("mpip.allreduce",n=-1,warn=TRUE)

#loop flags
id.start <- grep("@--- MPI Time", x)
id.end <- grep("@--- Callsites:", x)
x.sub <- x[(id.start + 2):(id.end - 2)]
loop<-(id.end-1)-(id.start+2)

#the objects starting with "c" are actually modified/copied from orginal objects
#filtering the 
l <- lapply(seq.int(loop), function(i) { tmp <- unlist(strsplit(x.sub[i], split=" ")); tmp[which(tmp!="")] })
head<-as.list(l[[1]])
cloop<-loop-1
copyl<-l[2:loop]
first_stat<-matrix(ncol=4,nrow=loop-1,0)
colnames(first_stat)<-c(head)
#changing datatypes for plotting
for (j in 1:cloop)
  first_stat[j,] <- copyl[[j]]



#second_part
#loop flags
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
#"copy" is the modified version of original while the numeric addition is respect to resemblance   to previous codes
head <- as.list(l2[[1]])
copyl2 <- l2[2:loop] #separate subset for handling the numeric
cloop2 <- loop-1 #loop limit

second_stat <- matrix(ncol=5,nrow=loop-1,0)
colnames(second_stat) <- l2[[1]][-1]
rownames(second_stat) <- c(1:cloop2)
#changing datatypes for plotting purposes                    
for (j in 1:cloop2)
  second_stat[j,] <- as.vector(as.numeric(copyl2[[j]][-1])) #could be [-1] if character are removed

second <- as.data.frame(second_stat) #converted to data.frame for handling the plotting #second stat

#return list
ret_mpiP<-list(first=first_stat,second=second_stat)
return(ret_mpip)
}