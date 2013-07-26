library(pbdPROF, quiet = TRUE)

fn <- system.file("data/fpmpi.svd", package = "pbdPROF")
da <- read.prof(fn, lib.type = "fpmpi")

