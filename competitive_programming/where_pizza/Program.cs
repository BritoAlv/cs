public class disjoint_sets
{
    int[] parent;
    public int[] size;
    public disjoint_sets(int N)
    {
        parent = new int[N + 1];
        size = new int[N + 1];
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
    public void union(int a, int b)
    {
        var l = find_set(a);
        var r = find_set(b);
        if (l == r)
        {
            return;
        }
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
        
    }
}
public class Test
{
    public static void Main()
    {
        int t = int.Parse(Console.ReadLine());
        
        long[] answer = new long[t];
        while (t > 0)
        {
            int n = int.Parse(Console.ReadLine());
            int[] a = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            int[] b = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            int[] d = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
            answer[answer.Length - t] = algorithm(a, b, d);
            t--;
        }
        foreach (var result in answer)
        {
            Console.WriteLine(result);
        }
    }

    public static long algorithm(int[] a, int[] b, int[] d)
    {
        disjoint_sets DS = new disjoint_sets(a.Length);
        for (int i = 0; i < a.Length; i++)
        {
            DS.union(a[i], b[i]);
        }
        for (int i = 0; i < a.Length; i++)
        {
            if (d[i] > 0)
            {
                DS.size[DS.find_set(d[i])] = 0;
            }   
        }
        long answer = 1; // guaranteed at least one satisfies the problem. 
        foreach (var size in DS.size)
        {
            if (size >= 2)
            {
                answer = (answer * 2) % ((10 * 10 * 10) * (10 * 10 * 10) * 10 * 10 * 10 + 7);
            }
        }
        return answer;
    }
}