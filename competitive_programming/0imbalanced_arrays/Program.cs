namespace imbalanced_arrays
{
    public class Test
    {
        public static void Main()
        {
            int number_cases = int.Parse(Console.ReadLine());
            while (number_cases > 0)
            {
                int n = int.Parse(Console.ReadLine());
                (int, int)[] values = Console.ReadLine()
                                             .Split()
                                             .Select((x, y) => (y, int.Parse(x)))
                                             .OrderByDescending(z => z.Item2)
                                             .ToArray();
                int[] answer = new int[n];
                bool works = false;
                if (values[0].Item2 == 0)
                {
                    works = true;
                    Array.Fill(answer, -n);
                }
                else if (values[n - 1].Item2 == n)
                {
                    works = true;
                    Array.Fill(answer, n);
                }
                else
                {
                    for (int cant_positive = 1; cant_positive < n; cant_positive++)
                    {
                        if (cant_positive < values[cant_positive].Item2)
                        {
                            continue;
                        }
                        if (values[cant_positive-1].Item2 < cant_positive)
                        {
                            continue;
                        }
                        int[] degree = new int[n];
                        HashSet<int> used = new();
                        for (int i = n - 1; i >= cant_positive; i--)
                        {
                            for (int j = 0; j < values[i].Item2; j++)
                            {
                                degree[j]++;
                                if (answer[j] == 0)
                                {
                                    int offset = 0;
                                    if (j == 0)
                                    {
                                        while (used.Contains(-(n - j - offset)))
                                        {
                                            offset++;
                                        }
                                        answer[j] = n - j - offset;
                                        used.Add(n - j - offset);
                                    }
                                    else
                                    {
                                        while (used.Contains(-(answer[j-1]-1 - offset)))
                                        {
                                            offset++;
                                        }
                                        answer[j] = answer[j-1]-1 - offset;
                                        used.Add(answer[j - 1] - 1 - offset);
                                    }
                                }
                            }
                            if (values[i].Item2 == 0)
                            {
                                answer[i] = -n;
                                used.Add(-n);
                            }
                            else
                            {
                                answer[i] = -answer[values[i].Item2 - 1] + 1;
                                used.Add(answer[i]);
                            }
                        }
                        bool finished = true;
                        for (int i = 0; i < cant_positive; i++)
                        {
                            if (answer[i] == 0)
                            {
                                answer[i]++;
                            }
                            if (degree[i] != values[i].Item2 - cant_positive)
                            {
                                finished = false;
                                break;
                            }
                        }
                        if (finished)
                        {
                            works = true;
                            break;
                        }
                    }
                }
                if (works)
                {
                    Console.WriteLine("YES");
                    int[] real_ans = new int[n];
                    for (int i = 0; i < n; i++)
                    {
                        real_ans[values[i].Item1] = answer[i];
                    }
                    for (int i = 0; i < n; i++)
                    {
                        Console.Write(real_ans[i] + " ");
                    }
                    Console.WriteLine();
                }
                else
                {
                    Console.WriteLine("NO");
                }
                number_cases--;
            }
        }
    }
}