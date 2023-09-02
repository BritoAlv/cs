namespace prime_deletion
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            bool[] is_prime = new bool[10 * 10 * 10 * 10];
            Array.Fill(is_prime, true);
            for (int i = 2; i < is_prime.Length; i++)
            {
                if (is_prime[i])
                {
                    for (int j = 2 * i; j < is_prime.Length; j += i)
                    {
                        is_prime[j] = false;
                    }
                }
            }
            while (test_cases > 0)
            {
                string number = Console.ReadLine();
                Dictionary<char, int> positions_digit = new();
                for (int i = 0; i < number.Length; i++)
                {
                    positions_digit[number[i]] = i;
                }
                int answer = -1;
                for (int i = 11; i < is_prime.Length; i++)
                {
                    if (is_prime[i])
                    {
                        string str_num = i.ToString();
                        int last_pos = -1;
                        for (int j = 0; j < str_num.Length; j++)
                        {
                            if (positions_digit.ContainsKey(str_num[j]) && positions_digit[str_num[j]] > last_pos)
                            {
                                last_pos = positions_digit[str_num[j]];
                            }
                            else
                            {
                                last_pos = -1;
                                break;
                            }
                        }
                        if (last_pos > 0)
                        {
                            answer = i;
                            break;
                        }
                    }
                }
                Console.WriteLine(answer);
                test_cases--;
            }
        }
    }
}