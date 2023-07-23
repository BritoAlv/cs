library(dplyr)
library(tidyverse)
library(repr)
options(repr.plot.width = 9, repr.plot.height = 5 ,repr.plot.res = 300)

# it's almost the same process it's just we need to mix the data:

#load data

generate_data <- function(...) {
    values <- list(...)
    values <- map(values, ~ read.csv(file = .x))
    return(bind_rows(values))
}

mixed_data <- generate_data("./SIMD.csv")
mixed_data

x = mixed_data$input_size
mixedplot <- ggplot(
  data = mixed_data, mapping = aes(x = x, y = Tiempo, colour = Algoritmo)) +
  geom_point(size = 2) +
  labs(x = "Tamaño De Entrada", y = "Tiempo Consumido") +
  geom_line() +
  scale_x_continuous(breaks = x, labels = x) +
  theme(axis.text.x = element_text(angle = 90))

mixedplot