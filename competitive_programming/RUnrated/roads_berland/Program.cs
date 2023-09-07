public class disjoint_sets
{
    int[] parent;
    int[] size;
    public disjoint_sets(int N)
    {
        parent = new int[N + 1];
        size = new int[N + 1];
        for (int i = 0; i < N + 1; i++)
        {
            make_set(i);
        }
    }

    public List<int> get_parent()
    {
        HashSet<int> set = new HashSet<int>();
        for (int i = 1; i < parent.Length; i++)
        {
            var p = find_set(i);
            if (!set.Contains(p))
            {
                set.Add(p);
            }
        }
        return set.ToList();
    }


    public void make_set(int i)
    {
        parent[i] = i;
        size[i] = 1;
    }

    public int find_set(int a)
    {
        if (parent[a] == a)
        {
            return a;
        }
        return parent[a] = find_set(parent[a]);
    }
    public bool union(int a, int b)
    {
        var l = find_set(a);
        var r = find_set(b);
        if (size[l] < size[r])
        {
            parent[l] = r;
            size[r] += size[l];
            size[l] = 0;
        }
        else
        {
            parent[r] = l;
            size[l] += size[r];
            size[r] = 0;
        }
        return l == r;
    }
}

public class Test
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        List<(int, int)> edges = new List<(int, int)>();
        int t = N;
        while (t > 1)
        {
            var line = Console.ReadLine().Split();
            edges.Add((int.Parse(line[0]), int.Parse(line[1])));
            t--;
        }
        var answer = algorithm(N, edges);
        Console.WriteLine(answer.Count);
        foreach (var edge in answer)
        {
            Console.WriteLine(edge.Item1 + " " + edge.Item2 + " " + edge.Item3 + " " + edge.Item4);
        }
    }
    public static List<(int, int, int, int)> algorithm(int N, List<(int, int)> edges)
    {
        List<(int, int, int, int)> answer = new List<(int, int, int, int)>();
        disjoint_sets DS = new disjoint_sets(N);
        Stack<(int, int)> propina = new Stack<(int, int)>();
        foreach (var edge in edges)
        {
            var prop = DS.union(edge.Item1, edge.Item2);
            if (prop)
            {
                propina.Push(edge);
            }
        }
        var parents = DS.get_parent();
        if (parents.Count == 1)
        {
            return answer;
        }
        for (int i = 0; i < parents.Count - 1; i++)
        {
            var destroy_edge = propina.Pop();
            answer.Add((destroy_edge.Item1, destroy_edge.Item2, parents[i], parents[i + 1]));
        }
        return answer;
    }
}