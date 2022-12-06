using Poker;

public class Test
{
    public static void Main()
    {
        Hand A = new Hand();
        A.Draw(new Card(CardValue.Príncipe, CardSuit.Diamante));
        A.Draw(new Card(CardValue.Príncipe, CardSuit.Diamante));
        A.Draw(new Card(CardValue.As, CardSuit.Diamante));
        A.Draw(new Card(CardValue.Reina, CardSuit.Diamante));
        A.Draw(new Card(CardValue.As, CardSuit.Diamante));
        Console.WriteLine(Scorer.GetHandRank(A.Cards));

        Hand B = new Hand();
        B.Draw(new Card(CardValue.Príncipe, CardSuit.Pica));
        B.Draw(new Card(CardValue.Príncipe, CardSuit.Diamante));
        B.Draw(new Card(CardValue.Príncipe, CardSuit.CorazónRojo));
        B.Draw(new Card(CardValue.As, CardSuit.Diamante));
        B.Draw(new Card(CardValue.As, CardSuit.Diamante));
        Console.WriteLine(Scorer.GetHandRank(B.Cards));

        Console.WriteLine(A.CompareTo(B));
    

    }
}