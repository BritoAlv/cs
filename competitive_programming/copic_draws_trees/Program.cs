public class Test
{
    public static void Main()
    {
        // input
        List<int> answer = new List<int>();
        int t = int.Parse(Console.ReadLine());
        while (t > 0)
        {
            int n = int.Parse(Console.ReadLine());
            int counter = n - 1;
            List<(int, int)> edges = new List<(int, int)>(n - 1);
            while (counter > 0)
            {
                var item = Console.ReadLine().Split();
                edges.Add((int.Parse(item[0]), int.Parse(item[1])));
                counter--;
            }
            ds A = new ds(n, edges);
            A.paint();
            answer.Add(A.steps);
            t--;
        }
        foreach (var item in answer)
        {
            Console.WriteLine(item);
        }
    }
}

public class ds
{
    public int steps = 0;
    public int number_Vertices;
    private bool[] colored { get; }
    private Dictionary<int, Queue<(int, int)>> graph_edges = new Dictionary<int, Queue<(int, int)>>();
    public ds(int number_vertices, List<(int, int)> edges)
    {
        /*
        complexity of building the data structure is O(n)
        */
        this.number_Vertices = number_vertices;
        colored = new bool[number_Vertices];
        for (int i = 0; i < edges.Count; i++)
        {
            int priority = i + 1;
            if (!graph_edges.ContainsKey(edges[i].Item1))
            {
                graph_edges[edges[i].Item1] = new Queue<(int, int)>();
            }
            graph_edges[edges[i].Item1].Enqueue((edges[i].Item2, priority));
            if (!graph_edges.ContainsKey(edges[i].Item2))
            {
                graph_edges[edges[i].Item2] = new Queue<(int, int)>();
            }
            graph_edges[edges[i].Item2].Enqueue((edges[i].Item1, priority));
        }
    }
    public bool is_colored(int vertex)
    {
        return colored[vertex - 1];
    }

    public void colour( int vertex)
    {
        colored[vertex - 1] = true;
        return;
    }
    public List<(int, int)> colorear(int vertice, int prioridad)
    {
        /*
        colorear va a devolver una lista con los vértices que no fue posible colorear debido a la prioridad, y los que si los va a colorear.
        */
        colour(vertice);
        List<(int, int)> answer = new List<(int, int)>();
        int len = graph_edges[vertice].Count;
        while (len > 0)
        {
            var actual = graph_edges[vertice].Dequeue();
            if (!is_colored(actual.Item1))
            {
                if (actual.Item2 > prioridad)
                {
                    foreach (var item in colorear(actual.Item1, actual.Item2))
                    {
                        answer.Add(item);
                    }
                }
                else
                {
                    answer.Add(actual);
                    graph_edges[vertice].Enqueue(actual);
                }
            }
            len--;
        }
        return answer;
    }
    public List<(int, int)> reading(List<(int, int)> type2vertex)
    {
        List<(int, int)> remaining = new List<(int, int)>();
        foreach (var vertex in type2vertex)
        {
            foreach (var colored in colorear(vertex.Item1, vertex.Item2))
            {
                remaining.Add(colored);
            }
        }
        List<(int, int)> answer = new List<(int, int)>();
        foreach (var item in remaining)
        {
            if (!is_colored(item.Item1))
            {
                answer.Add(item);
            }
        }
        return answer;
    }
    public void paint()
    {
        List<(int, int)> type2 = new List<(int, int)>() { (1, 0) };
        while (type2.Count > 0)
        {
            steps++;
            type2 = reading(type2);
        }
    }
}