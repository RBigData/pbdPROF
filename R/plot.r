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


### fpmpi
plot_fpmpi <- function(x, ..., which = 1L:4L, show.title = TRUE,
                       label = "FPMPI Profiler Output")
{
  df <- as.data.frame(x@parsed)
  
  df$Routine <- factor(df$Routine)
  df$Calls <- factor(df$Calls)
  
  ### Set up plots
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
  
  plots <- list(g1, g2, g3, g4)
  
  grid_plotter(plots=plots, which=which, label=label, show.title=show.title)
  
  invisible()
}



### mpip
plot_mpip <- function(x, ..., which = 1L:4L, show.title = TRUE,
                      label = "MPIP Profiler Output")
{
  output <- x@parsed
  
  ##very first plot
  rankvsmpi <- output[[1]]
  rankvsmpi1 <- data.frame(Rank = rankvsmpi$Task, MPI_time = rankvsmpi$MPITime)
  
  rankvsmpi1 <- rankvsmpi1[(rankvsmpi1$Rank != "*"),]
  ##pseduo trick to add total time with every rank
  ranker <- data.frame(Rank = 0:(NROW(rankvsmpi1) - 1),
                       MPI_time = sum(rankvsmpi1$MPI_time))
  rankvsmpi1 <- rbind(ranker, rankvsmpi1)
  
  plot_first <- qplot(Rank, MPI_time, data = rankvsmpi1, fill = factor(MPI_time),
                      geom = "bar", stat = "identity") +
                ylab("MPI time(in millisecond)") + theme(legend.position = "none")
  
  # Run time by function
  timestat <- output[[3]]
  timevscallname <- data.frame(Call1 = timestat$Call, Time = timestat$Time)
  Legends1 <- factor(timevscallname$Call1)
  
  g1 <- qplot(Call1, Time, data=timevscallname, geom="bar", stat="identity", fill=Legends1) +
         xlab("MPI Function") + 
         ylab("Run Time (in milliseconds)") +
         theme(legend.position="none") +
         geom_text(data=timevscallname, aes(label=Time, y=Time), size=3)
  
  # Proportion of run time by function
  timevscallname_per <- data.frame(Call2=timestat$Call, Time_per=timestat$MPI.)
  Legends2 <- factor(timevscallname_per$Call2)
  
  g2 <- qplot(Call2, Time_per, data=timevscallname_per, geom="bar", stat="identity", fill=Legends2) +
         xlab("MPI Function") + 
         ylab("Proportion of Run Time") +
         theme(legend.position="none") +
         geom_text(data=timevscallname_per, aes(label=Time_per, y=Time_per), size=3)
  
  # Data sent/received by function
  sentstat <- output[[4]]
  sentvscallname <- data.frame(Call3=sentstat$Call, Message_size=sentstat$Total)
  Legends3 <- factor(sentvscallname$Call3)
  
  g3 <- qplot(Call3, Message_size, data=sentvscallname, geom="bar", stat="identity", fill=Legends3) +
       xlab("MPI Function") + 
       ylab("Message Size (in bytes)") +
       theme(legend.position="none") +
       geom_text(data=sentvscallname, aes(label=Message_size, y=Message_size), size=3)
  
  # Proportion of data sent/received by function
  sentvscallname_per <- data.frame(Call3=sentstat$Call, Message_size_per=sentstat$Sent.)
  Legends4 <- factor(sentvscallname_per$Call3)
  
  g4 <- qplot(Call3, Message_size_per, data=sentvscallname_per, geom="bar", stat="identity", fill=Legends4) +
         xlab("MPI Function") + 
         ylab("Proportion of Message Size") +
         theme(legend.position="none") +
         geom_text(data=sentvscallname_per, aes(label=Message_size_per, y=Message_size_per), size=3)
  
  plots <- list(g1, g2, g3, g4)
  
  grid_plotter(plots=plots, which=which, label=label, show.title=show.title)
#  grid.newpage()
#  pushViewport(viewport(layout = grid.layout(2, 2)))
#  print(a, vp=viewport(layout.pos.row=1, layout.pos.col = 1))
#  print(b, vp=viewport(layout.pos.row=1, layout.pos.col = 2))
#  print(c, vp=viewport(layout.pos.row=2, layout.pos.col = 1))
#  print(d, vp=viewport(layout.pos.row=2, layout.pos.col = 2))
#  
  #=========================================================================
  
#  #grid plot2 summary 
#  #with facet introduced.
#  #**Timing stats  (5)
#  timing <- output[[5]]
#  timingcount <- data.frame(Call_Name = timing$Name, Rank = timing$Rank,
#                            Count = timing$Count)
#  timingcount <- timingcount[(timingcount$Rank != "*"),]
#  #remove * from Rank
#  plot1a <- qplot(Rank, Count, data = timingcount, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Count") +
#            geom_text(data = timingcount, aes(label = Count, y = Count),
#                      size = 3) +
#            theme(legend.position = "none") +
#            facet_wrap(facets =~ Call_Name, scales = "free_x")
#  
#  plot1b <- qplot(Rank, Count, data = timingcount, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") + ylab("Count") +
#            geom_text(data = timingcount, aes(label = Count, y = Count), size = 3)
#  
#  ###second part
#  timingmean <- data.frame(Call_Name = timing$Name, Rank = timing$Rank,
#                           Mean_time = timing$Mean)
#  timingmean <- timingmean[(timingmean$Rank != "*"),]
#  #remove * from Rank
#  plot2a <- qplot(Rank, Mean_time, data = timingmean, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Mean Time(in milliseconds)") +
#            geom_text(data = timingmean, aes(label = Mean_time, y = Mean_time),
#                      size = 3) +
#            theme(legend.position = "none") +
#            facet_wrap(facets =~ Call_Name, scales = "free_x")

#  plot2b <- qplot(Rank, Mean_time, data = timingmean, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Mean Time(in milliseconds)") +
#            geom_text(data = timingmean, aes(label = Mean_time, y = Mean_time),
#                      size = 3)
#  
#  ###third part
#  timingmax <- data.frame(Call_Name = timing$Name, Rank = timing$Rank,
#                          Max_time = timing$Max)
#  timingmax <- timingmax[(timingmax$Rank != "*"),]
#  #remove * from Rank
#  plot3a <- qplot(Rank, Max_time, data = timingmax, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Max Time(in milliseconds)") +
#            geom_text(data = timingmax, aes(label = Max_time, y = Max_time),
#                      size = 3) +
#            theme(legend.position = "none") +
#            facet_wrap(facets =~ Call_Name, scales = "free_x")
#  
#  plot3b <- qplot(Rank, Max_time, data = timingmax, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Max Time(in milliseconds)") +
#            geom_text(data = timingmax, aes(label = Max_time, y = Max_time),
#                      size = 3)
#  
#  ###fourth part
#  timingmpi <- data.frame(Call_Name = timing$Name, Rank = timing$Rank,
#                          Mpi_per = timing$MPI.)
#  timingmpi <- timingmpi[(timingmpi$Rank != "*"),]
#  #remove * from Rank
#  plot4a <- qplot(Rank, Mpi_per, data = timingmpi, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("MPI (in percent)") +
#            geom_text(data = timingmpi, aes(label = Mpi_per, y = Mpi_per),
#                      size = 3) +
#            theme(legend.position = "none") +
#            facet_wrap(facets =~ Call_Name, scales = "free_x")
#  
#  plot4b <- qplot(Rank, Mpi_per, data = timingmpi, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") + ylab("MPI (in percent)") +
#            geom_text(data = timingmpi, aes(label = Mpi_per, y = Mpi_per),
#                      size = 3)
#  
#  grid.arrange(plot1a, plot2a, plot3a, plot4a, nrow = 2, ncol = 2)
#  grid.arrange(plot1b, plot2b, plot3b, plot4b, nrow = 2, ncol = 2)
#  #=======================================================================================
#  
#  ##third plot3 summary
#  ##may be using facet
#  message <- output[[6]]
#  messagecount <- data.frame(Call_Name = message$Name, Rank = message$Rank,
#                             Count = message$Count)
#  #remove * from Rank
#  messagecount <- messagecount[(messagecount$Rank != "*"),]
#  
#  plot5a <- qplot(Rank, Count, data = messagecount, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") + ylab("Message Count") +
#            geom_text(data = messagecount, aes(label = Count, y = Count),
#                      size = 3) +
#            theme(legend.position = "none") +
#            facet_wrap(facets =~ Call_Name, scales = "free_x")
#  
#  plot5b <- qplot(Rank, Count, data = messagecount, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") + ylab("Message Count") +
#            geom_text(data = messagecount, aes(label = Count, y = Count),
#                      size = 3)
#  
#  plot5b
#  
#  ##second part
#  messagemean <- data.frame(Call_Name = message$Name, Rank = message$Rank,
#                            Mean = message$Mean)
#  #remove * from Rank
#  messagemean <- messagemean[(messagemean$Rank !=  "*"),]
#  
#  plot6a <- qplot(Rank, Mean, data = messagemean, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Message mean size(in bytes)") +
#            geom_text(data = messagemean, aes(label = Mean, y = Mean), size = 3) +
#            theme(legend.position = "none") +
#            facet_wrap(facets =~ Call_Name, scales = "free_x")
#  
#  plot6b <- qplot(Rank, Mean, data = messagemean, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Message mean size(in bytes)")
#  
#  plot6a
#  plot6b
#  
#  ##third part
#  messagemax <- data.frame(Call_Name = message$Name, Rank = message$Rank,
#                           Max = message$Max)
#  #remove * from Rank
#  messagemax <- messagemax[(messagemax$Rank !=  "*"),]
#  
#  plot7a <- qplot(Rank, Max, data = messagemax, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Message max size(in bytes)") +
#            geom_text(data = messagemax, aes(label = Max, y = Max), size = 3) +
#            theme(legend.position = "none") +
#            facet_wrap(facets =~ Call_Name, scales = "free_x")
#  
#  plot7b <- qplot(Rank, Max, data = messagemax, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Message max size(in bytes)")
#  
#  plot7a
#  plot7b
#  
#  ##fourth part sum
#  ##Might have to include the * rank since the sum is in consideration
#  messagesum <- data.frame(Call_Name = message$Name, Rank = message$Rank,
#                           Sum = message$Sum)
#  #remove * from Rank
#  messagesum <- messagesum[(messagesum$Rank !=  "*"),]
#  
#  plot8a <- qplot(Rank, Sum, data = messagesum, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Message sum size(in bytes)") +
#            geom_text(data = messagesum, aes(label = Sum, y = Sum), size = 3) +
#            theme(legend.position = "none") +
#            facet_wrap(facets =~ Call_Name, scales = "free_x")
#  
#  plot8b <- qplot(Rank, Sum, data = messagesum, fill = factor(Call_Name),
#                  geom = "bar", stat = "identity") +
#            ylab("Message max size(in bytes)")
#  
#  plot8a
#  plot8b
  
  
  
  invisible()
}


plot_tau <- function(x, ..., which = 1L:4L, show.title = TRUE,
                       label = "TAU Profiler Output"){
  stop("plot_tau is not implemented yet.")
}
