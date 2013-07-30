# Internals
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


# autoplot compatibility
autoplot.prof <- function(object, ..., which=1L:4L, show.title=TRUE, label="FPMPI Profiler Output")
{
  plot_fpmpi(x=object, which=which, show.title=show.title, label=label, ...)
}

