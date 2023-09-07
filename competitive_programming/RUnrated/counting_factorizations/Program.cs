/*
CODEFORCES 1794 D
*/
public class Test
{

    public static void Main()
    {
        // Constants
        int mod = 998244353;
        // Input
        int n = int.Parse(Console.ReadLine());
        List<int> numbers = Console.ReadLine().Split().Select(x => int.Parse(x)).ToList();
        long answer = algorithm(n, numbers, mod);
        Console.WriteLine(answer);
    }

    public static long algorithm(int n, List<int> numbers, int mod)
    {
        // PRE-COMPUTED
        long pre_n = n_factorial_mod(n, mod);
        long[] inverse_factorials = new long[2 * n + 1];
        for (int i = 0; i < 2 * n + 1; i++)
        {
            inverse_factorials[i] = get_inverse(n_factorial_mod(i, mod), mod);
        }
        bool[] is_primes = primes_less_than(10 * 10 * 10 * 10 * 10 * 10);
        Dictionary<int, int> primes = new Dictionary<int, int>();
        Dictionary<int, int> no_primes = new Dictionary<int, int>();
        foreach (var item in numbers)
        {
            if (is_primes[item])
            {
                if (!primes.ContainsKey(item))
                {
                    primes[item] = 0;
                }
                primes[item]++;
            }
            else
            {
                if (!no_primes.ContainsKey(item))
                {
                    no_primes[item] = 0;
                }
                no_primes[item]++;
            }
        }
        if (primes.Count < n)
        {
            return 0;
        }
        // THE OTHER COMPUTED DATA IS THE PRODUCT OF N! BY INVERSE OF NO_PRIMES_FACTORIALS.

        // FINAL ANSWER SHOULD BE MULTIPLIED BY THIS NUMBER.
        long answer = 0;
        List<long> values = new List<long>();
        foreach (var value in primes.Values)
        {
            values.Add(get_inverse(value, mod));
        }
        answer += generate_sum(values, primes.Count - n, mod);
        answer = (answer * pre_n) % mod;
        foreach (var item in no_primes.Keys)
        {
            answer = (answer * inverse_factorials[no_primes[item]]) % mod;
        }
        foreach (var item in primes.Keys)
        {
            answer = (answer * inverse_factorials[primes[item] - 1]) % mod;
        }
        return answer;
    }

    /*
    DP, using C(n,k) = C(n-1, k) + C(n-1, k-1)
    */
    public static long generate_sum(List<long> values, int k, int mod)
    {
        int n = values.Count;
        if (n == 0)
        {
            return 1;
        }
        List<long> row = new List<long>();
        /*
        set up C(1,0) && C(1,1)
        */
        row.Add(1);
        row.Add(values[0]);
        for (int i = 2; i <= n; i++)
        {
            List<long> row_updated = new List<long>();
            for (int j = 0; (j <= k && j <= i); j++)
            {
                if (j == 0)
                {
                    row_updated.Add(1);
                }
                else if (j == i)
                {
                    long ans = 1;
                    for (int z = 0; z < i; z++)
                    {
                        ans = (ans * values[z]) % mod;
                    }
                    row_updated.Add(ans);
                }
                else
                {
                    row_updated.Add
                    (
                        generate_new_value(row[j - 1], row[j], n, values[i - 1], mod)
                    );
                }
            }
            row = row_updated;
        }
        return row[k];
    }
    static long generate_new_value(long k_1, long k, int n, long ai, int mod)
    {
        long ans = (ai * k_1) % mod;
        ans += k;
        ans = ans % mod;
        return ans;
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

    public static long fast_exponentiation(long n, int exp, int mod)
    {
        /*
        given n and exp, using mod, return n^{exp} mod mod.
        */
        if (n == 1)
        {
            return 1;
        }
        if (exp == 0)
        {
            return 1;
        }
        if (exp == 1)
        {
            return n;
        }
        long number = n;
        number = (number * number) % mod;
        if (exp % 2 == 0)
        {
            return fast_exponentiation(number, exp / 2, mod);
        }
        else
        {
            return (n * fast_exponentiation(number, (exp - 1) / 2, mod)) % mod;
        }
    }
    /*
    use the array returned by this to check if primes[i] is prime.
    */
    public static bool[] primes_less_than(int n)
    {
        bool[] primes = new bool[n + 1];
        Array.Fill(primes, true);
        primes[0] = false;
        primes[1] = false;
        for (int i = 2; i < n + 1; i++)
        {
            if (primes[i])
            {
                int j = i + i;
                while (j <= n)
                {
                    primes[j] = false;
                    j += i;
                }
            }
        }
        return primes;
    }

    /*
    Given nonzero - integers (a,b) return (x,y) so that ax + by = 1. Assuming that (a,b) = 1
    */
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
        var anss = solve_diop(a - (a/b) * b, b);
        return (anss.Item1, anss.Item2 - (a/b)*anss.Item1);
    }
}