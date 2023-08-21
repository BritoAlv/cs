namespace more_wrong
{
    public class Test
    {
        public static void Main()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int n = int.Parse(Console.ReadLine());
                HashSet<int> set = new();
                List<int> values = new();
                for (int i = 1; i <= n; i++)
                {
                    set.Add(i);
                    values.Add(i);
                }
                Stack<int> to_remove = new();
                while (set.Count > 1)
                {
                    for (int i = 0; i < values.Count - 1; i += 2)
                    {
                        var first = values[i];
                        var second = values[i + 1];

                        Console.WriteLine("? " + first + " " + second);
                        int answer1 = int.Parse(Console.ReadLine());
                        if (answer1 == -1)
                        {
                            return;
                        }
                        if (answer1 == 0)
                        {
                            to_remove.Push(first);
                            continue;
                        }
                        if (second - first == 1)
                        {
                            /*
                            seems cheaper this case.
                            */
                            if (answer1 == 0)
                            {
                                to_remove.Push(first);
                            }
                            else
                            {
                                to_remove.Push(second);
                            }
                        } 
                        else
                        {
                            Console.WriteLine("? " + first + " " + (second - 1));
                            int answer2 = int.Parse(Console.ReadLine());
                            if (answer2 == -1)
                            {
                                return;
                            }
                            if (answer1 == answer2)
                            {
                                to_remove.Push(first);
                            }
                            else
                            {
                                to_remove.Push(second);
                            }
                        }
                    }
                    while (to_remove.Count > 0)
                    {
                        var popped = to_remove.Pop();
                        if (set.Contains(popped))
                        {
                            set.Remove(popped);
                        }
                    }
                    values = set.ToList();
                }
                Console.WriteLine("! " + set.First());
                test_cases--;
            }
        }
    }
}