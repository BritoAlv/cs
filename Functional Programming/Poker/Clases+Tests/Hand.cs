namespace Poker
{
    public class Hand : IComparable<Hand>
    {
        private List<Card> _cards = new List<Card>();
        public IEnumerable<Card> Cards
        {
            get
            {
                return this._cards;
            }
        }

        public int CompareTo(Hand? other)
        {
            if (Scorer.GetHandRank(this.Cards) > Scorer.GetHandRank(other.Cards))
            {
                return 1;
            }
            else if (Scorer.GetHandRank(this.Cards) < Scorer.GetHandRank(other.Cards))
            {
                return -1;
            }
            else
            {
                var common_rank = Scorer.GetHandRank(this.Cards);
                switch (common_rank)
                {
                    case HandRank.EscaleraReal:
                        return 0;
                    case HandRank.EscaleraColor:
                        return this.Cards.OrderByDescending(x => x.Value).First().Value.CompareTo(other.Cards.OrderByDescending(x => x.Value).First().Value);
                    case HandRank.CuatroIguales:
                        return this.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 4).First().First().Value.CompareTo(other.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 4).First().First().Value);
                    case HandRank.Full:
                        return this.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 3).First().First().Value.CompareTo(other.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 3).First().First().Value);
                    case HandRank.Color:
                        return this.Cards.OrderByDescending(x => x.Value).First().Value.CompareTo(other.Cards.OrderByDescending(x => x.Value).First().Value);
                    case HandRank.Escalera:
                        return this.Cards.OrderByDescending(x => x.Value).First().Value.CompareTo(other.Cards.OrderByDescending(x => x.Value).First().Value);
                    case HandRank.Trio:
                        return this.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 3).First().First().Value.CompareTo(other.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 3).First().First().Value) == 0 ? this.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 3).First().First().Value.CompareTo(other.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 3).First().First())  :this.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 3).First().First().Value.CompareTo(other.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 3).First().First()) ;
                    case HandRank.DosParejas:
                        return this.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 2).Select(x => x.First().Value).Order().Last().CompareTo(other.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 2).Select(x => x.First().Value).Order().Last());
                    case HandRank.Pareja:
                        return this.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 2).First().First().Value.CompareTo(other.Cards.GroupBy(x => x.Value).Where(x => x.Count() == 2).First().First().Value);
                    default:
                        return this.Cards.OrderByDescending(x => x.Value).First().Value.CompareTo(other.Cards.OrderByDescending(x => x.Value).First().Value);

                }
            }
        }

        public void Draw(Card card) => _cards.Add(card);
    }
}
