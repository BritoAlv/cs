namespace two_binary_strings
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                string binary1 = Console.ReadLine();
                string binary2 = Console.ReadLine();

                var len = binary1.Length;
                List<int> zero_matchs = new();
                List<int> one_matchs = new();

                for (int i = 0; i < len; i++)
                {
                    if (binary1[i] == binary2[i])
                    {
                        if (binary1[i] == '0')
                        {
                            zero_matchs.Add(i);
                        }
                        else
                        {
                            one_matchs.Add(i);
                        }
                    }
                }
                bool solved = false;
                for (int i = 0; i < zero_matchs.Count; i++)
                {
                    if (binary1[zero_matchs[i] + 1] == binary2[zero_matchs[i] + 1] && binary1[zero_matchs[i] + 1] == '1')
                    {
                        solved = true;
                        break;
                    }
                }
                for (int i = 0; i < zero_matchs.Count; i++)
                {
                    if (binary1[one_matchs[0] - 1] == binary2[one_matchs[0] - 1] && binary1[one_matchs[0] - 1] == '0')
                    {
                        solved = true;
                        break;
                    }
                }
                Console.WriteLine(solved ? "YES": "NO");
                test_cases--;
            }
        }
    }
}