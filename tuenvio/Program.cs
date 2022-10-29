using System.Diagnostics;
/* 

tenemos que generar todas las variaciones, permutaciones que cumplan las siguiente condiciones:

- empiezan y acaban con 0.
- no poseen dos ceros seguidos.
- posee sin repetir todos los números de 1 a n.

Por ejemplo para n = 1,
sería solamente 0 1 0

n = 2
0 1 2 0
0 1 0 2 0
0 2 0 1 0
0 2 1 0        

para cada número generado debemos comprobar si el peso no se pasa del peso válido en ninguno de 
los viajes, donde el peso es lo que hay entre medio de los ceros, en caso afirmativo, calculamos el
combustible que necesita esta permutacion, para realizarse y si lo actualizamos respecto al menor
combustible que teníamos antes.
*/


public static class tuenvio
{
    public static void Main()
    {

        //pesos
        int[] pesos = new int[] { 20, 15, 10, 13, 17 };
        // Combustible
        int[,] combustible = new int[,]
        {
                { 0, 4, 3, 1, 2},
                { 4, 0, 3, 3, 4},
                { 3, 3, 0, 2, 5},
                { 1, 3, 2, 0, 3},
                { 2, 4, 5, 3, 0},
            };
        Stopwatch a = new Stopwatch();
        a.Start();
        int alvaro = get_combustible(pesos, combustible);
        a.Stop();

        Stopwatch b = new Stopwatch();
        b.Start();
        int marlon = Pruu.tuenvio(pesos, combustible);
        b.Stop();
        Console.WriteLine("Alvaro " + alvaro + " " + a.Elapsed);
        Console.WriteLine("Marlon " + marlon + " " + b.Elapsed);
    }

    public static int get_combustible(int[] pesos, int[,] combustible)
    {
        int cant_ordenes = pesos.Length - 1;
        int min_combustible = -1;
        int peso_maximo = pesos[0];
        /*
        Como recursivamente, obtener las combinaciones que necesito, cual es la condicion de parada, 
        una vez que haya puesto los n números, no me queda más remedio que poner un 0, entonces tengo que llevar
        un bool con los números que tomé y a la misma vez saber cuantos ya puse cuando ponga los  n, pongo el 0 y ya
        tengo.
        */
        backtracking(new List<int>() { 0 }, 0, 1, new bool[cant_ordenes]);
        void backtracking(List<int> actual, int cant_numbers_used, int actual_pos, bool[] taken)
        {
            if (cant_numbers_used == cant_ordenes)
            {
                actual.Add(0);
                // aka tengo la permutacion lista.
                if (is_valid(actual))
                {
                    int comb = used_combustible(actual);
                    if (comb > 0 && min_combustible == -1)
                    {
                        min_combustible = comb;
                    }
                    else
                    {
                        min_combustible = Math.Min(min_combustible, comb);
                    }
                }
                actual.RemoveAt(actual.Count - 1);

            }
            else
            {
                // we have two options, put a number 0 if the number before is a 0.
                if (actual[actual_pos - 1] > 0)
                {
                    actual.Add(0); // put the 0
                    backtracking(actual, cant_numbers_used, actual_pos + 1, taken); // do the backtracking
                    actual.RemoveAt(actual.Count - 1); // remove the 0.
                }
                for (int i = 1; i <= cant_ordenes; i++)
                {
                    if (!taken[i - 1]) // si no lo he cogido
                    {
                        taken[i - 1] = true;
                        actual.Add(i);
                        backtracking(actual, cant_numbers_used + 1, actual_pos + 1, taken);
                        actual.RemoveAt(actual.Count - 1);
                        taken[i - 1] = false;
                    }
                }
            }
        }

        int used_combustible(List<int> permutacion)
        {
            int used_combustible = 0;
            for (int i = 1; i < permutacion.Count; i++)
            {
                used_combustible += combustible[permutacion[i - 1], permutacion[i]];
            }
            return used_combustible;
        }

        bool is_valid(List<int> permutacion)
        {
            /*
            this is checking if the weights are valid, not the permutacion,
            */
            int start = 0; // start of an interval that begins with a 0.
            int actual_weight = 0;
            while (start < permutacion.Count - 1)
            {
                for (int i = start + 1; i < permutacion.Count; i++)
                {
                    if (permutacion[i] == 0)
                    {
                        start = i;
                        actual_weight = 0;
                        break;
                    }
                    else
                    {
                        actual_weight += pesos[permutacion[i]];
                        if (actual_weight > peso_maximo)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        return min_combustible;
    }
}





/*
Solucion de Marlon
*/
class Pruu
{
    public static void viajes(int[] ciudades, int[] peso, int max, int actual, int i, List<int> agregar, List<int[]> lista)
    {
        if (i >= ciudades.Length)
        {
            agregar.Add(0);
            int[] c = new int[agregar.Count];
            for (int a = 0; a < agregar.Count; a++)
            {
                c[a] = agregar[a];
            }
            lista.Add(c);
        }
        else
        {
            if (actual + peso[i + 1] <= max)
            {
                int d = actual;
                actual = actual + peso[i + 1];
                List<int> ag2 = new List<int>();
                for (int a = 0; a < agregar.Count; a++)
                {
                    ag2.Add(agregar[a]);
                }
                ag2.Add(ciudades[i]);
                viajes(ciudades, peso, max, actual, i + 1, ag2, lista);

            }
            agregar.Add(0);
            agregar.Add(ciudades[i]);
            actual = peso[i + 1];
            viajes(ciudades, peso, max, actual, i + 1, agregar, lista);
        }
    }
    public static int costo(int[] combinacion, int[,] matriz)
    {
        int sum = 0;
        for (int i = 0; i < combinacion.Length - 1; i++)
        {
            sum = sum + matriz[combinacion[i], combinacion[i + 1]];
        }
        return sum;
    }
    public static List<int[]> permutaciones(int[] ciudades)
    {
        int[] recorrida = new int[ciudades.Length];
        bool[] visitada = new bool[ciudades.Length];
        List<int[]> lista = new List<int[]>();
        lista = permutaciones(ciudades, recorrida, visitada, 0, lista);
        return lista;
    }
    private static List<int[]> permutaciones(int[] ciudades, int[] recorrida, bool[] visitada, int cuantas, List<int[]> devolver)
    {
        if (cuantas == ciudades.Length)
        {
            int[] agregar = new int[ciudades.Length];
            for (int i = 0; i < ciudades.Length; i++)
            {
                agregar[i] = recorrida[i];
            }
            devolver.Add(agregar);
        }
        else
        {
            for (int k = 0; k < ciudades.Length; k++)
            {
                if (!visitada[k])
                {
                    visitada[k] = true;
                    recorrida[cuantas] = ciudades[k];
                    permutaciones(ciudades, recorrida, visitada, cuantas + 1, devolver);
                    visitada[k] = false;

                }
            }
        }
        return devolver;
    }
    public static int tuenvio(int[] pesos, int[,] combustibles)
    {
        int[] tareas = new int[pesos.Length - 1];
        for (int i = 0; i < tareas.Length; i++)
        {
            tareas[i] = i + 1;
        }
        for (int i = 1; i < pesos.Length; i++)
        {
            if (pesos[i] > pesos[0])
                return -1;
        }
        List<int[]> ciudades = permutaciones(tareas);
        List<int[]> lista = new List<int[]>();
        for (int i = 0; i < ciudades.Count; i++)
        {
            List<int> agregar = new List<int>();
            agregar.Add(0);
            agregar.Add(ciudades[i][0]);
            viajes(ciudades[i], pesos, pesos[0], pesos[1], 1, agregar, lista);
        }
        List<int> valores = new List<int>();
        int c = 0;
        int d = int.MaxValue;
        for (int i = 0; i < lista.Count; i++)
        {
            c = costo(lista[i], combustibles);
            if (c < d)
                d = c;
        }
        return d;
    }
}
