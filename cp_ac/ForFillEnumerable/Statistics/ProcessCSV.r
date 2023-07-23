# operations with strings.
library(stringr)

# tidiverse  %>%
library(tidyverse)

# get current path.
folder_path <- paste(getwd(), "/", sep = "")

# get all files that ends in .csv
paths <- list.files(path = folder_path) %>%
    str_subset(pattern = ".csv$") # capture all the files ending in .csv

# concatenate path with name of the file.
paths <- str_c(folder_path, paths)

# auxiliar function to parse numbers.
parse_numbers <- function(number) {
    if (!grepl(".", number, fixed = TRUE)) {
        return(as.double(gsub(",", ".", number)))
    }
    return(as.double(
        gsub(
            ",", "", number
        )
    ))
}

# auxiliar function
# delete , in big numbers, like 1,000.
# substract algorithm_time of setup.
execute_substraction <- function(data, i, index) {
    left <- parse_numbers(data[i, index])
    right <- parse_numbers(data[i - 1, index])
    if (is.na(left)) {
        left <- 0
    }
    if (is.na(right)) {
        right <- 0
    }
    return(left - right)
}

# at this point we take from the data, the parts we need.
# to do this, Determine what to do with the data and apply to all the .csvs


select_columns <- function(data) {
    result <- data %>% dplyr::select(
        c("Method", "N") |
            dplyr::starts_with("Mean") |
            c("Time_Complexity") |
            dplyr::starts_with("Allocated") |
            c("Memory_Complexity")
    )
    return(result)
}

rename_columns <- function(data) {
    result <- data
    colnames(result)[1] <- "Algoritmo"
    colnames(result)[2] <- "input_size"
    colnames(result)[3] <- "Tiempo"
    colnames(result)[4] <- "cte_tiempo"
    colnames(result)[5] <- "Memoria"
    colnames(result)[6] <- "cte_memoria"
    return(result)
}

deletesetuprow <- function(data) {
    result  <- data
    number_rows <- nrow(result)
    for (i in 1:number_rows) {
        if (i %% 2 == 0) {
            result <- rbind(
                result, list(
                    result[i, 1], result[i, 2],
                    execute_substraction(result, i, 3),
                    execute_substraction(result, i, 4),
                    execute_substraction(result, i, 5),
                    execute_substraction(result, i, 6)
                )
            )
        }
    }
    result <- result[-1:-number_rows, ]

    # fix row index
    rownames(result) <- seq(from = 1, to = nrow(result))
    return(result)
}

process_csv <- function(path) {
    # read csv
    # windows use ; as separator
    data <- read.csv(file = path, sep = ";")
    # select only columns we need.
    data <- select_columns(data)

    # rename columns
    data <- rename_columns(data)
    # delete Setup Row.
    data <- deletesetuprow(data)
    # save the csv.
    write.csv(data, path)
}
# apply the function to every csv in the folder.
map(paths, ~ process_csv(.x))