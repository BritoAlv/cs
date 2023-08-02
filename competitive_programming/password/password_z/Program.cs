namespace password_z
{
    public class Test
    {
        public static void Main()
        {
            string s = Console.ReadLine();
            int result = Z_password(s);
            if (result == -1)
            {
                Console.WriteLine("Just a legend");
            }
            else
            {
                for (int i = 0; i < result; i++)
                {
                    Console.WriteLine(s[i]);
                }
            }
        }

        public static int Z_password(string s)
        {
            int[] z = new int[s.Length];
            int l = 0;
            int maxz = 0;
            z[0] = 0;
            for (int i = 1; i < s.Length; i++)
            {
                z[i] = Math.Min(z[i - l], Math.Max(0, l + z[l] - i));
                while (i + z[i] < s.Length && s[z[i]] == s[i + z[i]])
                {
                    z[i]++;
                }
                if (i + z[i] > l + z[l])
                {
                    l = i;
                }
                if (z[i] == s.Length - i && maxz >= s.Length - i)
                {
                    return s.Length - i;
                }
                maxz = Math.Max(maxz, z[i]);
            }
            return -1;
        }
    }
}