using System.Collections;

public class Problem
{
    public static void Main()
    {
        int number_cases = int.Parse(Console.ReadLine());
        int[] lens = new int[number_cases];
        string[] strings = new string[number_cases];
        for (int i = 0; i < number_cases; i++)
        {
            int len = int.Parse(Console.ReadLine());
            strings[i] = Console.ReadLine();
        }

        for (int i = 0; i < number_cases; i++)
        {
            Console.WriteLine(get_minimum_melodies(strings[i]));
        }
    }

    public static int get_minimum_melodies(string melody)
    {
        HashSet<string> set = new HashSet<string>();
        for (int i = 0; i < melody.Length - 1; i++)
        {
            var mel = melody.Substring(i, 2);
            if (!set.Contains(mel))
            {
                set.Add(mel);
            }
            set.Add(mel);
        }
        return set.Count;
    }
}





