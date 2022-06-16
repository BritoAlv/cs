public class Program{
    public static void Main(){
    int[] tablero1 = { 3, 1, 5, 2, 3, 4, 1, 1, 1, 2, 5, 2, 7, 8, 2, 7, 2, 3, 1, 6 };
    int cantidadDeJugadores1 = 3;
    int[] lanzamientos1 = { 5, 3, 7, 1, 2, 2 };
    int[] posiciones2 = Parchi(tablero1, cantidadDeJugadores1, lanzamientos1);
    int[] posiciones1 = CParchi(tablero1, cantidadDeJugadores1, lanzamientos1);
    foreach (var item in posiciones1)
    {
        Console.Write(item + " ");
    }
    Console.WriteLine("   ");
    foreach (var item in posiciones2)
    {
        Console.Write(item + " ");
    }    
    }

    public static int[] CParchi(int[] tablero, int players, int[] tiradas){
        int[] posjugador = new int[players];
        int c = players - (tiradas.Length % players);
        int[] realtiradas = new int[tiradas.Length+c];

        for (int i = 0; i < realtiradas.Length; i++)
        {
            if(i < tiradas.Length){realtiradas[i] = tiradas[i];}
            else{
                if(tiradas.Length < players)
                realtiradas[i]= tablero[0];
                else if(tiradas.Length > players){
                realtiradas[i] = realtiradas[i-players];
                }               
                }
        }

        
        for (int i = 0; i < realtiradas.Length / players; i++)
        {
            for (int j = 0; j < players; j++)
            {
                for (int k = posjugador[j]; k < tablero.Length; k++)
                {
                    if (tablero[k] == realtiradas[i*players+j])
                    {
                        posjugador[j] = k;
                        break;
                    }
                    else if (k == tablero.Length-1) {
                        posjugador[j] = tablero.Length;
                        return posjugador;
                    }
                }
            }
        }
        return posjugador;
    }
    public static int[] Parchi(int[] tablero, int players, int[] tiradas)
    {   
        int[] posiciones = new int[players]; // posiciones[i] representa donde está el jugador i en el tablero.
        for (int i = 0; i < tiradas.Length; i++)
        {
            posiciones[ i % players] = find_index(posiciones[i % players], tiradas[i]);
            if( posiciones[ i % players] == tablero.Length ){break;}
        }
        return posiciones;
        int find_index(int posplayer, int buscar){
            int answer = tablero.Length;
            for (int i = posplayer; i < tablero.Length; i++)
            {
                if(tablero[i] == buscar){answer = i; break;}
            }
            return answer;
        }
    }
}