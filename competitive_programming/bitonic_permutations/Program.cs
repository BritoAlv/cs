public class Test
{
    public static void Main()
    {
        long mod = (10 * 10 * 10) * (10 * 10 * 10) * 10 * 10 * 10 + 7;
        List<long> answers = new List<long>();
        int test_cases = int.Parse(Console.ReadLine());
        while (test_cases > 0)
        {
            string[] line = Console.ReadLine().Split();
            answers.Add(
                algorithm
                (
                    int.Parse(line[0]),
                    int.Parse(line[1]),
                    int.Parse(line[2]),
                    int.Parse(line[3]),
                    int.Parse(line[4]), mod
                )
                );
            test_cases--;
        }
        foreach (var item in answers)
        {
            Console.WriteLine(item);
        }


    }

    private static long algorithm(int n, int i, int j, int x, int y, long mod)
    {
        /*
        case 1: x == n.
        */
        long answer = 0;
        if (x == n && i != n && i != 1)
        {
            /*
            this means that we have n at the left of a fixed position y. 
            */
            answer = combinations(y - 1, n - j) * combinations(n - (y + 1), j - (i + 1));
            answer = answer % mod;
        }
        else if (y == n && j != n && j != 1)
        {
            /*
            this means that we have n at the right of a fixed position 
            */
            answer = combinations(x - 1, i - 1) * combinations(n - (x + 1), j - (i + 1));
            answer = answer % mod;
        }
        else
        {
            for (int m = 2; m < n; m++)
            {
                if (m != i && m != j)
                {
                    if (m < i) // left
                    {
                        if (x < y)
                        {
                            continue;
                        }
                        answer += ((combinations(y - 1, n - j) * combinations(x - y - 1, j - i - 1)) % mod) * combinations(n - x - 1, i - m - 1);
                        answer = answer % mod;
                    }
                    else if (m > j) // right
                    {
                        if (x > y)
                        {
                            continue;
                        }
                        answer += ((combinations(x - 1, i - 1) * combinations(y - x - 1, j - i - 1)) % mod) * combinations(n - y - 1, m - j - 1);
                        answer = answer % mod;
                    }
                    else // middle
                    {
                        if (x < y)
                        {
                            answer += ((combinations(x - 1, i - 1) * combinations(n - y - 1, j - m - 1)) % mod) * combinations(y - x - 1, n - j - (x - 1 - (i - 1))) % mod;
                        }
                        else
                        {
                            answer += ((combinations(y - 1, n - j) * combinations(n - x - 1, m - i - 1)) % mod) * combinations(x - y - 1, i - (y - (n - j)));
                        }
                        answer = answer % mod;
                    }
                }
            }
        }
        return answer;
    }

    public static long combinations(int n, int i, int mod = (10 * 10 * 10) * (10 * 10 * 10) * 10*10*10 + 7)
    {
        if (n < i)
        {
            return 0;
        }
        if (i < 0)
        {
            return 0;
        }
        if (n == i && n == 0)
        {
            return 1;
        }
        if (n <= 0)
        {
            return 0;
        }
        if (i == 0)
        {
            return 1;
        }
        else
        {
            long nfactorial = n_factorial_mod(n, mod);
            nfactorial = (nfactorial * get_inverse(n_factorial_mod(i, mod), mod)) % mod;
            nfactorial = (nfactorial * get_inverse(n_factorial_mod(n - i, mod), mod)) % mod;
            return nfactorial;
        }
    }

    public static long n_factorial_mod(int n, int mod)
    {
        if (n <= 1)
        {
            return 1;
        }
        long answer = 1;
        for (int i = 2; i <= n; i++)
        {
            answer = (answer * i) % mod;
        }
        return answer;
    }
    public static long get_inverse(long n, int mod)
    {
        /*
        compute the inverse of n mod mod
        */
        // return fast_exponentiation(n, mod - 2, mod);
        if (n == 0)
        {
            return 1; // this works ? but doesn't make sense. 
        }
        var ans = solve_diop(mod, n).Item2;
        while (ans < 0)
        {
            ans += mod;
        }
        return ans;
    }

    public static (long, long) solve_diop(long a, long b)
    {
        if (a < 0)
        {
            var temp = solve_diop(-a, b);
            temp.Item1 = -temp.Item1;
            return temp;
        }
        if (b < 0)
        {
            var temp = solve_diop(a, -b);
            temp.Item2 = -temp.Item2;
            return temp;
        }
        if (a < b)
        {
            var ans = solve_diop(b, a);
            long temp = ans.Item1;
            ans.Item1 = ans.Item2;
            ans.Item2 = temp;
            return ans;
        }
        if (b == 1)
        {
            return (-1, a + 1);
        }
        var anss = solve_diop(a - (a / b) * b, b);
        return (anss.Item1, anss.Item2 - (a / b) * anss.Item1);
    }
}