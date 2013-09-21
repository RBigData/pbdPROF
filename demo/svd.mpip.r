library(pbdPROF, quiet = TRUE)

fn <- system.file("extdata/svd.mpip", package = "pbdPROF")
da <- read.prof(fn)

print(da)

if (interactive()){
  plot(da)
}
