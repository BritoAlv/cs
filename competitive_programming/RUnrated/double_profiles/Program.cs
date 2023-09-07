﻿namespace double_profiles
{
    public class Test
    {
        public static void Main()
        {
            string[] line = Console.ReadLine().Split();
            int n = int.Parse(line[0]);
            int m = int.Parse(line[1]);
            long[] precomputed_powers1 = new long[n + 1];
            precomputed_powers1[0] = 1;
            long M1 = 1000000009;

            long[] precomputed_powers2 = new long[n + 1];
            precomputed_powers2[0] = 1;
            long M2 = 1000000007;
            for (int i = 1; i < n + 1; i++)
            {
                precomputed_powers1[i] = precomputed_powers1[i - 1] * 2 % M1;
                precomputed_powers2[i] = precomputed_powers2[i - 1] * 5 % M2;
            }

            long[] hash1 = new long[n + 1];
            long[] hash2 = new long[n + 1];
            while (m > 0)
            {
                string[] current = Console.ReadLine().Split();
                int first = int.Parse(current[0]);
                int second = int.Parse(current[1]);
                if (hash1[first] == 0)
                {
                    hash1[first] += precomputed_powers1[first] % M1;
                }
                if (hash2[first] == 0)
                {
                    hash2[first] += precomputed_powers2[first] % M2;
                }
                if (hash1[second] == 0)
                {
                    hash1[second] += precomputed_powers1[second] % M1;
                }
                if (hash2[second] == 0)
                {
                    hash2[second] += precomputed_powers2[second] % M2;
                }

                hash1[first] += precomputed_powers1[second] % M1;
                hash1[second] += precomputed_powers1[first] % M1;
                hash2[first] += precomputed_powers2[second] % M2;
                hash2[second] += precomputed_powers2[first] % M2;
                m--;
            }
            Dictionary<(long, long), long> keyValuePairs1 = new();
            Dictionary<(long, long), long> keyValuePairs2 = new();
            for (int i = 1; i < hash1.Length; i++)
            {
                if (keyValuePairs1.ContainsKey((hash1[i], hash2[i])))
                {
                    keyValuePairs1[(hash1[i], hash2[i])]++;
                }
                else
                {
                    keyValuePairs1[(hash1[i], hash2[i])] = 1;
                }
                if (hash1[i] > 0 && hash2[i] > 0)
                {
                    hash1[i] -= precomputed_powers1[i] % M1;
                    hash2[i] -= precomputed_powers2[i] % M2;
                    if (keyValuePairs1.ContainsKey((hash1[i], hash2[i])))
                    {
                        keyValuePairs1[(hash1[i], hash2[i])]++;
                    }
                    else
                    {
                        keyValuePairs1[(hash1[i], hash2[i])] = 1;
                    }
                }
            }
            long answer = 0;
            foreach (var item in keyValuePairs1.Values)
            {
                answer += (item * (item - 1)) / 2;
            }
            foreach (var item in keyValuePairs2.Values)
            {
                answer += (item * (item - 1)) / 2;
            }
            Console.WriteLine(answer);
        }
    }
}