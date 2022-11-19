### Notas sobre SOLID:

- Si los tests son muy difíciles de hacer entonces el diseño está mal.

- El proceso sería escribir código que pasen los tests esperados y después refactorizar. Hacer preguntas sobre el código, cómo: 
  
  - es *DRY*?
  
  - tiene una sola responsabilidad?
  
  - todo cambia en él al mismo tiempo?

No hay que ser inteligente para empezar a hacerlo, pero sí saber como una vez que está mal saber arreglarlo, 

En informática, inyección de dependencias (en inglés Dependency Injection, DI) es un patrón de diseño orientado a objetos, en el que se suministran objetos a una clase en lugar de ser la propia clase la que cree dichos objetos. Esos objetos cumplen contratos que necesitan nuestras clases para poder funcionar (de ahí el concepto de dependencia). Nuestras clases no crean los objetos que necesitan, sino que se los suministra otra clase 'contenedora' que inyectará la implementación deseada a nuestro contrato.

Ejemplos de Inyección De Dependencias:

```java
public class Vehiculo {

    private Motor motor = new Motor(); // aka se inyecta.

    /** @return retorna la velocidad del vehículo*/
    public Double enAceleracionDePedal(int presionDePedal) {
        motor.setPresionDePedal(presionDePedal);
        int torque = motor.getTorque();
        Double velocidad = ... //realiza el cálculo
        return velocidad;
    }

}

//se omite la clase Motor ya que no es relevante para este ejemplo
```

```java
public class Vehiculo {

    private Motor motor = null;

    public void setMotor(Motor motor){
        this.motor = motor;
    }

    /** @retorna la velocidad del vehículo*/
    public Double enAceleracionDePedal(int presionDePedal) {
        Double velocidad = null;
        if (null != motor){
            motor.setPresionDePedal(presionDePedal);
            int torque = motor.getTorque();
            velocidad = ... //realiza el cálculo
        }   
        return velocidad; 
    }
}

//se omite la clase Motor ya que no es relevante para este ejemplo

public class VehiculoFactory {

    public Vehiculo construyeVehiculo() {
        Vehiculo vehiculo = new Vehiculo();
        Motor motor = new Motor();
        vehiculo.setMotor(motor);
        return vehiculo;
    }

}
```

La ventaja de hacer esto es que la clase no tiene la responsabilidad de crar el objeto, le pasamos a la clase un objeto que cumple los contratos que necesitamos y listo.

No intentes adivinar donde va a parar el re-factoring, solo sigue las reglas y observa lo que pasa.

Una vez que acabamos el refactoring volvemos al mismo punto, chequeamos si nuestro programa cumple ciertos estandares como hicimos antes. 

Triángulo de Responsabilidad en el Refactoring: Identificamos las dependencias, creamos una versión abstracta de estas y le pasamos a los métodos una implementación de la versión abstracta que es la que necesitabamos, de esta forma solamente tendríamos que cambiar que implementación pasar. Identificamos las responsabilidades, Creamos una clase con esas responsabilidades, y lo ponemos en la clase que va. No adivinar donde vamos a acabar.

Refactorizar, no porque sepamos la abstracción, sino porque la queremos encontrar. Debemos depender de los objetos que son menos propensos a cambiar. Objetos que son propensos a cambiar deben depender de los que menos son propensos a cambiar.

- Test Driven Development.

- DRY.

Once you begin to treat your objects as if they are defined by their behavior rather than by their class, you enter a new realm of expressive design.

Debe haber un solo requerimiento que haga a una clase cambiar, o sea la clase debe tener una sola responsabilidad. 

Sobre el Open-Closed Principle, en el caso de Rectángulo vs Square, la idea es hacer abstracto el método de Área, de forma que cada clase que hereda deba implementarlo a su forma. La idea del Open-CLosed principle es que por ejemplo una vez que la clase sea digamos compilada a un *.dll* no deba ser modificada más, sea capaz de poder extenderse (a través de métodos abstractos por ejemplo),  pero a la vez cerrada para modificaciones.

El principio de *Liskov* lo que plantea es que dos clases que hereden de una misma clase base deben funcionar como objetos de la clase Base sin problemas. No hace falta saber que son de esta clase derivada o de otra, solamente que son de la clase principal. 

Dependency Injection no es Dependency Inversion, pasarle a los métodos un objeto de tipo abstracto, para quealguien se quede a cargo de decidir que implementación pasar. Injection significa que es él el que se encarga de crear las cosas.

```csharp
IGameBoard board = new GameBoard(); // wrong 
IGameBoard board = DI.Get<IGameBoard>(); // fine
```

Dependency Inversion se depende de abstracciones e interfaces, no de cosas concretas. 

- Design is *all* about dependencies
  
  - If you *refer* to something, you depend on it.
  - When the things you depend on change, you must change.

- Resistance is a resource => Listen to what the pain is telling you. Listen to what the code smells are telling you. Embrace the friction. Fix the problem.

- On assessing the design:
  
  - When you get to the refactor stage of red-green-refactor, ask yourself ...
    - Is it DRY?
    - Does it have one responsibility?
    - Does everything change at the same rate?
    - Does it depend on things that change less than it does?
  - When the answer to *all* of these things is 'yes', the design is probably in good shape.

- "Triangle of Responsibility" Refactoring
  
  1. Refactor
  2. Extract - Pull functionality out where necessary
  3. Inject - Inject that new dependency into place from which it was extracted

- What if I don't know where I want this refactoring to take me?
  
  - That's OK. In fact, that's typical.
  - "Refactor, not because you *know* the abstraction, but because you want to *find* it."
  - "You don't have to know where you're going to successfully refactor."
  - When you see someone's code and think it's beautiful and you wonder how they thought of it, they didn't. They evolved it to that point.
