library(pbdPROF, quiet = TRUE)

fn <- system.file("extdata/fpmpi.allreduce", package = "pbdPROF")
da <- read.prof(fn)

print(da)

if (interactive()){
  plot(da)
}
