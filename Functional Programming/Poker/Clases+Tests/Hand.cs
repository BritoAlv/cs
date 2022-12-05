namespace Poker
{
    public class Hand
    {
        private List<Card> _cards = new List<Card>();
        public IEnumerable<Card> Cards
        {
            get
            {
                return this._cards;
            }
        }
        public void Draw(Card card) => _cards.Add(card);
    }
}
