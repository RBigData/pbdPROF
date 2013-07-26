library(pbdPROF, quiet = TRUE)

fn <- system.file("data/fpmpi.masterslavePI", package = "pbdPROF")
da <- read.prof(fn, lib.type = "fpmpi")

