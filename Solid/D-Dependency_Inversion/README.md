### Design Patterns: Dependency Inversion

La idea general de este principio e sque los módulos de alto nivel con lógica compleja deben ser fácilmente reusables y no afectados por cambios en los módulos de bajo nivel, que proveen utilidades. Para esto se introduce una abstracción que desacopla los módulos entre sí. Módulos de alto nivel no deben depender de los módulos d ebajo nivel, pero deben depender de abstracciones. Las abstracciones no deben depender de detalles, sino los detalles depender de las abstracciones. Ambos tipos de módulos los de bajo nivel y los de alto nivel deben depender de las abstracciones. O sea se introduce una abstracción por medio de los módulos. Teniendo dos dependencias al final:

- los módulos de alto nivel dependen de la abstracción.

- los módulos de bajo nivel dependen de la abstracción.

La idea es que si tenemos una clase que  depende de otras clases que representan utilidades ( bajo nivel) , realizar una abstracción que capture el concepto de las utilidades, y utilizar las clases de bajo nivel que teníamos como una implementación  específica de la abstracción obtenida por ellos, y la clase de alto nivel tomaría objetos del tipo de la abstracción. Esto permite editar o modifcar ambas lógicas sin tener que modificar la otra e introducir implementaciones de los conceptos reusando la parte que teníamos.

#### Beneficios:

- es posible hacer cambios a la aplicación en solamente una parte, reemplazamos es parte, y todo sigue funcionando, nada depende de instancias. Mientras que los contratos se cumplan todo está ok.

- la aplicación se convierte en varias partes pequeñas, cada una de las cuales hace solamente una cosa, que no tienen dependencias, que son contenidas en sí mismas. Hace posible trabajar en una parte del proyecto, en contra, de tener que trabajar en todo el proyecto. Nuevos cambios serán en un solo lugar.

- garantiza una aplicación totalmente desconectada donde nada depende de el alto nivel o el bajo nivel, todo depende de las interfaces, lo que permite nuevamente *unit-tests* cada cosa por separado.

- evita el *type-coupling* generado por los *news*.
