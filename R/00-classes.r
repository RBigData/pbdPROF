### Prof container
setClass(
         "prof", 
          representation(
                         profiler="character",
                         raw="character",
                         parsed="data.frame"
          ),
          
          prototype(
                         profiler="",
                         raw="character",
                         parsed=data.frame()
          )
)

