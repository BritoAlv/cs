namespace word_on_the_paper
{
public class Test
{
    public static void Algorithm()
    {
        int test_cases = int.Parse(Console.ReadLine());
        while( test_cases > 0)
        {    
            List<char> word = new();
            for (int i = 0; i < 8; i++)
            {
                var line = Console.ReadLine().Where(x => char.IsLetter(x));
                if (line.Count() > 0 )
                {
                    word.Add(line.First());
                }
            }
            Console.WriteLine(string.Join("", word));
            test_cases--;
        }
    }
}
}