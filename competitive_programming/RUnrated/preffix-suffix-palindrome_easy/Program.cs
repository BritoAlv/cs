using System;

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
            int max = 0;
            bool candidate_is_prefix = false;
            (int, int) candidate = (0, 0); // index, len
            long[] p_pow1 = new long[s.Length + 1];
            long[] p_pow2 = new long[s.Length + 1];
            long M1 = 1000000009;
            long M2 = 1000000007;

            p_pow1[0] = 1;
            p_pow2[0] = 1;
            long[] prefix_hashes1 = new long[s.Length + 1];
            long[] suffix_hashes1 = new long[s.Length + 1];

            long[] prefix_hashes2 = new long[s.Length + 1];
            long[] suffix_hashes2 = new long[s.Length + 1];

            for (int i = 0; i < s.Length; i++)
            {
                prefix_hashes1[i + 1] = (prefix_hashes1[i] + (s[i] - 'a' + 1) * p_pow1[i]) % M1;
                suffix_hashes1[i + 1] = (suffix_hashes1[i] + (s[s.Length - 1 - i] - 'a' + 1) * p_pow1[i]) % M1;
                p_pow1[i + 1] = p_pow1[i] * 31 % M1;

                prefix_hashes2[i + 1] = (prefix_hashes2[i] + (s[i] - 'a' + 1) * p_pow2[i]) % M2;
                suffix_hashes2[i + 1] = (suffix_hashes2[i] + (s[s.Length - 1 - i] - 'a' + 1) * p_pow2[i]) % M2;
                p_pow2[i + 1] = p_pow2[i] * 37 % M2;
            }

            for (int len = s.Length; len >= 1; len--)
            {
                for (int index = 0; index <= s.Length - len; index++)
                {
                    (long, long) hash1 = ((prefix_hashes1[index + len] + M1 - prefix_hashes1[index]) % M1 * p_pow1[s.Length - index] % M1, (prefix_hashes2[index + len] + M2 - prefix_hashes2[index]) % M2 * p_pow2[s.Length - index] % M2);

                    (long, long) hash2 = ((suffix_hashes1[s.Length - index] + M1 - suffix_hashes1[s.Length - index - len]) % M1 * p_pow1[s.Length - (s.Length - index - len)] % M1, (suffix_hashes2[s.Length - index] + M2 - suffix_hashes2[s.Length - index - len]) % M2 * p_pow2[s.Length - (s.Length - index - len)] % M2);
                    if (hash1 == hash2) // is palindrome
                    {
                        var leftlen = index;
                        var rightlen = s.Length - index - len;

                        if (leftlen + len + leftlen <= s.Length)
                        {
                            if (prefix_hashes1[leftlen] == suffix_hashes1[leftlen] && prefix_hashes2[leftlen] == suffix_hashes2[leftlen])
                            {
                                // is valid,
                                if (len + 2 * leftlen > max)
                                {
                                    max = len + 2 * leftlen;
                                    candidate = (index, len);
                                    candidate_is_prefix = true;
                                }
                            }
                        }

                        if (rightlen + len + rightlen <= s.Length)
                        {
                            if (prefix_hashes1[rightlen] == suffix_hashes1[rightlen] && prefix_hashes2[rightlen] == suffix_hashes2[rightlen])
                            {
                                // is valid,
                                if (len + 2 * rightlen > max)
                                {
                                    max = len + 2 * rightlen;
                                    candidate = (index, len);
                                    candidate_is_prefix = false;
                                }
                            }
                        }
                    }
                }
            }
            if (candidate_is_prefix)
            {
                return string.Concat(s.AsSpan(0, candidate.Item1 + candidate.Item2), s.AsSpan(s.Length - candidate.Item1, candidate.Item1));
            }
            else
            {
                return string.Concat(s.AsSpan(0, s.Length - 1 - candidate.Item1 - candidate.Item2 + 1), s.AsSpan(candidate.Item1));
            }
        }
    }
}