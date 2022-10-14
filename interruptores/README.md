## Statement:

We are given an $m*n$ boolean board where $A[m,n] = true$ means that the switch $m$ controls lamp $n$, our task is find a minimal sequence of index of switches taken from $0$ to $m-1$ (maybe) repeated ones so that when we actions the switches from left to right we end up with all lamps on, they are initially off.

Notemos que como lo que interesa es la paridad de los interruptores que encienden una lámpara determinada el problema lo podemos resolver hallando todas las secuencias posibles de interruptores  y probando a ver si funciona. Esto es $O(2^n)$ podemos mejorar la complejidad del caso promedio introduciendo podas, como por ejemplo:

- Una vez obtenida una secuencia de tamaño $k$ que funcione no revisar más ninguna de tamaño $k$.

- Otra poda es inicialmente si sucede que una lámpara es encendida solamente por un interruptor en caso de serlo, lo cogemos en todos los subconjuntos existentes.

El método que comprueba si una secuencia de switches es válida, tengo dos métodos de hacerlo:

- Con una estructura en la que *contains* *add* *remove* sea constante puedo ir llevando el estado de las lámparas cada vez que acciono un interruptor y más áun puedo guardar el estado de esto, para así no tener que recalcularlo cada vez que haga un cambio no brusco en la secuencia.

- La otra idea es hacerle un *XOR* (*Suma Binaria*) a las filas determinadas por los interruptores de la secuencia en el orden de la secuencia. Que análogamente para ser optimizado la idea es tener la capacidad de no tener que recalcularlo todo cada vez que necesitemos verificar si es válido.

Hay dos formas de hallar los subconjuntos usando un backtracking usual o generar os subconjuntos por tamaño, o sea, primerolos de tamaño $0$, después los de tamaño $1$ y así sucesivamente. Aparentemente no es posible determinar que vía es más óptima porque todo depende del tablero específico con el que se esté lidiando.
