namespace imbalanced_arrays
{
    public class Simulator
    {
        int Next_positive { get; set; }
        int Next_negative { get; set; }
        public Simulator(int n)
        {
            Next_positive = n;
            Next_negative = -n;
        }
        public int Extract(bool positive)
        {
            Next_positive--;
            Next_negative++;
            if (positive)
            {
                return Next_positive + 1;
            }
            else
            {
                return Next_negative - 1;
            }
        }
    }
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
                                             .OrderByDescending(z => z.Item2) // makes the solution O(nlogn)
                                             .ToArray();
                int[] answer = new int[n];

                /*
                loop over possible values of cant_positive numbers until we get to a valid one, starting from 0, 
                */

                int cant_positive = 0; // for now let's assume this is the number of positives.
                int pointer = n - 1;

                /*
                pointer will set to the greatest valid position of the array so that to its right all the degrees are >= 
                cant_positive +  1, becuase will test if the cant of positive can be incremented.

                Claim unlock: 

                the degree of the greatest positive vertex = cant_positive + cant_negative with degree >= 1.
                the degree of the second   positive vertex = cant_positive + cant_negative with degree >= 2. 
                ......

                so we loop until we get to a cant_positive that breaks this condition and use the last answer.
                */ 

                while (pointer >= 0 && values[pointer].Item2 < cant_positive + 1)
                {
                    pointer--;
                }
                while (cant_positive < n)
                {
                    if (values[cant_positive].Item2 <= cant_positive || values[cant_positive].Item2 != (pointer + 1))
                    {
                        break;
                    }
                    cant_positive++;
                    while (pointer >= 0 && values[pointer].Item2 < cant_positive + 1)
                    {
                        pointer--;
                    }
                }

                /*
                at this point the cant_positive is set.
                */

                bool finished = true;
                if (values[0].Item2 == 0)
                {
                    Array.Fill(answer, -n);
                }
                else if (values[n - 1].Item2 == n)
                {
                    Array.Fill(answer, n);
                }
                else if (cant_positive >= values[cant_positive].Item2 && values[cant_positive - 1].Item2 >= cant_positive)
                {
                    Simulator A = new(n);
                    int next_to_use = 0;
                    for (int i = n - 1; i >= cant_positive; i--)
                    {
                        for (int j = next_to_use; j < values[i].Item2; j++)
                        {
                            if (answer[values[j].Item1] == 0)
                            {
                                answer[values[j].Item1] = A.Extract(true);
                            }
                        }
                        next_to_use = Math.Max(next_to_use, values[i].Item2);
                        answer[values[i].Item1] = A.Extract(false);
                    }
                    for (int i = cant_positive - 1; i >= 0; i--)
                    {
                        if (answer[values[i].Item1] == 0)
                        {
                            answer[values[i].Item1] = A.Extract(true);
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                else
                {
                    finished = false;
                }
                if (finished)
                {
                    Console.WriteLine("YES");
                    Console.WriteLine(string.Join(" ", answer));
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