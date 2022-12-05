using FluentAssertions;
using Poker;
public class HandTests
{
    [Fact]
    public void CanCreateHand()
    {
        var hand = new Hand();
        // Any determines if a sequence contains elements.
        Assert.False(hand.Cards.Any());
    }

    [Fact]
    public void CanHandDrawCard()
    {
        var card = new Card(CardValue.As, CardSuit.Pica);
        var hand = new Hand();

        hand.Draw(card);
        // First return the first element in a sequence.
        Assert.Equal(hand.Cards.First(), card);
    }
    
}
