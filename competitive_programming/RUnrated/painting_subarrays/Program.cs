public class disjoint_sets
{
    int[] parent;
    public disjoint_sets(int N)
    {
        parent = new int[N + 1];
        for (int i = 0; i < N + 1; i++)
        {
            make_set(i);
        }
    }
    public void make_set(int i)
    {
        parent[i] = i;
    }
    public int find_set(int i)
    {
        if (parent[i] == i)
        {
            return i;
        }
        return parent[i] = find_set(parent[i]);
    }
    public void union(int i, int j)
    {
        var a = find_set(i);
        var b = find_set(j);
        if (a > b)
        {
            parent[b] = a;
            return;
        }
        parent[a] = b;
    }
}
public class Test
{
    public static void Main()
    {
        int N = 6;
        List<(int, int, int)> queries = new List<(int, int, int)>(){
            (1,2,2),
            (5,5,1),
            (3,4,2),
            (0,1,3),
        };
        foreach (var position in DSMethod(N, queries))
        {
            Console.Write(position + " ");
        }
        Console.WriteLine();
        foreach (var position in DSMethod(N, queries))
        {
            Console.Write(position + " ");
        }
        Console.WriteLine();
    }
    public static int[] DSMethod(int N, List<(int, int, int)> queries)
    {
        int[] segment = new int[N];
        disjoint_sets DS = new disjoint_sets(N);
        for (int j = queries.Count - 1; j >= 0; j--)
        {
            for (int i = DS.find_set(queries[j].Item1); i <= queries[j].Item2; i = DS.find_set(i))
            {
                segment[i] = queries[j].Item3;
                DS.union(i, i + 1);
            }
        }
        return segment;
    }
    public static int[] NaiveMethod(int N, List<(int, int, int)> queries)
    {
        int[] segment = new int[N];
        for (int j = queries.Count - 1; j >= 0; j--)
        {
            for (int i = queries[j].Item1; i <= queries[j].Item2; i++)
            {
                if (segment[i] == 0)
                {
                    segment[i] = queries[j].Item3;
                }
            }
        }
        return segment;
    }
}