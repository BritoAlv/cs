using System;
using System.Collections.Generic;
using System.Linq;

namespace Poker
{
    /*
    scorer for five cards poker.
    */
    public class FiveCardPokerScorer
    {
        /*
        Todos las funciones por las que ranqueamos una mano.
        */
        public static Card HighCard(IEnumerable<Card> cards) => cards.Aggregate((highCard, nextCard) => nextCard.Value > highCard.Value ? nextCard : highCard);
        private static bool HasFlush(IEnumerable<Card> cards) => cards.All(c => cards.First().Suit == c.Suit);
        private static bool HasRoyalFlush(IEnumerable<Card> cards) => HasStraightFlush(cards) && cards.All(c => c.Value > CardValue.Nueve);
        private static bool HasOfAKind(IEnumerable<Card> cards, int num) => cards.ToKindAndQuantities().Any(c => c.Value >= num);
        private static int CountOfAKind(IEnumerable<Card> cards, int num) => cards.ToKindAndQuantities().Count(c => c.Value == num);
        private static bool HasPair(IEnumerable<Card> cards) => HasOfAKind(cards, 2);
        private static bool HasTwoPair(IEnumerable<Card> cards) => CountOfAKind(cards, 2) == 2;
        private static bool HasThreeOfAKind(IEnumerable<Card> cards) => HasOfAKind(cards, 3);
        private static bool HasFourOfAKind(IEnumerable<Card> cards) => HasOfAKind(cards, 4);
        private static bool HasFullHouse(IEnumerable<Card> cards) => HasThreeOfAKind(cards) && HasPair(cards);
        private static bool HasStraight(IEnumerable<Card> cards) => cards.OrderBy(card => card.Value).SelectConsecutive((n, next) => n.Value + 1 == next.Value).All(value => value);
        private static bool HasStraightFlush(IEnumerable<Card> cards) => HasStraight(cards) && HasFlush(cards);

        // A list of ranks gives added flexibility to how hand ranks can be scored.
        // Each ranker has an Eval delegate that returns a bool

        // a function that gives us the rank of a hand, by taking an IEnumerable of cards. But first it takes a list of ranking functions and
        // ranks them by its priotity, and after that we find the first function between the rankings, that evaluates true.
        public static HandRank GetHandRank(IEnumerable<Card> cards) => Rankings()
                           .OrderByDescending(card => card.rank)
                           .First(rule => rule.eval(cards)).rank;

        /*
        This contains the rankings in tuples, of the form
        ( Delegate, rank of hand). 

        functions as data.
        */
        private static List<(Func<IEnumerable<Card>, bool> eval, HandRank rank)> Rankings() =>
           new List<(Func<IEnumerable<Card>, bool> eval, HandRank rank)>
           {
                       (cards => HasRoyalFlush(cards), HandRank.EscaleraReal),
                       (cards => HasStraightFlush(cards), HandRank.EscaleraColor),
                       (cards => HasFourOfAKind(cards), HandRank.CuatroIguales),
                       (cards => HasFullHouse(cards), HandRank.Full),
                       (cards => HasFlush(cards), HandRank.Color),
                       (cards => HasStraight(cards), HandRank.Escalera),
                       (cards => HasThreeOfAKind(cards), HandRank.Trio),
                       (cards => HasTwoPair(cards), HandRank.DosParejas),
                       (cards => HasPair(cards), HandRank.Pareja),
                       (cards => true, HandRank.CartaAlta),
           };

    }
}