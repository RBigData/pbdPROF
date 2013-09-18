cd# Internals
plot_fpmpi <- function(x, ..., which=1L:4L, show.title=TRUE, label="FPMPI Profiler Output")
{
  df <- x@parsed
  
  df$Routine <- factor(df$Routine)
  df$Calls <- factor(df$Calls)
  
  ### Set up plots
  g1 <- ggplot(df, aes_string(x='Routine', y='Calls')) + 
          geom_bar(stat="identity", aes_string(fill='Routine')) + 
          xlab("Routine") + 
          ylab("Calls") +
          theme(axis.text.x=element_text(angle=20, hjust=1)) +
          theme(legend.position="none")
  
  g2 <- ggplot(df, aes_string(x='Routine', y='Time')) + 
          geom_bar(stat="identity", aes_string(fill='Routine')) + 
          xlab("Routine") +
          ylab("Time (seconds)") + 
          theme(axis.text.x=element_text(angle=20, hjust=1)) +
          theme(legend.position="none")
  
  g3 <- ggplot(df, aes_string(x='Routine', y='Data.Sent')) + 
          geom_bar(stat="identity", aes_string(fill='Routine')) + 
          xlab("Routine") +
          ylab("Data Sent (bytes)") + 
          theme(axis.text.x=element_text(angle=20, hjust=1)) +
          theme(legend.position="none")
  
  g4 <- ggplot(df, aes_string(x='Routine', y='SyncTime')) + 
          geom_bar(stat="identity", aes_string(fill='Routine')) + 
          xlab("Routine") +
          ylab("Sync Time (seconds)") + 
          theme(axis.text.x=element_text(angle=20, hjust=1)) +
          theme(legend.position="none")
  
  ### Set up grid
  grid.newpage()
  
  # Error checking
  if (length(which) > 4 || length(which) < 1 || any(which < 0) || any(which > 4) || length(unique(which)) != length(which)){
    stop("argument 'which' must contain a subset of the numbers 1, 2, 3, 4")
  } 
  # 3-4 plots
  else if (length(which) >= 3){
    grid <- c(2, 2)
    
    if (show.title)
      pushViewport(viewport(layout=grid.layout(3, 2, heights=c(1, 10, 10))))
    else
      pushViewport(viewport(layout=grid.layout(2, 2)))
  } 
  # 2 plots
  else if (length(which) == 2){
    grid <- c(1, 2)
    
    if (show.title)
      pushViewport(viewport(layout=grid.layout(2, 2, heights=c(1, 20))))
    else
      pushViewport(viewport(layout=grid.layout(1, 2)))
  } 
  # 1 plot
  else {
    grid <- c(1, 1)
    
    if (show.title)
      pushViewport(viewport(layout=grid.layout(2, 1, heights=c(1, 20))))
    else
      pushViewport(viewport(layout=grid.layout(1, 1)))
  }
  
  ### Plot
  plots <- paste("g", which, sep="")
  k <- 1L
  
  if (show.title)
    adj <- 1L
  else
    adj <- 0L
  
  for (i in 1L:grid[1L] + adj){
    for (j in 1L:grid[2L]){
      if (k == length(which) && k < prod(grid))
        j <- j:(j+1L)
        
      print(eval(parse(text=plots[k])), vp=viewport(layout.pos.row=i, layout.pos.col=j))
      k <- k + 1L
      
      if (k > length(which))
        break
    }
    
    if (k > length(which))
      break
  }
  
  # Add title
  if (show.title)
    grid.text(label, y=unit(1, "npc") - unit(1, "lines"), gp=gpar(font=1, fontsize=15))
  
  invisible()
}


# plot method
setMethod("plot", signature(x="prof"),
  function(x, ...)
  {
    if (x@profiler == 'fpmpi')
      plot_fpmpi(x, ...)
    else
      stop("Unknown profiler")
  }
)



##mpip plotter
plot_mpi <- function(x, ..., which=1L:4L, show.title=TRUE, label="MPIP Profiler Output")
{

  output<-x@parsed
#grid plot1
#timing stats summary
#first plot
library(ggplot2)
library(gridExtra)
  timestat<-output$value[[3]]
  timevscallname<-data.frame(Call1=timestat$Call,Time=timestat$Time)
  Legends1=factor(timevscallname$Call1)
  a<-qplot(Call1,Time,data=timevscallname,geom="bar",stat="identity",fill=Legends1)+xlab("Call_Name")+ylab("Time(in milliseconds)")+geom_text(data=timevscallname,aes(label=Time,y=Time),size=3)
  ##second plot
  timevscallname_per<-data.frame(Call2=timestat$Call,Time_per=timestat$MPI.)
  Legends2=factor(timevscallname_per$Call2)
  b<-qplot(Call2,Time_per,data=timevscallname_per,geom="bar",stat="identity",fill=Legends2)+xlab("Call_Name")+ylab("Time(in percent)")+geom_text(data=timevscallname_per,aes(label=Time_per,y=Time_per),size=3)

##third part 
sentstat<-output$value[[4]]
sentvscallname<-data.frame(Call3=sentstat$Call,Message_size=sentstat$Total)
Legends3=factor(sentvscallname$Call3)
c<-qplot(Call3,Message_size,data=sentvscallname,geom="bar",stat="identity",fill=Legends3)+xlab("Call_Name")+ylab("Message size(in bytes)")+geom_text(data=sentvscallname,aes(label=Message_size,y=Message_size),size=3)

##fourth part


sentvscallname_per<-data.frame(Call3=sentstat$Call,Message_size_per=sentstat$Sent.)
Legends4=factor(sentvscallname_per$Call3)
d<-qplot(Call3,Message_size_per,data=sentvscallname_per,geom="bar",stat="identity",fill=Legends4)+xlab("Call_Name")+ylab("Message size(in bytes)")+geom_text(data=sentvscallname_per,aes(label=Message_size_per,y=Message_size_per),size=3)

##plot in grid
grid.arrange(a,b,c,d,nrow=2,ncol=2)

}




# autoplot compatibility
autoplot.prof <- function(object, ..., which=1L:4L, show.title=TRUE, label="FPMPI Profiler Output")
{
  plot_fpmpi(x=object, which=which, show.title=show.title, label=label, ...)
}

