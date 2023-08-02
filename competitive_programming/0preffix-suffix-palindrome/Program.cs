namespace preffix_suffix_palindrome
{
    public class Test
    {
        public static void Main()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                string S = Console.ReadLine();
                Console.WriteLine(Alg(S));
                test_cases--;
            }
        }

        public static string Alg(string s)
        {
            int max_length = Get_len_max_suffix_prefix_palindrome(s);
            int max = 0;
            string candidate = "";
            for (int len = 0; len <= max_length; len++)
            {
                if (s.Length - len < len)
                {
                    continue;
                }
                var part1 = Get_max_palindrome_prefix(s[len..(s.Length - len)]);
                var part2 = Get_max_palindrome_sufix(s[len..(s.Length - len)]);

                if (part1 >= part2)
                {
                    if (2 * len + part1 > max)
                    {
                        candidate = s[..(len + part1)];
                        candidate += s[^len..];
                        max = 2 * len + part1;
                    }
                }
                else
                {
                    if (2 * len + part2 > max)
                    {
                        max = 2 * len + part2;
                        candidate = s[..len];
                        candidate += s[^(len + part2)..];
                    }
                }
            }
            return candidate;
        }

        private static int Get_len_max_suffix_prefix_palindrome(string s)
        {
            string S = s + "$";
            for (int i = s.Length - 1; i >= 0; i--)
            {
                S += s[i];
            }
            int[] z = new int[2 * s.Length + 1];
            z[0] = -1;
            int l = 0;
            for (int i = 1; i < S.Length; i++)
            {
                z[i] = Math.Min(z[i - l], Math.Max(0, l + z[l] - i));
                while (i + z[i] < S.Length && S[z[i]] == S[i + z[i]])
                {
                    z[i]++;
                }
                if (i + z[i] > l + z[l])
                {
                    l = i;
                }
            }
            return z[s.Length + 1];
        }

        public static int Get_max_palindrome_prefix(string s)
        {
            if (s.Length <= 1)
            {
                return s.Length;
            }
            string S = s + "$";
            for (int i = s.Length - 1; i >= 0; i--)
            {
                S += s[i];
            }
            return Prefix_function(S);
        }

        public static int Prefix_function(string s)
        {
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
            }
            return pi[^1];
        }

        public static int Get_max_palindrome_sufix(string s)
        {
            if (s.Length <= 1)
            {
                return s.Length;
            }
            string S = "";
            for (int i = s.Length - 1; i >= 0; i--)
            {
                S += s[i];
            }
            S += "$";
            S += s;
            return Prefix_function(S);
        }
    }
}