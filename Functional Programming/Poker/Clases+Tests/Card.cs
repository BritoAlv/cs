using NeoSmart.Unicode;
public class Card
{
    public Card(CardValue value, CardSuit suit)
    {
        Value = value;
        Suit = suit;
    }

    public CardValue Value { get; }
    public CardSuit Suit { get; }

    public override string ToString() => $" {((int)this.Value)}{this.Suit.GetEmoji()} ";
}
  