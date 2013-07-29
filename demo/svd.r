library(pbdPROF, quiet = TRUE)

fn <- system.file("data/fpmpi.svd", package = "pbdPROF")
da <- read.prof(fn)

da

if (interactive()){
  plot(da)
}
