discrete_inverse_sampling <- function (prob)
{
  U <- runif(1)
  if(U <= prob[1])
  {
    return(1)
  }
  for(state in 2: length(prob))
  {
     if(sum(prob[1: state-1]) < U && U <= sum(prob[1: state]))
     {
        return(state)
     }
  }
}

num_samples <- 100000
prob <- c(0.4, 0.2, 0.1, 0.1, 0.2)
names(prob) <- c("0", "2", "3", "7", "10")
samples <- numeric(num_samples)
for(i in seq_len(num_samples))
{
  samples[i] <- discrete_inverse_sampling(prob)
}
sim_prob <- table(samples) / sum(table(samples))
names(sim_prob) <- c("0", "2", "3", "7", "10")
#barplot(prob, main='True Probability Mass Function')
#barplot(sim_prob, main= 'Empirical Probability Mass Function')