/*

Solución hecha por nex.

no hacer un bfs para resolver esto, este problema es analogamente a hallar el número chromático de un grafo, el cual es un problema NP,
por lo que tener cuidado sobre como resolverlo.
*/

public class Frecuencias
{
    public static void Main()
    {
        bool[,] test = new bool[,]
                            {
                                {false, true, true, false, false},
                                {true, false, true, false, false},
                                {true, true, false, false, false},
                                {false, false, false, false, true},
                                {false, false, false, true, false},
                            };
        Console.WriteLine(AsignarFrecuencias(test));
    }
    public static int AsignarFrecuencias(bool[,] interferencias)
    {
        return Frec(0, interferencias, 0, 0, new int[interferencias.GetLength(0)], int.MaxValue);
    }
    private static int Frec(int index, bool[,] interferencias, int antenas, int max_frec, int[] frecuencias, int best)
    {
        if (antenas == frecuencias.Length)
        {
            return max_frec; //paro si llego al total de antenas
        }
        if (max_frec >= best)
        {
            return best; //si la max_frec puesta es mayor q best retorno best 
        }
        if (index > interferencias.GetLength(0))
        {
            return int.MaxValue;
        }
        bool[] frec_Usadas = new bool[max_frec + 1];  //solo es necesario hasta la mayor frec usada
        // esto es para rellenar el bool frec_usadas 
        for (int i = 0; i < interferencias.GetLength(0); i++)
        {
            if (interferencias[index, i] && (frecuencias[i] != 0))
            {
                frec_Usadas[frecuencias[i]] = true;
            }
        }
        // lo lleno con las frecuencias que ya fueron usadas
        int sol = int.MaxValue;
        for (int i = 1; i <= max_frec; i++)
        {
            if (frec_Usadas[i]) continue; //si ya use esa frecuencia continuo
            frecuencias[index] = i;  //como es una frecuencia repetida no aumento el maximo
            sol = Math.Min(Frec(index + 1, interferencias, antenas + 1, max_frec, frecuencias, Math.Min(best, sol)), sol);
            frecuencias[index] = 0;
        }
        frecuencias[index] = max_frec + 1; //pongo una nueva frecuenicia que no he usado y aumento el max
        sol = Math.Min(Frec(index + 1, interferencias, antenas + 1, max_frec + 1, frecuencias, Math.Min(best, sol)), sol);
        frecuencias[index] = 0;
        return sol;
    }

}
