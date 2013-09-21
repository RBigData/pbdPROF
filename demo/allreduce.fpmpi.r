library(pbdPROF, quiet = TRUE)

fn <- system.file("extdata/allreduce.fpmpi", package = "pbdPROF")
da <- read.prof(fn)

print(da)

if (interactive()){
  plot(da)
}
