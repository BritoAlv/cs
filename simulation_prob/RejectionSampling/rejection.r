set.seed(2019)
m <- 1e5
x <- runif(m, -1, 1) # interval that random variable should take
y <- runif(m, 0, 2/pi) # samples from c*g(x)
s <- x[y < (2/pi)*sqrt(1-x*x)] # take the ones such that f(x) <= c*g(x)
length(s)
plot(x,y, pch=".", col="maroon")
points(s,y[y< (2/pi)*sqrt(1-x^2)], pch=".", col="green3")