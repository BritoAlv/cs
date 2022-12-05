global using Xunit;

public class CardTests
{
    [Fact]
    public void CanCreateCardWithValue()
    {
        var card = new Card(CardValue.As, CardSuit.Pica);
        Assert.Equal(CardSuit.Pica, card.Suit);
        Assert.Equal(CardValue.As, card.Value);
    }

    [Fact]
    public void CanDescribeCard()
    {
        var card = new Card(CardValue.As, CardSuit.Trébol);
        Assert.Equal("Un As de Trébol", card.ToString());
    }
}