using FluentAssertions;

namespace Poker
{
    public class FiveCardPokerScorerTests
    {
        [Fact]
        public void CanGetHighCard()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.Siete, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Diez, CardSuit.Diamante));
            hand.Draw(new Card(CardValue.Cinco, CardSuit.CorazónRojo));
            hand.Draw(new Card(CardValue.Rey, CardSuit.CorazónRojo));
            hand.Draw(new Card(CardValue.Dos, CardSuit.CorazónRojo));
            FiveCardPokerScorer.HighCard(hand.Cards).Value.Should().Be(CardValue.Rey);
        }

        [Fact]
        public void CanScoreHighCard()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.Siete, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Diez, CardSuit.Diamante));
            hand.Draw(new Card(CardValue.Cinco, CardSuit.CorazónRojo));
            hand.Draw(new Card(CardValue.Rey, CardSuit.CorazónRojo));
            hand.Draw(new Card(CardValue.Dos, CardSuit.CorazónRojo));
            FiveCardPokerScorer.GetHandRank(hand.Cards).Should().Be(HandRank.CartaAlta);
        }

        [Fact]
        public void CanScoreFlush()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.Dos, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Tres, CardSuit.Pica));
            hand.Draw(new Card(CardValue.As, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Cinco, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Seis, CardSuit.Pica));
            FiveCardPokerScorer.GetHandRank(hand.Cards).Should().Be(HandRank.Color);
        }
        [Fact]
        public void CanScoreRoyalFlush()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.Diez, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Príncipe, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Reina, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Rey, CardSuit.Pica));
            hand.Draw(new Card(CardValue.As, CardSuit.Pica));
            FiveCardPokerScorer.GetHandRank(hand.Cards).Should().Be(HandRank.EscaleraReal);
        }

        [Fact]
        public void CanScorePair()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.Diez, CardSuit.Diamante));
            hand.Draw(new Card(CardValue.Príncipe, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Nueve, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Diez, CardSuit.CorazónRojo));
            hand.Draw(new Card(CardValue.As, CardSuit.Pica));
            FiveCardPokerScorer.GetHandRank(hand.Cards).Should().Be(HandRank.Pareja);
        }

        [Fact]
        public void CanScoreTwoPair()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.Diez, CardSuit.Diamante));
            hand.Draw(new Card(CardValue.Príncipe, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Príncipe, CardSuit.Diamante));
            hand.Draw(new Card(CardValue.Diez, CardSuit.CorazónRojo));
            hand.Draw(new Card(CardValue.As, CardSuit.Pica));
            FiveCardPokerScorer.GetHandRank(hand.Cards).Should().Be(HandRank.DosParejas);
        }

        [Fact]
        public void CanScoreThreeOfAKind()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.Diez, CardSuit.Diamante));
            hand.Draw(new Card(CardValue.Príncipe, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Nueve, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Diez, CardSuit.CorazónRojo));
            hand.Draw(new Card(CardValue.Diez, CardSuit.Pica));
            FiveCardPokerScorer.GetHandRank(hand.Cards).Should().Be(HandRank.Trio);
        }
        [Fact]
        public void CanScoreFourOfAKind()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.Diez, CardSuit.Diamante));
            hand.Draw(new Card(CardValue.Príncipe, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Diez, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Diez, CardSuit.CorazónRojo));
            hand.Draw(new Card(CardValue.Diez, CardSuit.Pica));
            FiveCardPokerScorer.GetHandRank(hand.Cards).Should().Be(HandRank.CuatroIguales);

        }
        [Fact]
        public void CanScoreFullHouse()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.Diez, CardSuit.Diamante));
            hand.Draw(new Card(CardValue.Príncipe, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Diez, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Príncipe, CardSuit.CorazónRojo));
            hand.Draw(new Card(CardValue.Diez, CardSuit.Pica));
            FiveCardPokerScorer.GetHandRank(hand.Cards).Should().Be(HandRank.Full);

        }

        [Fact]
        public void CanScoreStraight()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.Diez, CardSuit.Diamante));
            hand.Draw(new Card(CardValue.Príncipe, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Reina, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Rey, CardSuit.CorazónRojo));
            hand.Draw(new Card(CardValue.As, CardSuit.Pica));

            FiveCardPokerScorer.GetHandRank(hand.Cards).Should().Be(HandRank.Escalera);
        }

        [Fact]
        public void CanScoreStraightUnordered()
        {
            var hand = new Hand();
            hand.Draw(new Card(CardValue.As, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Reina, CardSuit.Diamante));
            hand.Draw(new Card(CardValue.Príncipe, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Diez, CardSuit.Pica));
            hand.Draw(new Card(CardValue.Rey, CardSuit.CorazónRojo));

            FiveCardPokerScorer.GetHandRank(hand.Cards).Should().Be(HandRank.Escalera);
        }
    }


}
