# Inverse Transform Sampling

Inverse Transform Sampling permite generar números aleatorios que satisfagan cualquier probability distribution. 

La observación es que la variable aleatoria: $$X \stackrel{def}{=} F^{-1}_X(U)$$

Satisface que su probability distribution posee como *cumulative distribution* $F$.

La *cumulative distribution* de una variable aleatoria $X$ es $$F_{X} = P ( X 	\leq x )$$

Asumiendo que tengamos un generador para la variable aleatoria $U$, uniforme en $[0, 1]$, y que podamos invertir la cumulative distribution function podemos obtener $X$.

En el caso en que $X$ es una variable aleatoria discreta tal que: $P( X = x_i) = p_i$. Sería:

- generar $U \approx Unif(0,1)$
- hallar el índice $k$ tal que:
$$\sum^{k-1}_{j = 1} p_j \leq U < \sum^{k}_{j = 1} p_j$$
- devolver $X = x_k$

# Proof:

$$Pr(X \leq x) = Pr ( F^{-1}_X(U) \leq x) = Pr( U \leq F_X(x)) = F_X(x)$$