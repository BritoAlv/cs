num_samples <- 1000
U <- runif(num_samples)
X <- -log(1-U)/2

#plot

hist(X, freq = F, xlab = 'X', main = 'Exponential Random Variable')
curve(dexp(x, rate = 2), 0, 3, lwd = 2, xlab = '', ylab = '', add = T)
