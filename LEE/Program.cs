public class Program{
    public static void Main(){
        Console.WriteLine(" Este es el algoritmo de Lee, esta implementación considera como casillas vecinal a las diagonales.");
        Console.WriteLine("0 partimos de aquí");
        Console.WriteLine("-10 esta casilla es prohibida");
        Console.WriteLine("-1 esta casilla es inalcanzable");
        while(true){
        Random rnd = new Random();
        // generate a random boolean map of length 6*8
        bool[,] map = new bool[6,8];
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                map[i,j] = (rnd.NextDouble()>0.5);
            }
        }
        PrintArray.P(map);
        int p,q;
        do {
             p = rnd.Next(6);
             q = rnd.Next(8);
        } 
        while( map[p,q] ); 

        PrintArray.P(lee.Lee(map,p,q));
        Console.ReadKey();
    }}
}
public static class lee {
    public static int[,] Lee(bool[,] mapa, int fila_inicial, int columna_inicial){
        
        int filas = mapa.GetLength(0);
        int columnas = mapa.GetLength(1);
        // codigo por no saber.
        bool[,] realmap = (bool[,])mapa.Clone();
        // acka acaba el código de no saber.

        // creamos el array distancias que representará las distancias.
        int[,] distancias = new int[filas, columnas];
        // paso 1: marcar la casilla por donde empezamos
        distancias[fila_inicial, columna_inicial] = 1;

        /* paso 2: la función work, hace lo siguiente es un procedure y la vez
        devuelve un bool, la idea es recorrer el tablero hasta encontrar alguna
        casilla que satisfaga al menos una de:
        - su valor es 0 y es true en el map (entonces le ponemos -9) y seguimos
        - su valor no es 0 y no nos hayamos parado en ella antes. ( mapa = false  )
        
        Cuando encontramos una casilla que satisface (2) hacemos lo siguiente:
        le ponemos true en el mapa porque no la visitaré de nuevo, y actualizamos el valor
        de sus vecinos,  si tiene algun vecino con valor = 0, esto le pone true al cambio, y sigue
        con el for hasta que este recorra todas las casillas del tablero. este do - while 
        loop va a parar cuando el doble for se ejecute y ninguna casilla sea actualizada. (o sea)
        entre todas las casillas que encontremos dispnibles ninguna tiene un vecino
        actualizable. 

        work contains update neighbours that contain set value that contain valid cell.
        If valid cell this set the bool to true; 
        */  
        bool work(){
            bool hubo_cambio = false;
            for (int j = 0; j < filas; j++)
            {
                for (int l = 0; l < columnas; l++)
                {    
                    
                    if ((distancias[j,l] == 0) && (realmap[j,l])){
                    distancias[j,l] = -9;
                    }
                    else if ((distancias[j,l] > 0) && (!realmap[j,l])) {
                        realmap[j,l] = true;
                        update_neighbours(j,l);
                    }
                        
                }
            }
            return hubo_cambio;
        void update_neighbours(int j, int l){
            int valor = distancias[j,l] + 1;
            set_value(j+1,l);
            set_value(j-1,l);
            set_value(j,l+1);
            set_value(j,l-1);
            // coment to remove diagonals.
            set_value(j+1,l+1);
            set_value(j+1,l-1);
            set_value(j-1,l+1);
            set_value(j-1,l-1);
            // end comment here.
            void set_value(int a, int b){
                if (valid_cell(a,b)){
                    distancias[a,b] = valor;
                }
            }

            bool valid_cell(int a, int b){
                // this first check first if the cell is inside the board, and also check if
                // its value is 0 because if its greater than zero we dont need to change it
                // because by definition and property of the algorithm every number is the
                // minimal distance.  
                if ((a >= 0) && (a < filas) && (b >= 0) && (b < columnas) && (distancias[a,b] == 0) && (!realmap[a,b])){
                    hubo_cambio = true;
                    return true;}
                else{ return false;}
            }
        }    
        }
        bool rr = work();
        while(rr){rr = work();}
    // substract 1 to set cell value according to problem.    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            distancias[i,j] = distancias[i,j] -1;
        }
    }
    return distancias;
    } 


}

public static class PrintArray{
            public static void P<T>(T[,] array)
    {
        for (int i = 0; i < array.GetLength(0); i++)
        {
            for (int j = 0; j <array.GetLength(1); j++)
                Console.Write(array[i, j].ToString().PadLeft(5));

            Console.WriteLine();
        }
    }
}

/*
bool flag = true;
for(int i = 0; (i < 10)&&(flag); i++){
   for(int j = 0; (j < 10); j++){
       if(ksdgagd){flag = false; break;}
   }}
*/
// si A es -1 devuelve 0 else devuelve el valor de A. (condicion)?(codigo a ejec):(ejec en otro caso)
// return (A == -1)?0:A;




