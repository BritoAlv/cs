namespace desorting
{
    public class Test
    {
        public static void Main()
        {
            int t = int.Parse(Console.ReadLine());
            int[] answers = new int[t];
            while (t > 0)
            {
                int len = int.Parse(Console.ReadLine());
                int[] arr = Console.ReadLine().Split().Select(x => int.Parse(x)).ToArray();
                answers[^t] = Alg(arr);
                t--;
            }
            foreach (var item in answers)
            {
                Console.WriteLine(item);
            }    
        }

        private static int Alg(int[] arr)
        {
            var smallest_dif = int.MaxValue;
            for (int i = 0; i < arr.Length-1; i++)
            {
                if (arr[i] > arr[i+1])
                {
                    return 0;
                }
                else if (arr[i] == arr[i+1])
                {
                    smallest_dif = 1;
                }
                else
                {
                    smallest_dif = Math.Min( arr[i + 1] - arr[i], smallest_dif);
                }
            }
            return smallest_dif / 2 + 1;
        }
    }
}