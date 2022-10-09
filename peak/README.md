Dado un tablero encontrar un número que sea mayor que sus vecinos. Complejidad linear. La idea es una generalización de la versión en una dimensión. El algoritmo es el siguiente dado un tablero rectangular calcular la fila y la columna en el medio, hallar el mayor número que está en esta fila o en esta columna, ( notar que esto divide el tablero en 4 subtableros ) si este mayor número no es un peak, entonces tiene un vecino que es mayor que él, lo que hacemos es buscar en el subtablero donde se encuentra este mayor número un peak (demostrar que hay un peak ahí), recursivamente la complejidad es linear.

| Method        | Tamaño    | Tiempo           | $\frac{Tamaño}{{n}}$ |
|:-------------:| --------- | ----------------:|:--------------------:|
| **twod_peak** | **10000** | **699,529.29**   | **69.952929**        |
| **twod_peak** | **20000** | **1,734,095.02** | **86.704751**        |
| **twod_peak** | **30000** | **3,130,945.11** | **104.364837**       |
| **twod_peak** | **40000** | **4,932,043.97** | **123.301099**       |
| **twod_peak** | **50000** | **6,257,837.01** | **125.156740**       |
| **twod_peak** | **60000** | **7,468,680.37** | **124.478006**       |

Dado un array encontrar un número que sea mayor que sus vecinos. Complejidad Logarítmica. La idea es revisar el elemento del medio, si es un peak we are done revisar en el subtablero donde se encuentra el vecino que es mayor que él (demostrar que hay un peak ahí).

| Method        | Tamaño    | Tiempo    | $\frac{Tamaño}{\log_2{n}}$ |
|:-------------:|:---------:| ---------:| -------------------------- |
| **oned_peak** | **1000**  | **23.43** | **2.351044**               |
| **oned_peak** | **2000**  | **26.64** | **2.429374**               |
| **oned_peak** | **4000**  | **29.99** | **2.5063129**              |
| **oned_peak** | **8000**  | **33.30** | **2.5682981**              |
| **oned_peak** | **16000** | **36.78** | **2.633579**               |
| **oned_peak** | **32000** | **40.02** | **2.6740997**              |
| **oned_peak** | **64000** | **43.28** | **2.7107969**              |
