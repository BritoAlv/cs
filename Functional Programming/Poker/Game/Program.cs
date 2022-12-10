using Poker;

public class Program
{
    public static void Main()
    {
        while (true)
        {
            Hand A = generate_random_hand();
            Hand B = generate_random_hand();
            Console.WriteLine(A.ToStringWithRank());
            Console.WriteLine(B.ToStringWithRank());
            int result = A.CompareTo(B);
            switch (result)
            {
                case 1:
                    if (A.rank == B.rank)
                    {
                        Console.WriteLine($"Poseen el mismo rango {A.rank}, still A wins.");
                    }
                    else
                    {
                        Console.WriteLine($"A le gana a B porque {A.rank} es mejor que {B.rank}");
                    }

                    break;
                case -1:
                    if (A.rank == B.rank)
                    {
                        Console.WriteLine($"Poseen el mismo rango {A.rank}, still B wins.");
                    }
                    else
                    {
                        Console.WriteLine($"B le gana a A porque {B.rank} es mejor que {A.rank}");
                    }
                    break;
                default:
                    Console.WriteLine("=> Están empatados");
                    break;
            }
            Console.WriteLine();
            Console.ReadLine();
        }


    }

    public static Hand generate_random_hand()
    {
        Hand A = new Hand();
        for (int i = 0; i < 5; i++)
        {
            A.Draw(generate_random_card());
        }
        return A;
    }

    public static Card generate_random_card()
    {
        return new Card(generate_random_value(), generate_random_suit());
    }

    private static CardSuit generate_random_suit()
    {
        var rnd = new Random();
        return rnd.NextEnum<CardSuit>();
    }

    private static CardValue generate_random_value()
    {
        var rnd = new Random();
        return rnd.NextEnum<CardValue>();
    }
}
