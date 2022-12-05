using System.Text;

public static class Examples
{
    public static string GetSaludation(int hour) =>
        hour < 12 ? "Good Morning" : "Good Afternoon";
    

    // Higher Order Functions (takes other function as argument)

    public static int Contar<T>(this IEnumerable<T> source, Func<T, bool> predicate)
    {
        int count = 0;
        foreach (var item in source)
        {
            if (predicate(item))
            {
                count++;
            }
        }
        return count;
    }
    public static StringBuilder AppendWhen(this StringBuilder sb, string value, bool predicate)
     => predicate ? sb.Append(value) : sb;

    public static IEnumerable<int> GreaterThan(int[] arr, int get)
    {
        foreach (int n in arr)
        {
            if (n > get)
            {
                // yield allow us to consume the answer.
                yield return n;
            }
        }
    }

    
}
