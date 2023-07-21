public class Test
{
    public static void Main()
    {
        string test = "alvxalv";
        Console.WriteLine(string_compression(test));
    }

    /*
    z[i] is the length of the greatest string starting at s[i] that is also prefix.
    */

    /*
    z[i] is the greatest common prefix of each suffix and the string.
    */
    static int[] naive_z_function(string s)
    {
        int[] z = new int[s.Length];
        z[0] = 0;
        for (int i = 1; i < s.Length; i++)
        {
            while (i + z[i] < s.Length && s[z[i]] == s[i + z[i]])
            {
                z[i]++;
            }
        }
        return z;
    }
    static int[] z_function(string s)
    {
        int[] z = new int[s.Length];
        int l = 0;
        z[0] = 0;
        for (int i = 1; i < s.Length; i++)
        {
            z[i] = Math.Min(z[i - l], Math.Max(l + z[l] - i, 0));
            while (i + z[i] < s.Length && s[i + z[i]] == s[z[i]])
            {
                z[i]++;
            }
            if (i + z[i] > l + z[l])
            {
                l = i;
            }
        }
        return z;
    }
    static int naive_number_distinct_substring(string s)
    {
        HashSet<string> set = new HashSet<string>();
        for (int i = 0; i < s.Length; i++)
        {
            for (int j = i; j < s.Length; j++)
            {
                set.Add(get_substring(s, i, j));
            }
        }
        return set.Count;
    }

    private static string get_substring(string s, int i, int j)
    {
        var result = "";
        for (int m = i; m <= j; m++)
        {
            result = result + s[m];
        }
        return result;
    }

    static int number_distinct_substring(string s)
    {
        int answer = 1;
        var last_suffix = s.Substring(s.Length - 1);
        for (int i = s.Length - 2; i >= 0; i--)
        {
            var new_suffix = s.Substring(i);
            answer += s.Length - i;
            answer -= altered_z_function(new_suffix, last_suffix); // O(n)
            last_suffix = new_suffix;
        }
        return answer;

        int altered_z_function(string actual_suffix, string past_suffix)
        {
            int[] z = new int[actual_suffix.Length + 1 + past_suffix.Length];
            string s = actual_suffix + "#" + past_suffix;
            int max = 0;
            int l = 0;
            z[0] = 0;
            for (int i = 1; i < s.Length; i++)
            {
                z[i] = Math.Min(z[i - l], Math.Max(l + z[l] - i, 0));
                while (i + z[i] < s.Length && s[i + z[i]] == s[z[i]])
                {
                    z[i]++;
                }
                if (i + z[i] > l + z[l])
                {
                    l = i;
                }
                if (i > actual_suffix.Length)
                {
                    if (z[i] > max)
                    {
                        max = z[i];
                    }
                }
            }
            return max;
        }
    }
    static string string_compression(string s)
    {
        int[] z = new int[s.Length];
        int l = 0;
        z[0] = 0;
        var flag = false;
        for (int i = 1; i < s.Length; i++)
        {
            z[i] = Math.Min(z[i - l], Math.Max(l + z[l] - i, 0));
            while (i + z[i] < s.Length && s[i + z[i]] == s[z[i]])
            {
                z[i]++;
            }
            if (i + z[i] > l + z[l])
            {
                l = i;
            }
        }
        int t = 1;
        while (t*l != s.Length)
        {
            if (t*l > s.Length || z[t*l] != s.Length - t*l)
            {
                return s;
            }
            t++;
        }
        return s.Substring(0, l);
    }
    static List<int> pattern_matching(string pattern, string text)
    {
        List<int> result = new List<int>();
        string to_apply_z = pattern + "$" + text;
        int[] z = new int[to_apply_z.Length];
        int l = 0;
        int r = 0;
        z[0] = 0;
        for (int i = 1; i < to_apply_z.Length; i++)
        {
            if (i < r)
            {
                z[i] = Math.Min(z[i - l], r - i);
            }
            while (i + z[i] < to_apply_z.Length && to_apply_z[z[i]] == to_apply_z[i + z[i]])
            {
                z[i]++;
            }
            if (i + z[i] > r)
            {
                r = i + z[i];
                l = i;
            }
            if (z[i] >= pattern.Length)
            {
                result.Add(i - pattern.Length);
            }
        }
        return result;
    }
}