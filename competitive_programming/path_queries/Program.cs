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
        var sum = size[l] * size[r];
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
        string[] lline = Console.ReadLine().Split();
        int number_vertex = int.Parse(lline[0]);
        int number_queries = int.Parse(lline[1]);
        int t = number_vertex;
        List<((int, int, int), int)> ed = new List<((int, int, int), int)>();
        while (t > 1)
        {
            var line = Console.ReadLine().Split();
            ed.Add(
                (
                    ( int.Parse(line[0]), int.Parse(line[1]), int.Parse(line[2]) ), int.Parse(line[2])
                )
                );
            t--;
        }
        PriorityQueue<(int, int, int), int> edges = new PriorityQueue<(int, int, int), int>(ed);
        PriorityQueue<(int, int), int> queries = new PriorityQueue<(int, int), int>(Console.ReadLine().Split().Select((x, y) => ((y, int.Parse(x)), int.Parse(x))));

        foreach (var answer in algorithm(number_vertex, edges, queries))
        {
            Console.Write(answer + " ");
        }
    }
    private static long[] algorithm(int number_vertex, PriorityQueue<(int, int, int), int> edges, PriorityQueue<(int, int), int> queries)
    {
        long[] answer = new long[queries.Count];
        disjoint_sets DS = new disjoint_sets(number_vertex);
        long old_sum = 0;
        while (queries.Count > 0)
        {
            var queri = queries.Dequeue();
            long sum = 0;
            while (edges.Count > 0 && edges.Peek().Item3 <= queri.Item2)
            {
                var edge = edges.Dequeue();
                sum += DS.union(edge.Item1, edge.Item2);
            }
            answer[queri.Item1] = old_sum + sum;
            while (queries.Count > 0 && queries.Peek().Item2 == queri.Item2)
            {
                var same = queries.Dequeue();
                answer[same.Item1] = old_sum + sum;
            }
            old_sum += sum;
        }
        return answer;
    }
}