### Prof container
setClass(
         "prof", 
          representation(
                         type="character",
						 parse="data.frame"
          ),
          
          prototype(
                         type="",
						 parse=data.frame()
          )
)

