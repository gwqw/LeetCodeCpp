/**
Design the data structures for a generic deck of cards. 
Explain how you would subclass it to implement particular card games.

CardDeck has array of card

*/

class ICardDeck {
public:
    enum class Suit {buby, chervy, piki, cresti};
    struct Card {
        Suit mast;
        int nominal;
    };
    virtual void ShuffleDeck() = 0;
    virtual Card takeNextCard() = 0;
};

