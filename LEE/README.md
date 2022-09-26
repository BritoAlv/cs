### Problema:

Dado un tablero de $m$ filas y $n$ columnas, y una posición inicial en él $(i,j)$  hallar la menor distancia que existe entre la posición inicial y las casillas del tablero, pudiendo existir obstácuos en el tablero, existen dos casos:

- las casillas vecinas pueden ser diagonales.

- las casillas vecinas no pueden ser diagnonales.

### Algunos lemas y conclusiones relativas al problema:

Un camino que va a partir de la casilla inicial a cualquier otra casilla solamente descendiendo o moviéndose a la derecha es mínimo siempre, asumamos que tenemos un camino que solamente se mueve hacia abajo y hacia la derecha, a partir desde la casilla inicial hasta la casilla destino, si la casilla inicial está en la posición $(i,j)$ y la destino está en la casilla $(a,b)$ entonces como solamente nos movemos abajo y derecha se tiene que: $i \leq a$ y $j \leq b$ , en particular hay que atravesar hay que moverse hacia abajo al menos $(a-i)$ veces y hacia la derecha al menos $(b-j)$ que es la longitud de cualquier camino que se mueve solamente hacia abajo y la derecha. 

Ahora consideremos otro tipo de camino donde en él último paso del camino podemos movernos hacia arriba o a la izquierda, se sigue cumpliendo que es mínimo, pués asumamos que llegamos  a través de $m$ pasos, y desde otro camino se llega en $t < m$ pasos, entonces podemos llegar en $t+1 \leq m$ pasos a la casilla que conecta al destino con la del camino de tipo abajo-derecha, lo anterior es absurdo si $t+1 < m$, por lo que sigue siendo mínimo. 

---

Ahora que cuando están las diagonales permitidas no cualquier camino que solamente se mueva hacia abajo será verdadero, es posible hallar contraejemplos:

En el siguiente ejemplo los valores son puestos a partir de $0$, actualizando los valores de cada casilla en la misma fila, y cuando llega al final de la fila se mueve para la siguiente columna, 

| 0   | 1   | 2   | 3   | 4   |
|:---:| --- | --- | --- | --- |
| 1   | 2   | X   | x   | 4   |
|     | 2   | 3   | 5   | 5   |
|     |     |     |     |     |

El problema surge porque en el caso de las diagonales es moverse hacia la izquierda / abajo/arriba y a diferencia de en el caso anterior no es posible garantizar el mínimo cuando este comportamiento puede suceder, porque las casillas que están marcadas con números menores se quedan pendientes y pueden generar caminos más mínimos, lo que demostré en el caso anterior es que a pesar de quedar casillas pendientes no importa porque el camino que se generará va a ser mínimo si se garantiza que se mueve abajo y derecha nada más.

### Idea del algoritmo:

Para evitar el problema de las casillas pendientes se utiliza una cola, primero le añadimos la casilla inicial, y revisamos sus vecinos, actualizamos sus valores, y añadimos sus vecinos a la cola, y así ..., de esta forma debido al orden en que son añadidos los elementos a la cola se garantiza que primero en el tablero a todas las casillas alcanzables se les asigna el valor $1$, despues a todas las alcanzables el valor $2$, después a todas el valor $3$, y así hasta que la cola quede vacía y habremos acabado. Esto garantiza el mínimo porque si la menor distancia entre la casilla y la inicial es $k$, en la iteración número $k$ se le debe asignar el valor $k$, porque ella es alcanzable a $k$ pasos.

### Complejidad:

La complejidad de este algoritmo es $O(mn)$, pués para casilla del tablero ejecutamos el proceso de revisarla y actualizar sus vecinos y pasamos por ella una sola vez en el momento en que la sacamos del Queue.

### Benchmark Results:

En los resultados finales se puede ver que multiplicar por $10$ la cantidad de filas / columnas aumenta linearmente el resultado final.

| cant_columns | cant_rows | Mean             | Allocated     |
| ------------ | --------- | ----------------:| -------------:|
| 10           | 10        | 4.193 us         | 2 KB          |
|              |           |                  |               |
| 10           | 100       | 16.780 us        | 8.09 KB       |
| 100          | 10        | 9.154 us         | 5.66 KB       |
|              |           |                  |               |
| 100          | 100       | 692.802 us       | 155.18 KB     |
| 10           | 1000      | 81.845 us        | 47.46 KB      |
| 1000         | 10        | 107.078 us       | 51.77 KB      |
|              |           |                  |               |
| 10           | 10000     | 840.836 us       | 397.44 KB     |
| 10000        | 10        | 884.747 us       | 405.55 KB     |
| 100          | 1000      | 7,285.359 us     | 1535.83 KB    |
| 1000         | 100       | 7,837.892 us     | 1537.19 KB    |
|              |           |                  |               |
| 100          | 10000     | 71,503.114 us    | 15401.05 KB   |
| 10000        | 100       | 75,238.012 us    | 15421.74 KB   |
| 1000         | 1000      | 76,109.449 us    | 15470.8 KB    |
|              |           |                  |               |
| 1000         | 10000     | 727,288.522 us   | 154523.72 KB  |
| 10000        | 1000      | 816,293.558 us   | 154559.35 KB  |
|              |           |                  |               |
| 10000        | 10000     | 9,107,012.415 us | 1545718.04 KB |
