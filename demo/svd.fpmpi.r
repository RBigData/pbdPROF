library(pbdPROF, quiet = TRUE)

fn <- system.file("extdata/svd.fpmpi", package = "pbdPROF")
da <- read.prof(fn)

print(da)

