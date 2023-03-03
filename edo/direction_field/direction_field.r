library(purrr)
SlopeField <- function(
    FUN,
    xi = -5,
    xs = 5,
    yi = -5,
    ys = 5,
    radius = 0.1,
    grid.by = 0.25) {
    # FUN   - given function ODE i.e:
    # xi,xs - lower and upper bound - x - plot
    # yi,ys - lower and upper bound - y - plot

    # grid points
    seqx <- seq(xi, xs, grid.by)
    seqy <- seq(yi, ys, grid.by)

    # plot
    f <- c(xi, xs)
    h <- c(yi, ys)
    plot(f,
        h,
        main = "Slope field",
        ylab = "Dependet variable",
        xlab = "Independet variable",
        pch = "."
    )

    othery <- seqx
    othery <- map(othery, function (x) x/(x-1) )
   plot(seqx, othery , add = TRUE)

    # arrows

    for (x in seqx) {
        for (y in seqy) {
            ym <- y
            xm <- x

            slope <- unlist(FUN(x, y))

            if (is.na(slope)) {
                cor <- "black"
            } else if (slope > 0) {
                cor <- "blue"
            } else if (slope < 0) {
                cor <- "red"
            } else if (slope == 0) {
                cor <- "green"
            }
            arrows(radius * cos(atan(slope) + pi) + xm,
                radius * sin(atan(slope) + pi) + ym,
                radius * cos(atan(slope)) + xm,
                radius * sin(atan(slope)) + ym,
                length = 0.2 * radius, col = cor
            )
        }
    }
}

ode <- function(t, y) {
    dydt <- (-y * y) / (t * t)
    list(dydt)
}

SlopeField(ode, xi = -3, xs = 3, yi = -5, ys = 5, radius = 0.1, grid.by = 0.25)
