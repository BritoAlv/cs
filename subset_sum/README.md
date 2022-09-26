Descripción del problema:
Dado un multi-conjunto (que pueden existir elementos repetidos) conteniendo
enteros no negativos, y un entero `k`, diga si existe un sub-multi-conjunto
del multi-conjunto que sume exactamente `k` 

Solución: Se han implementado diferentes métodos, el algoritmo es exponencial debido a que necesita revisar todos los subconjuntos, es implementado usando backtracking.

| Method               | size  | Mean            | Allocated   |
|:--------------------:| ----- | ---------------:| -----------:|
|                      |       |                 |             |
| **with_list**        | **5** | **1,993.8 ns**  | **1360 B**  |
| **with_list**        | **6** | **4,364.5 ns**  | **2640 B**  |
| **with_list**        | **7** | **10,084.1 ns** | **5208 B**  |
| **with_list**        | **8** | **21,355.5 ns** | **10328 B** |
| **with_list**        | **9** | **44,502.2 ns** | **20576 B** |
|                      |       |                 |             |
| with_mask            | 5     | 6,317.8 ns      | 6888 B      |
| with_mask            | 6     | 14,593.9 ns     | 13800 B     |
| with_mask            | 7     | 31,720.1 ns     | 27624 B     |
| with_mask            | 8     | 64,424.4 ns     | 55272 B     |
| with_mask            | 9     | 137,856.8 ns    | 110568 B    |
|                      |       |                 |             |
| with_counter         | 5     | 121.0 ns        | -           |
| with_counter         | 6     | 246.5 ns        | -           |
| with_counter         | 7     | 500.7 ns        | -           |
| with_counter         | 8     | 1,014.0 ns      | -           |
| with_counter         | 9     | 2,062.7 ns      | -           |
|                      |       |                 |             |
| without_extra_params | 5     | 120.9 ns        | -           |
| without_extra_params | 6     | 249.2 ns        | -           |
| without_extra_params | 7     | 497.4 ns        | -           |
| without_extra_params | 8     | 1,023.3 ns      | -           |
| without_extra_params | 9     | 2,106.1 ns      | -           |
