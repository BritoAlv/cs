# sort_insertion. (ver pdf)

- Entender el algoritmo Insertion Sort.
- Programar el algoritmo en C#.
- La matemática detrás de él, su complejidad .
- Plots para comprobar su complejidad.
- Casos límites respecto a las diferentes estructuras de datos.

(binary_search es usada aquí).

Este algoritmo está explicado a más detalle en el pdf, he aquí una de las tablas usadas para entender este:

La tabla siguiente nos muestra que el algoritmo posee una complejidad cuadrática que es $0.00019*n^2$ el tiempo estimado, y el uso de meoria es prácticamente nulo.

| Method          | Tamaño | Tiempo  | Tiempo / (Tamaño^2)  | Allocated [B] |
| --------------- |:------:| ------- | -------------------- | ------------- |
| binary_search_1 | 1000   | 253     | 0.000253             | -             |
| binary_search_1 | 2000   | 894.5   | 0.000223625          | 1             |
| binary_search_1 | 3000   | 1883.9  | 0.000209322222222222 | 2             |
| binary_search_1 | 4000   | 3268.4  | 0.000204275          | 3             |
| binary_search_1 | 5000   | 4953    | 0.00019812           | 6             |
| binary_search_1 | 6000   | 7006.6  | 0.000194627777777778 | 6             |
| binary_search_1 | 7000   | 9640.7  | 0.000196748979591837 | 13            |
| binary_search_1 | 8000   | 12452.8 | 0.000194575          | 13            |
| binary_search_1 | 9000   | 15826   | 0.000195382716049383 | 26            |
| binary_search_1 | 10000  | 19451.3 | 0.000194513          | 26            |
