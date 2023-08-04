namespace password_kmp
{
    public class Test
    {
        public static void Main()
        {
            /*
            given a string s find the longest substring t of s such that t is prefix, suffix, and appears inside of s also.
            */

            var S = Console.ReadLine();
            int pi = Prefix_function(S);
            if (pi == -1)
            {
                Console.WriteLine("Just a legend");
            }
            else
            {
                Console.WriteLine(S[..pi]);
            }

        }

        public static int Prefix_function(string s)
        {
            /*
            the sequence pi[i], pi[pi[i]], pi[pi[pi[i]]] loops over the suffixes of the string that ends at i such that are also prefixes in decreasing order. 
            */
            int[] indexes = new int[s.Length + 1];
            int[] pi = new int[s.Length];
            pi[0] = 0;
            for (int i = 1; i < s.Length; i++)
            {
                int k = pi[i - 1];
                while (k > 0)
                {
                    if (s[i] == s[k])
                    {
                        break;
                    }
                    else
                    {
                        k = pi[k - 1];
                    }
                }
                if (s[i] == s[k])
                {
                    pi[i] = k + 1;
                }
                if (i != s.Length - 1)
                {
                    indexes[pi[i]] = i;
                }

            }
            if (s.Length > 2)
            {
                int start = pi[s.Length - 1];
                while (start > 0)
                {
                    if (indexes[start] > 0)
                    {
                        return start;
                    }
                    start = pi[start - 1];
                }
            }
            return -1;
        }
    }
}
