namespace rudolph_tic_tac_toe
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                char answer = 'D';
                char[,] ints = new char[3, 3];
                var line1 = Console.ReadLine();
                var line2 = Console.ReadLine();
                var line3 = Console.ReadLine();
                for (int i = 0; i < 3; i++)
                {
                    ints[0, i] = line1[i];
                    ints[1, i] = line2[i];
                    ints[2, i] = line3[i];
                }
                if (ints[0, 0] != '.' && ints[0, 0] == ints[1, 1] && ints[0, 0] == ints[2, 2])
                {
                    Console.WriteLine(ints[0, 0]);
                }

                else if (ints[0, 2] != '.' && ints[0, 2] == ints[1, 1] && ints[0, 2] == ints[2, 0])
                {
                    Console.WriteLine(ints[0, 2]);
                }
                else
                {
                    for (int i = 0; i < 3; i++)
                    {
                        if (ints[i, 0] != '.' && ints[i, 0] == ints[i, 1] && ints[i, 0] == ints[i, 2])
                        {
                            answer = (ints[i, 0]);
                            break;
                        }

                        if (ints[0, i] != '.' && ints[0, i] == ints[1, i] && ints[0, i] == ints[2, i])
                        {
                            answer = (ints[0, i]);
                            break;
                        }
                    }
                    if (answer == 'D')
                    {
                        Console.WriteLine("DRAW");
                    }
                    else
                    {
                        Console.WriteLine(answer);

                    }
                }
                test_cases--;
            }
        }
    }
}