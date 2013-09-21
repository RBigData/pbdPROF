library(pbdPROF, quiet = TRUE)

fn <- system.file("extdata/masterslavePI.fpmpi", package = "pbdPROF")
da <- read.prof(fn)

print(da)

if (interactive()){
  plot(da)
}
