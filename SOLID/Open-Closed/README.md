# Open-Closed Principle:

- Se dice que un módulo está abierto si se puede extender. Por ejemplo, se deberían poder añadir campos a la estructura de datos que contiene dicho módulo o nuevas funcionalidades a su comportamiento.
- Se dice que un módulo queda cerrado si queda utilizable para otros módulos. Esto implica que dicho módulo goza de una descripción estable y bien definida (implicando a su interfaz pública, en el sentido de protección de la información).

Ejemplo más común: A good alternative to the previous implementation would be follow the recommendations stated by the Open-Closed principle, which means extend the functionality to provide the custom implementation for each account type instead of changing the existing customer, user and platform account class. If each plan has a completely different implementation, it would be better to create separated classes in order to separate the risks and increase the aspects of testability and flexibility. To achieve this objective, it is possible to use interfaces for the User and Plan Account classes.

In this case, instead of one user class we have one for each type of account, sharing the same IUser interface. Additionally, each specific classes initializes a different concrete classes related to the Plan Account once all of them implement the same IPlanAccount interface.

The second code is more clear and easier to test and extend in the future. It explictly express the intention of the code. The excessive use of if and switch-case statement normally indicates that something should be refactored and improved.
