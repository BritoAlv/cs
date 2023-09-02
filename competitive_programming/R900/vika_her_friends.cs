namespace vika_her_friends
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int[] fix = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int n = fix[0];
                int m = fix[1];
                int k = fix[2];
                int[] fix2 = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int x = fix2[0];
                int y = fix2[1];

                int vika_color = (x + y) % 2;
                int[] fix3 = new int[2];
                int friends_same_color = 0;
                int t = k;
                while (t > 0)
                {
                    fix3 = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                    if ((fix3[0] + fix3[1]) % 2 == vika_color)
                    {
                        friends_same_color++;
                    }
                    t--;
                }

                if (friends_same_color >= 1)
                {
                    Console.WriteLine("NO");
                }

                else if (friends_same_color == 1)
                {
                    Console.WriteLine(n == 1 || m == 1 ? "NO" : "YES");
                }

                else
                {
                    Console.WriteLine("YES");
                }
                test_cases--;
            }
        }
    }
}