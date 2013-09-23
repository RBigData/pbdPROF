# plot method
setMethod("plot", signature(x="prof"),
  function(x, ...)
  {
    if (x@profiler == 'fpmpi')
      plot_fpmpi(x, ...)
    else if (x@profiler == 'mpip')
      plot_mpip(x, ...)
    else if (x@profiler == 'tau')
      plot_tau(x, ...)
    else
      stop("Unknown profiler")
  }
)



# autoplot compatibility
autoplot.prof <- function(object, ...)
{
  if (x@profiler == 'fpmpi')
    plot_fpmpi(x=object, which=which, show.title=show.title, label=label, ...)
  else if (x@profiler == 'mpip')
    plot_mpip(x=object, which=which, show.title=show.title, label=label, ...)
  else if (x@profiler == 'tau')
    plot_tau(x=object, which=which, show.title=show.title, label=label, ...)
  else
    stop("Unknown profiler")
}




### fpmpi
plot_fpmpi <- function(x, ..., which=1L:4L, show.title=TRUE, label="FPMPI Profiler Output")
{
  df <- as.data.frame(x@parsed)
  
  df$Routine <- factor(df$Routine)
  df$Calls <- factor(df$Calls)
  
  # Set up plots
  g1 <- ggplot(df, aes_string(x = 'Routine', y = 'Calls')) + 
          geom_bar(stat = "identity", aes_string(fill = 'Routine')) + 
          xlab("Routine") + 
          ylab("Calls") +
          theme(axis.text.x = element_text(angle = 20, hjust = 1)) +
          theme(legend.position = "none")
  
  g2 <- ggplot(df, aes_string(x = 'Routine', y = 'Time')) + 
          geom_bar(stat = "identity", aes_string(fill = 'Routine')) + 
          xlab("Routine") +
          ylab("Time (seconds)") + 
          theme(axis.text.x = element_text(angle = 20, hjust = 1)) +
          theme(legend.position = "none")
  
  g3 <- ggplot(df, aes_string(x = 'Routine', y = 'Data.Sent')) + 
          geom_bar(stat = "identity", aes_string(fill = 'Routine')) + 
          xlab("Routine") +
          ylab("Data Sent (bytes)") + 
          theme(axis.text.x = element_text(angle = 20, hjust = 1)) +
          theme(legend.position = "none")
  
  g4 <- ggplot(df, aes_string(x = 'Routine', y = 'SyncTime')) + 
          geom_bar(stat = "identity", aes_string(fill = 'Routine')) + 
          xlab("Routine") +
          ylab("Sync Time (seconds)") + 
          theme(axis.text.x = element_text(angle = 20, hjust = 1)) +
          theme(legend.position = "none")
  
  # Plot them
  plots <- list(g1, g2, g3, g4)
  
  grid_plotter(plots=plots, which=which, label=label, show.title=show.title)
  
  invisible()
}



### mpip
plot_mpip <- function(x, ..., which=1L:4L, show.title=TRUE, plot.type="timing", label)
{
  plot.type <- match.arg(tolower(plot.type), c("timing", "data", "statistics", "other", "message", "message2"))
  
  add.legend <- FALSE
  
  output <- x@parsed
  
  # --------------------------------------------------------
  # Timing plots
  # --------------------------------------------------------
  
  if (plot.type == "timing")
  {
    # Time by Rank
    rankvsmpi <- output[[1]]
    rankvsmpi1 <- data.frame(Rank=rankvsmpi$Task, MPI_time=rankvsmpi$MPITime)
    
    rankvsmpi1 <- rankvsmpi1[(rankvsmpi1$Rank != "*"),]
    ranker <- data.frame(Rank = 0:(NROW(rankvsmpi1) - 1),
                         MPI_time = sum(rankvsmpi1$MPI_time))
    rankvsmpi1 <- rbind(ranker, rankvsmpi1)
    Timing <- factor(c(rep("Serial", length(unique(rankvsmpi1$Rank))), rep("MPI", length(unique(rankvsmpi1$Rank)))))
    rankvsmpi1 <- cbind(rankvsmpi1, Timing)
    
    g1 <- qplot(Rank, MPI_time, data=rankvsmpi1, fill=Timing, geom="bar", stat="identity") +
            ylab("Run Time (in millisecond)") + 
            opts(legend.direction="horizontal", 
              plot.margin=unit(c(1, 0, 0, 0), "cm"), 
              legend.position=c(0.5, 1.05))
    
    # Proportional time by rank
    tot <- sapply(unique(rankvsmpi1$Rank), function(i) sum(rankvsmpi1$MPI_time[which(rankvsmpi1$Rank==i)]))
    rankvsmpi2 <- rankvsmpi1
    rankvsmpi2$MPI_time <- rankvsmpi2$MPI_time / tot[rankvsmpi2$Rank]
    
    g2 <- qplot(Rank, MPI_time, data=rankvsmpi2, fill=Timing, geom="bar", stat="identity") +
            ylab("Proportion of Run Time (in millisecond)") + 
            opts(legend.direction="horizontal", 
              plot.margin=unit(c(1, 0, 0, 0), "cm"), 
              legend.position=c(0.5, 1.05))

    
    # Run time by function
    timestat <- output[[3]]
    timevscallname <- data.frame(Call1 = timestat$Call, Time = timestat$Time)
    Legends1 <- factor(timevscallname$Call1)
    
    g3 <- qplot(Call1, Time, data=timevscallname, geom="bar", stat="identity", fill=Legends1) +
            xlab("MPI Function") + 
            ylab("Run Time (in milliseconds)") +
            theme(legend.position="none") +
            geom_text(data=timevscallname, aes(label=Time, y=Time), size=3) + 
            theme(axis.text.x=element_text(angle=-30, vjust=0.5))
    
    # Proportion of run time by function
    timevscallname_per <- data.frame(Call2=timestat$Call, Time_per=timestat$MPI.)
    Legends2 <- factor(timevscallname_per$Call2)
    
    g4 <- qplot(Call2, Time_per, data=timevscallname_per, geom="bar", stat="identity", fill=Legends2) +
            xlab("MPI Function") + 
            ylab("Proportion of Run Time") +
            theme(legend.position="none") +
            geom_text(data=timevscallname_per, aes(label=Time_per, y=Time_per), size=3) + 
            theme(axis.text.x=element_text(angle=-30, vjust=0.5))
    
    if (missing(label))
      label <- "Simple Timing Results"
  }
  
  # --------------------------------------------------------
  # Data transmission plots
  # --------------------------------------------------------
  
###  # Data sent/received by function
###  sentstat <- output[[4]]
###  sentvscallname <- data.frame(Call3=sentstat$Call, Message_size=sentstat$Total)
###  Legends3 <- factor(sentvscallname$Call3)
###  
###  g3 <- qplot(Call3, Message_size, data=sentvscallname, geom="bar", stat="identity", fill=Legends3) +
###       xlab("MPI Function") + 
###       ylab("Message Size (in bytes)") +
###       theme(legend.position="none") +
###       geom_text(data=sentvscallname, aes(label=Message_size, y=Message_size), size=3)
###  
###  # Proportion of data sent/received by function
###  sentvscallname_per <- data.frame(Call3=sentstat$Call, Message_size_per=sentstat$Sent.)
###  Legends4 <- factor(sentvscallname_per$Call3)
###  
###  g4 <- qplot(Call3, Message_size_per, data=sentvscallname_per, geom="bar", stat="identity", fill=Legends4) +
###         xlab("MPI Function") + 
###         ylab("Proportion of Message Size") +
###         theme(legend.position="none") +
###         geom_text(data=sentvscallname_per, aes(label=Message_size_per, y=Message_size_per), size=3)
  
  # --------------------------------------------------------
  # Timing statistics
  # --------------------------------------------------------
  
  else if (plot.type == "statistics" || plot.type == "other")
  {
    timing <- output[[5]]
    timingcount <- data.frame(Call_Name = timing$Name, Rank = timing$Rank, Count = timing$Count)
    timingcount <- timingcount[(timingcount$Rank != "*"),]
    
    timingmin <- data.frame(Call_Name = timing$Name, Rank = timing$Rank, Min_time = timing$Min)
    timingmin <- timingmin[(timingmin$Rank != "*"),]
    
    timingmean <- data.frame(Call_Name = timing$Name, Rank = timing$Rank, Mean_time = timing$Mean)
    timingmean <- timingmean[(timingmean$Rank != "*"),]
    
    timingmax <- data.frame(Call_Name = timing$Name, Rank = timing$Rank, Max_time = timing$Max)
    timingmax <- timingmax[(timingmax$Rank != "*"),]
    
    timingmpi <- data.frame(Call_Name = timing$Name, Rank = timing$Rank, Mpi_per = timing$MPI.)
    timingmpi <- timingmpi[(timingmpi$Rank != "*"),]
    
    if (plot.type == "statistics")
    {
      g1 <- qplot(Rank, Count, data=timingcount, fill=factor(Call_Name), geom="bar", stat="identity") +
                  ylab("Number of Function Calls") +
                  geom_text(data = timingcount, aes(label = Count, y = Count), size = 3) +
                  theme(legend.position = "none") +
                  facet_wrap(facets =~ Call_Name, scales = "free_x")
      
      g2 <- qplot(Rank, Mean_time, data=timingmean, fill=factor(Call_Name), geom="bar", stat="identity") +
                  ylab("Mean Time(in milliseconds)") +
                  geom_text(data=timingmean, aes(label=Mean_time, y=Mean_time), size=3) +
                  theme(legend.position = "none") +
                  facet_wrap(facets =~ Call_Name, scales = "free_x")
      
      g3 <- qplot(Rank, Max_time, data=timingmax, fill=factor(Call_Name), geom="bar", stat="identity") +
                  ylab("Max Time(in milliseconds)") +
                  geom_text(data = timingmax, aes(label=Max_time, y=Max_time), size=3) +
                  theme(legend.position = "none") +
                  facet_wrap(facets =~ Call_Name, scales = "free_x")
      
      g4 <- qplot(Rank, Mpi_per, data=timingmpi, fill=factor(Call_Name), geom="bar", stat="identity") +
                  ylab("MPI (in percent)") +
                  geom_text(data=timingmpi, aes(label=Mpi_per, y=Mpi_per), size=3) +
                  theme(legend.position = "none") +
                  facet_wrap(facets =~ Call_Name, scales = "free_x")
      
      if (missing(label))
        label <- "Timing Statistics by Function"
    }
    
    else if (plot.type == "other")
    {
  #    # (function call) count by rank
  #    g1 <- qplot(Rank, Count, data=timingcount, fill=factor(Call_Name), geom="bar", stat="identity") + 
  #                ylab("Number of Function Calls") +
  #                scale_fill_discrete(name="MPI Function") + 
  #                geom_text(data=timingcount, aes(label=Count, y=Count), size=3)
      
      # Min run time by rank
      g1 <- qplot(Rank, Min_time, data=timingmin, fill=factor(Call_Name), geom="bar", stat="identity") +
              ylab("Min Run Time (in milliseconds)") +
              scale_fill_discrete(name="MPI Function") + 
              geom_text(data=timingmax, aes(label=Max_time, y=Max_time), size=3)
      
      # Mean run time by rank
      g2 <- qplot(Rank, Mean_time, data=timingmean, fill=factor(Call_Name), geom="bar", stat="identity") +
                  ylab("Mean Run Time (in milliseconds)") +
                  scale_fill_discrete(name="MPI Function") + 
                  opts(legend.position = "none") + 
                  geom_text(data = timingmean, aes(label=Mean_time, y=Mean_time), size = 3)
      
      # Max run time by rank
      g3 <- qplot(Rank, Max_time, data=timingmax, fill=factor(Call_Name), geom="bar", stat="identity") +
                  ylab("Max Run Time (in milliseconds)") +
                  scale_fill_discrete(name="MPI Function") + 
                  opts(legend.position = "none") + 
                  geom_text(data=timingmax, aes(label=Max_time, y=Max_time), size=3)
      
      # 
      g4 <- qplot(Rank, Mpi_per, data=timingmpi, fill=factor(Call_Name), geom="bar", stat="identity") + 
                  ylab("MPI (in percent)") +
                  scale_fill_discrete(name="MPI Function") + 
                  opts(legend.position = "none") + 
                  geom_text(data=timingmpi, aes(label=Mpi_per, y=Mpi_per), size = 3)
      
      # Plot a single legend
      tmp <- ggplot_gtable(ggplot_build(g1))
      leg <- which(sapply(tmp$grobs, function(x) x$name) == "guide-box")
      legend <- tmp$grobs[[leg]]
      
      g1 <- g1 + opts(legend.position = "none")
      
    }
    
    add.legend <- TRUE
    
    if (missing(label))
      label <- "Timing Statistics by"
  }
  
  # --------------------------------------------------------
  # Message statistics
  # --------------------------------------------------------
  
  else if (plot.type == "message" || plot.type == "message2")
  {
    message <- output[[6]]
    messagecount <- data.frame(Call_Name=message$Name, Rank=message$Rank, Count=message$Count)
    messagecount <- messagecount[(messagecount$Rank != "*"),]
    
    messagemin <- data.frame(Call_Name = message$Name, Rank = message$Rank, Min = message$Min)
    messagemin <- messagemin[(messagemin$Rank !=  "*"),]
    
    messagemean <- data.frame(Call_Name = message$Name, Rank = message$Rank, Mean = message$Mean)
    messagemean <- messagemean[(messagemean$Rank !=  "*"),]
    
    messagemax <- data.frame(Call_Name = message$Name, Rank = message$Rank, Max = message$Max)
    messagemax <- messagemax[(messagemax$Rank !=  "*"),]
    
    messagesum <- data.frame(Call_Name = message$Name, Rank = message$Rank, Sum = message$Sum)
    messagesum <- messagesum[(messagesum$Rank !=  "*"),]
    
    
    if (plot.type == "message")
    {
#      g1 <- qplot(Rank, Count, data = messagecount, fill = factor(Call_Name), geom = "bar", stat = "identity") + ylab("Message Count") +
#              geom_text(data = messagecount, aes(label = Count, y = Count), size = 3) +
#              theme(legend.position = "none") +
#              facet_wrap(facets =~ Call_Name, scales = "free_x")
      
      # Min message size by rank
      g1 <- qplot(Rank, Min, data = messagemin, fill = factor(Call_Name), geom = "bar", stat = "identity") +
              ylab("Min Message Size (in bytes)") +
              geom_text(data = messagemin, aes(label = Min, y = Min), size = 3) +
              theme(legend.position = "none") +
              facet_wrap(facets =~ Call_Name, scales = "free_x")
      
      # Mean message size by rank
      g2 <- qplot(Rank, Mean, data = messagemean, fill = factor(Call_Name), geom = "bar", stat = "identity") +
              ylab("Mean Message Size (in bytes)") +
              geom_text(data = messagemean, aes(label = Mean, y = Mean), size = 3) +
              theme(legend.position = "none") +
              facet_wrap(facets =~ Call_Name, scales = "free_x")
      
      # Max message size by rank
      g3 <- qplot(Rank, Max, data = messagemax, fill = factor(Call_Name), geom = "bar", stat = "identity") +
              ylab("Max Message Size (in bytes)") +
              geom_text(data = messagemax, aes(label = Max, y = Max), size = 3) +
              theme(legend.position = "none") +
              facet_wrap(facets =~ Call_Name, scales = "free_x")
      
      # Total message size by rank
      g4 <- qplot(Rank, Sum, data = messagesum, fill = factor(Call_Name), geom = "bar", stat = "identity") +
              ylab("Total Message Size (in bytes)") +
              geom_text(data = messagesum, aes(label = Sum, y = Sum), size = 3) +
              theme(legend.position = "none") +
              facet_wrap(facets =~ Call_Name, scales = "free_x")
    }
    
    else if (plot.type == "message2")
    {
      # Min message size by rank
#      g1 <- qplot(Rank, Count, data = messagecount, fill = factor(Call_Name), geom = "bar", stat = "identity") + ylab("Message Count") +
#              geom_text(data = messagecount, aes(label = Count, y = Count), size = 3)
      
      g1 <- qplot(Rank, Min, data = messagemin, fill = factor(Call_Name), geom = "bar", stat = "identity") +
              ylab("Min Message Size (in bytes)") + 
              scale_fill_discrete(name="MPI Function")
      
      # Mean message size by rank
      g2 <- qplot(Rank, Mean, data = messagemean, fill = factor(Call_Name), geom = "bar", stat = "identity") +
              ylab("Message mean size(in bytes)") + 
              scale_fill_discrete(name="MPI Function") + 
              opts(legend.position = "none")
      
      # Max message size by rank
      g3 <- qplot(Rank, Max, data = messagemax, fill = factor(Call_Name), geom = "bar", stat = "identity") +
              ylab("Message max size(in bytes)") + 
              scale_fill_discrete(name="MPI Function") + 
              opts(legend.position = "none")
      
      # Total message size by rank
      g4 <- qplot(Rank, Sum, data = messagesum, fill = factor(Call_Name), geom = "bar", stat = "identity") +
              ylab("Total Message Size (in bytes)") + 
              scale_fill_discrete(name="MPI Function") + 
              opts(legend.position = "none")
      
       # Plot a single legend
      tmp <- ggplot_gtable(ggplot_build(g1))
      leg <- which(sapply(tmp$grobs, function(x) x$name) == "guide-box")
      legend <- tmp$grobs[[leg]]
      
      g1 <- g1 + opts(legend.position = "none")
      
      add.legend <- TRUE
    }
    
    if (missing(label))
      label <- "Message Statistics by Function"
  }
  
  ### produce plots
  plots <- list(g1, g2, g3, g4)
  
  if (add.legend)
    grid_plotter(plots=plots, which=which, label=label, show.title=show.title, legend=legend)
  else
    grid_plotter(plots=plots, which=which, label=label, show.title=show.title)
  
  invisible()
}


plot_tau <- function(x, ..., which = 1L:4L, show.title = TRUE,
                       label = "TAU Profiler Output")
{
  stop("plot() for tau profiled output is not yet implemented.")
}

