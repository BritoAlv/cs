# Rejection Sampling

The rejection method is a sampling method to deal with hard to directly sampling probability density function. La idea es usar una que si sepamos samplear $g(x)$ tal que existe una constante $c$ tal que:

$$f(x) \leq c g(x)$$

Entonces lo que se hace es generar samples usando $g(x)$, si el valor está pro debajo de $f(x)$ es aceptado, else es descartado.

 