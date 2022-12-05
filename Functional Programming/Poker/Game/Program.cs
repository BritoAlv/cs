using Poker;

public class Test
{
    public static void Main()
    {
        Hand A = new Hand();
        A.Draw(new Card(CardValue.As, CardSuit.Diamante));
        A.Draw(new Card(CardValue.As, CardSuit.Diamante));
        A.Draw(new Card(CardValue.As, CardSuit.Diamante));
        A.Draw(new Card(CardValue.As, CardSuit.Diamante));
        A.Draw(new Card(CardValue.As, CardSuit.Diamante));
        Console.WriteLine(FiveCardPokerScorer.GetHandRank(A.Cards));
        
    }
}