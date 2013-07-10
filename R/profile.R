profiletxt <- readLines("fpmpi_profile.txt", n=-1, warn=TRUE)

if(grepl("Command",profiletxt[32])) profiletxt <- profiletxt[-(1:47)] else profiletxt <- profiletxt[-(1:46)] 

len <- min(which(profiletxt=="")) - 1
l <- lapply(seq.int(len), function(i) { tmp <- unlist(strsplit(profiletxt[i], split=" ")); tmp[which(tmp!="")] })

rows <- sapply(l, `[[`, 1)
cols <- rbind("Calls","Time","Data","SyncTime","Routines"	)

x <- c()

for (i in 1:len){
  tmp <- as.numeric(c(l[[i]][3], l[[i]][4],  l[[i]][5]))
  x <- rbind(x,  tmp)
}
sync<-NULL
sync_arr<-matrix(nrow=nrow(x),ncol=1)
#getting the synctime column
i=1
for(j in 1:100){

if(grepl("SyncTime",profiletxt[j])) {

sync <- unlist(strsplit(profiletxt[j], split=" "))
sync= sync[which(sync!="")]
sync_arr[i,]=as.numeric(sync[3])
i=i+1
}}



#binding the synctime 
x <- cbind(x, sync_arr)
x <- cbind(x, rows)
rownames(x) <- NULL

x <- data.frame(x, stringsAsFactors=FALSE)
#rownames(x) <- rows
colnames(x) <- cols

x[is.na(x)] <- 0


print(x)

