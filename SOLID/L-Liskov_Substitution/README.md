## Liskov Substitution:

Este plantea que si S es un subtipo de T entonces  arbitrarios tipos T pueden ser reemplazados  con arbitrarios tipos S sin romper el programa.

- Covarianza: los tipos de retorno de los métodos de  las clases derivadas no debe cambiar en la herencia.

- Contravarianza: los tipos de los argumentos de los métodos de las clases derivadas no debe cambiar en la herencia.

No se debe poner más fuerte las pre-condiciones en las clases padres y no se pueden debilitar más aún las post-condiciones en las clases hijos.

Cada clase que hereda de otra puede usarse como su padre sin necesidad de conocer las diferencias entre ellas.

- Las precondiciones no pueden ser reforzadas por un subtipo.

- Las postcondiciones no pueden ser debilitadas por un subtipo.

- Las invariantes establecidas por el supertipo deben ser mantenidas por los subtipos.

- Se puede ejemplificar una violación de este principio definiendo un subtipo PuntoMutable como descendiente de un supertipo PuntoInmutable. Esto resulta en una violación del principio histórico, porque en la historia de un objeto de tipo PuntoInmutable, el estado es siempre el mismo desde su creación, por lo que no puede incluir la historia de un PuntoMutable. Sin embargo, campos extra añadidos en un subtipo podrían ser modificables sin problema, porque estos campos no son observables desde los métodos del supertipo. Así que se podría, por ejemplo, derivar un tipo Círculo con un centro fijo pero un radio variable a partir de un tipo PuntoInmutable sin violar LSP.

- Funciones que usen objetos de la clase base, deben poder usar objetos de la clase derivada sin necesidad de saberlo.

- The problem concerns which subtyping or inheritance relationship should exist between classes which represent circles and ellipses (or, similarly, squares and rectangles). More generally, the problem illustrates the difficulties which can occur when a base class contains methods which mutate an object in a manner which may invalidate a (stronger) invariant found in a derived class, causing the Liskov substitution principle to be violated.

There are three rules which you have to follow if you wanna have a valid LSP design:

- A derived object method cannot have stronger pre-conditions than a base class has.
- A derived object method cannot have weaker post-conditions than a base class has.
- A derived object method should have inputs and outputs/behaviours which are in line with a base class constraints.

In other words, we should be able to replace objects of base class with a derived ones and still our program should work in the same fashion. It is worth to mention, that Liskov Substitution Principle is a completion of another SOLID rule: Open Close principle.

LSP is not about code, but about promises made about that code, and we don't know the promises you made.
