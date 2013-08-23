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
#x<-readLines("mpip.allreduce",n=-1,warn=TRUE)

#first part
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
first<-as.data.frame(first_stat)

##############################################################################
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

second_stat <- matrix(ncol=6,nrow=loop-1,0)
colnames(second_stat) <- l2[[1]]
#rownames(second_stat) <- c(1:cloop2)
#changing datatypes for plotting purposes                    
for (j in 1:cloop2)
  second_stat[j,] <- copyl2[[j]] #could be [-1] if character are removed

second <- as.data.frame(second_stat) #converted to data.frame for handling the plotting #second stat




#xxxxxxxxxxx----------------------------------------xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx-------------------------------xxxxxxxxxxxxxxxxxxxxxxxx  
#third part of mpiP_profile output
#x<-readLines("mpip.allreduce",n=-1,warn=TRUE)

id3.start <- grep("@--- Aggregate Sent Message Size", x)
id3.end <- grep("@--- Callsite Time statistics", x)
x.sub <- x[(id3.start + 2):(id3.end - 2)]
loop3<-(id3.end-1)-(id3.start+2)

#the objects starting with "c" are actually modified/copied from orginal objects
#filtering the 
l3 <- lapply(seq.int(loop3), function(i) { tmp <- unlist(strsplit(x.sub[i], split=" ")); tmp[which(tmp!="")] })
head<-as.list(l3[[1]])
cloop3<-loop3-1
copyl3<-l3[2:loop3]
third_stat<-matrix(ncol=6,nrow=loop3-1,0)
colnames(third_stat)<-c(head)
#changing datatypes for plotting
for (j in 1:cloop3)
  third_stat[j,] <- copyl3[[j]]
third<-as.data.frame(third_stat)


##########################################################
#fourth stat


id4.start <- grep("@--- Callsite Time statistics", x)
id4.end <- grep("@--- Callsite Message Sent statistics", x)
x.sub <- x[(id4.start + 2):(id4.end - 2)]
loop4<-(id4.end-1)-(id4.start+2)

l4 <- lapply(seq.int(loop4), function(i) { tmp <- unlist(strsplit(x.sub[i], split=" ")); tmp[which(tmp!="")] }) #for subsetting the valid #expressions leaving out the spaces

head<-as.list(l4[[1]])

copyl4<-l4[2:loop4]  #separate subset for handling the numeric


cloop4<-loop4 - 1  #loop limit


adjusted<-loop4+1
while(adjusted >4){
  adjusted=adjusted-3
  l4[[adjusted]]=NULL
}

fourth_stat<-matrix(ncol=9,nrow=length(l4)-1,0)
colnames(fourth_stat)<-l4[[1]]
#rownames(fourth_stat)<-c(1:cloop4-1)
#removing the empty lines


#copying in new object
copyl4<-l4[2:length(l4)]
#putting the extracted data into matrixco
len4=length(l4)-1
for(j in 1:len4) {
  #error1: replacement length zero
  fourth_stat[j,]<-(copyl4[[j]]) } # [-1] if character are removed

fourth_stat[is.na(fourth_stat)]<-0
fourth<-as.data.frame(fourth_stat) #converted to data.frame for handling the plots


##########################################################

id5.start <- grep("@--- Callsite Message Sent statistics", x)
id5.end <- grep("@--- End of Report --------------------------------------------------------", x)
x.sub <- x[(id5.start + 2):(id5.end - 2)]
loop5<-(id5.end-1)-(id5.start+2)

l5 <- lapply(seq.int(loop5), function(i) { tmp <- unlist(strsplit(x.sub[i], split=" ")); tmp[which(tmp!="")] }) #for subsetting the valid #expressions leaving out the spaces

head<-as.list(l5[[1]])

copyl5<-l5[2:loop5]  #separate subset for handling the numeric


cloop5<-loop5 - 1  #loop limit

#removing the empty lines
added<-loop5+1

while(added > 4){
  added=added-3
  l5[[added]]=NULL
}
fifth_stat<-matrix(ncol=8,nrow=length(l5)-1,0)
colnames(fifth_stat)<-l5[[1]]
#rownames(fifth_stat)<-c(1:length(l5)-1)


#copying in new object
copyl5<-l5[2:length(l5)]
#putting the extracted data into matrixco
len=length(l5)-1
for(j in 1:len ){
  #error1: replacement length zero
  fifth_stat[j,]<-(copyl5[[j]]) } # [-1] if character are removed

fifth_stat[is.na(fifth_stat)]<-0
fifth<-as.data.frame(fifth_stat) #converted to data.frame for handling the plots

ret_mpip<-list(first=first,second=second,third=third,fourth=fourth,fifth=fifth)
return(ret_mpip)
}