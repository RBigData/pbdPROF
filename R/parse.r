### For parsing profile outputs.

parse.prof <- function(x, ...){
  UseMethod("parse.prof")
} # End of parse.prof().


### Internal library.
parse.prof.default <- function(x, ...){
  ret.class <- class(x)
  stop(paste("Function for class (", ret.class, ") is not found", sep = ""))
  invisible()
} # End of parse.prof.default()

parse.prof.fpmpi <- function(x, ...){
  if(grepl("Command", x[32])){
    x <- x[-(1:47)]
  } else{
    x <- x[-(1:46)]
  }

  len <- min(which(x == "")) - 1 
  l <- lapply(seq.int(len),
         function(i){
           tmp <- unlist(strsplit(x[i], split = " "))
           tmp[which(tmp != "")]
         })

  rows <- sapply(l, `[[`, 1)
  cols <- c("Calls", "Time", "Data", "SyncTime", "Routines")

  ret <- c()
  
  for(i in 1:len){
    tmp <- as.numeric(c(l[[i]][3], l[[i]][4],  l[[i]][5]))
    ret <- rbind(ret, tmp)
  }
  sync <- NULL
  sync_arr <- matrix(nrow = nrow(ret), ncol = 1)

  #getting the synctime column
  i <- 1
  for(j in 1:100){
    if(grepl("SyncTime", x[j])){
      sync <- unlist(strsplit(x[j], split = " "))
      sync <- sync[which(sync != "")]
      sync_arr[i,] <- as.numeric(sync[3])
      i <- i + 1
    }
  }

  #binding the synctime 
  ret <- cbind(ret, sync_arr)
  ret <- cbind(ret, rows)
  rownames(ret) <- NULL

  ret <- data.frame(ret, stringsAsFactors = FALSE)
  #rownames(ret) <- rows
  colnames(ret) <- cols

  ret[is.na(ret)] <- 0

  ret
} # End of parse.prof.fpmpi().

parse.prof.mpip <- function(x, ...){

} # End of parse.prof.mpip().

parse.prof.tau <- function(x, ...){

} # End of parse.prof.tau().

