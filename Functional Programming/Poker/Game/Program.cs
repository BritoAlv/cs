using Poker;

public class Test
{
    public static void Main()
    {
        Hand A = new Hand();
        A.Draw(new Card(CardValue.Reina, CardSuit.Diamante));
        A.Draw(new Card(CardValue.Reina, CardSuit.Diamante));
        A.Draw(new Card(CardValue.As, CardSuit.Diamante));
        A.Draw(new Card(CardValue.Reina, CardSuit.Diamante));
        A.Draw(new Card(CardValue.As, CardSuit.Diamante));
        Hand B = new Hand();
        B.Draw(new Card(CardValue.Príncipe, CardSuit.Pica));
        B.Draw(new Card(CardValue.Príncipe, CardSuit.Diamante));
        B.Draw(new Card(CardValue.Príncipe, CardSuit.CorazónRojo));
        B.Draw(new Card(CardValue.As, CardSuit.Diamante));
        B.Draw(new Card(CardValue.As, CardSuit.Diamante));

        Console.WriteLine(A.ToStringWithRank());
        Console.WriteLine(B.ToStringWithRank());
        int result = A.CompareTo(B);
        switch (result)
        {
            case 1:
                Console.WriteLine("A le gana a B");
                break;
            case -1:
                Console.WriteLine("B le gana a A");
                break;
            default:
                Console.WriteLine("=> Están empatados");
                break;
        }

    }
}