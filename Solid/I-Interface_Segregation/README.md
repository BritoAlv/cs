## Interface Segregation:

Este principio establece que los clientes no deben verse forzados a depender de interfaces que no usan, por ejemplo si una interfaz posee dos funcionalidades, desacoplarla en dos nuevas interfaces, y definir como nueva interfaz la que implementa las dos, 

El ISP se aplica a una interfaz amplia y compleja para escindirla en otras más pequeñas y específicas, de tal forma que cada cliente use solo aquella que necesite, pudiendo así ignorar al resto. A este tipo de interfaces reducidas se les llama "interfaces de rol".​

El ISP fue concebido para mantener a un sistema **desacoplado** respecto a los sistemas de los que depende, y así resulte más fácil *refactorizarlo*, *modificarlo* y *redesplegarlo*.
