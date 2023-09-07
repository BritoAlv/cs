using System;
using System.Collections.Generic;
using System.Linq;
public class disjoint_sets
{
    int[] parent;
    long[] size;
    public disjoint_sets(int N)
    {
        parent = new int[N + 1];
        size = new long[N + 1];
        for (int i = 0; i < N + 1; i++)
        {
            make_set(i);
        }
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
    public long union(int a, int b)
    {
        var l = find_set(a);
        var r = find_set(b);
        var sum = size[l]*size[r];
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
        return sum;
    }
}
public class Test
{
    public static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        List<(int, int, int)> edges = new List<(int, int, int)>();
        int t = N;
        while (t > 1)
        {
            var line = Console.ReadLine().Split();
            edges.Add((int.Parse(line[0]), int.Parse(line[1]), int.Parse(line[2])));
            t--;
        }
        /*         int N = 5;
                var edges = new List<(int, int, int)>()
                {
                    (1, 2 ,1),
                    (2, 3, 2),
                    (4, 2, 5),  
                    (3, 5, 14)
                }; */
        Console.WriteLine(alg(N, edges));
    }
    public static long alg(int N, List<(int, int, int)> graph)
    {
        long sum = 0;
        disjoint_sets DS = new disjoint_sets(N);
        foreach (var edge in graph.OrderBy(x => x.Item3))
        {
            sum += DS.union(edge.Item1, edge.Item2) * edge.Item3;
        }
        return sum;
    }
}
