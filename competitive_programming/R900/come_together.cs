namespace come_together
{
    public class Test
    {
        public static void Algorithm()
        {
            int test_cases = int.Parse(Console.ReadLine());
            while (test_cases > 0)
            {
                int[] fix1 = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int[] fix2 = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                int[] fix3 = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();

                List<int> valid_distances_x = new();
                List<int> valid_distances_y = new();

                if (fix1[0] - Math.Min(fix2[0], fix3[0]) < 0)
                {
                    valid_distances_x.Add(-(fix1[0] - Math.Min(fix2[0], fix3[0])));
                }

                if (fix1[0] - Math.Max(fix2[0], fix3[0]) > 0)
                {
                    valid_distances_x.Add(fix1[0] - Math.Max(fix2[0], fix3[0]));
                }

                if (fix1[1] - Math.Min(fix2[1], fix3[1]) < 0)
                {
                    valid_distances_y.Add(-(fix1[1] - Math.Min(fix2[1], fix3[1])));
                }

                if (fix1[1] - Math.Max(fix2[1], fix3[1]) > 0)
                {
                    valid_distances_y.Add(fix1[1] - Math.Max(fix2[1], fix3[1]));
                }

                Console.WriteLine(
                    (valid_distances_x.Count == 0 ? 0 : valid_distances_x.Min()) +
                    (valid_distances_y.Count == 0 ? 0 : valid_distances_y.Min()) +
                    + 1);


                test_cases--;
            }
        }
    }
}