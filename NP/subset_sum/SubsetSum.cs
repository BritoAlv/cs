public static class SubsetSum
{

    // Descripción del problema:
    //
    // Dado un multi-conjunto (que pueden existir elementos repetidos) conteniendo
    // enteros no negativos, y un entero `k`, diga si existe un sub-multi-conjunto
    // del multi-conjunto que sume exactamente `k`.ary_search_1

    public static bool Solve(int[] set, int k)
    {
        return WithList(set, k, 0, new List<int>());
        // return WithMask(set, k, 0, new bool[set.Length]);
        // return WithCounter(set, k, 0, 0);
        //return WithoutExtraParam(set, k, 0);
    }
    public static bool check_sum(IEnumerable<int> currentSet, int k)
    {
        int actual_sum = 0;
        foreach (var number in currentSet)
        {
            actual_sum = actual_sum + number;
            if (actual_sum == k)
            {
                return true;
            }
            if (actual_sum > k)
            {
                return false;
            }
        }
        return false;
    }
    // below methods should be private, are public to benchmark them.
    public static bool WithList(int[] set, int k, int i, List<int> currentSet)
    {


        // Si se llega al final del array
        if (i >= set.Length)
            // Se devuelve `true` si la suma es igual a `k`, de lo contrario
            // `false`
            return check_sum(currentSet, k);
        // Se explora la opción escogiendo el elemento actual
        currentSet.Add(set[i]);
        var s1 = WithList(set, k, i + 1, currentSet);
        // Se quita el elemento actual introducido para probar la opción de no
        // escoger el elemento actual
        currentSet.Remove(set[i]);
        // Esta es una poda, porque si la primera opción es verdadera, no es
        // necesario revisar la segunda opción por lo tanto se retorna `true`
        if (s1)
            return true;
        // Si se llega a este punto es que la opción de escoger el elemento actual
        // no dio `true` (o sea, dio `false`) por lo tanto se reduce a devolver el
        // resultado de la segunda opción sea esta verdadera o no
        return WithList(set, k, i + 1, currentSet);
    }

    public static bool WithMask(int[] set, int k, int i, bool[] mask)
    {
        // Esta implementación elimina la necesidad de utilizar una lista
        // pasando a utilizar una mascara booleana (array de bool) donde
        // el valor de la iésima posición de `mask` dictará si el iésimo
        // elemento de `set` es de los elementos escogidos
        if (i >= set.Length)
            // A diferencia de la solución anterior hay que sumar solo
            // los elementos donde su posición en `mask` sea `true`
            return check_sum(set.Select((s, i) => mask[i] ? s : 0), k);
        mask[i] = true;
        var s1 = WithMask(set, k, i + 1, mask);
        mask[i] = false;
        if (s1)
            return true;
        return WithMask(set, k, i + 1, mask);
    }

    public static bool WithCounter(int[] set, int k, int i, int c)
    {
        // Acá utilizamos un contador pues solo nos interesa saber
        // si existe un subconjunto de `set` que sume `k` por lo
        // que podemos llevar una variable `c` representando la suma
        // hasta el momento
        // La condición `c >= k` es una poda porque si en algun
        // momento c sobrepasa o iguala a k no tiene sentido seguir
        // revisando por esa rama ya que si es igual a k se habrá
        // encontrado la solución y si es mayor que k como los números
        // de `set` son no negativos se mantendrá en lo adelante `c`
        // siendo mayor que `k`
        if (i == set.Length || c >= k)
            return c == k;
        // Se explora la opción de escoger el elemento actual por lo
        // que se suma el elemento actual al contador `c`
        var s1 = WithCounter(set, k, i + 1, c + set[i]);
        if (s1)
            return true;
        // Si la primera opción no resulto se explora la segunda, de
        // no escoger el elemento, por tanto el contador permanece
        // igual
        return WithCounter(set, k, i + 1, c);
    }

    public static bool WithoutExtraParam(int[] set, int k, int i)
    {
        // Esta solución es la misma que la anterior, pero en vez
        // de llevar un contador de `0` a `k` lo que se hace es ir
        // disminuyendo `k`, pues es equivalente y nos ahorramos un
        // parámetro innecesario
        if (i == set.Length || k <= 0)
            return k == 0;
        var s1 = WithoutExtraParam(set, k - set[i], i + 1);
        if (s1)
            return true;
        return WithoutExtraParam(set, k, i + 1);
    }

    // Ejercicios extras:
    // 
    // 1. Devuelva al menos un sub-multi-conjunto que sume `k` si existe, si no devuelva `null`, el método debe devolver `int[]`
    //
    // 2. Devuelva todos los sub-multi-conjuntos que sumen `k`, si no devuelva una lista vacia, el método debe devolver `List<int[]>`
}
