# what if we get wrong complexity benchmark again?

# operations with strings.
library(stringr)

# tidiverse  %>%
library(tidyverse)

# get current path.
folder_path <- paste(getwd(), "/", sep = "")

# save path
path  <- str_c(folder_path, "Enumerable.csv")
# read data
data <- read.csv(path)

# mutate data in this example cte_memoria.
data <- data %>% mutate(cte_memoria = cte_memoria / input_size)

# write data
write.csv(data, path)
