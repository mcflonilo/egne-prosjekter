/*

int g_maximumScore{ 21 };
int g_minimumDealerScore{ 11 };
class Player;
class Deck;
class Card {
public:

    enum Suit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };
    enum Rank
    {
        rank_2,
        rank_3,
        rank_4,
        rank_5,
        rank_6,
        rank_7,
        rank_8,
        rank_9,
        rank_10,
        rank_jack,
        rank_queen,
        rank_king,
        rank_ace,

        max_ranks
    };
private:
    Rank m_rank{};
    Suit m_suit{};

public:
    Card() = default;

    Card(Rank rank, Suit suit)
        : m_rank{ rank }, m_suit{ suit }
    {
    }
    void print() const
    {
        switch (m_rank)
        {
        case rank_2:      std::cout << '2';   break;
        case rank_3:      std::cout << '3';   break;
        case rank_4:      std::cout << '4';   break;
        case rank_5:      std::cout << '5';   break;
        case rank_6:      std::cout << '6';   break;
        case rank_7:      std::cout << '7';   break;
        case rank_8:      std::cout << '8';   break;
        case rank_9:      std::cout << '9';   break;
        case rank_10:     std::cout << 'T';   break;
        case rank_jack:   std::cout << 'J';   break;
        case rank_queen:  std::cout << 'Q';   break;
        case rank_king:   std::cout << 'K';   break;
        case rank_ace:    std::cout << 'A';   break;
        default:
            std::cout << '?';
            break;
        }
        switch (m_suit)
        {
        case club:          std::cout << 'C';   break;
        case diamond:       std::cout << 'D';   break;
        case heart:         std::cout << 'H';   break;
        case spade:         std::cout << 'S';   break;
        default:
            std::cout << '?';
            break;
        }
    }
    int  value() const
    {
        switch (m_rank)
        {
        case rank_2:        return 2;
        case rank_3:        return 3;
        case rank_4:        return 4;
        case rank_5:        return 5;
        case rank_6:        return 6;
        case rank_7:        return 7;
        case rank_8:        return 8;
        case rank_9:        return 9;
        case rank_10:       return 10;
        case rank_jack:     return 10;
        case rank_queen:    return 10;
        case rank_king:     return 10;
        case rank_ace:      return 11;
        default:
            assert(false && "should never happen");
            return 0;
        }
    }

    friend Deck;
};
bool playerTurn(Deck deck, Player player);
bool dealerTurn(Deck deck, Player dealer);
class Deck {
private:
    std::array<Card, 52> m_deck{};
    int m_cardIndex{ -1 };

public:

    Deck()
    {

        int index{ 0 };

        for (int Cardsuit{ 0 }; Cardsuit < static_cast<int>(Card::max_suits); ++Cardsuit)
        {
            for (int Cardrank{ 0 }; Cardrank < static_cast<int>(Card::max_ranks); ++Cardrank)
            {
                m_deck[index].m_suit = static_cast<Card::Suit>(Cardsuit);
                m_deck[index].m_rank = static_cast<Card::Rank>(Cardrank);
                ++index;
            }
        }

    }
    void print()
    {
        for (const auto& card : m_deck)
        {
            card.print();
        }
    }
    void shuffle()
    {
        static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

        std::shuffle(m_deck.begin(), m_deck.end(), mt);
        m_cardIndex = 0;
    }
    Card dealCard() {
        ++m_cardIndex;
        return m_deck[m_cardIndex];
    }
};

class Player {
private:
    int m_score{ 0 };
public:
    int drawCard(Deck deck) {
        m_score += deck.dealCard().value();
        return deck.dealCard().value();
    }
    int score() {
        return m_score;
    }
    bool isBust() {
        return m_score > 21;
    }
    friend bool playerTurn(Deck deck, Player player);
    friend bool dealerTurn(Deck deck, Player dealer);
    Player() = default;
    Player(int x) {
        m_score = x;
    }
};



bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}


bool playerTurn(Deck deck, Player player)
{
    while (true)
    {
        if (player.score() > g_maximumScore)
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                int cardValue{ deck.dealCard().value() };
                player.m_score += cardValue;
                std::cout << "You were dealt a " << cardValue << " and now have " << player.score() << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(Deck deck, Player dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.score() < g_minimumDealerScore)
    {
        int cardValue{ deck.dealCard().value() };
        dealer.m_score += cardValue;
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score() << '\n';

    }

    // If the dealer's score is too high, they went bust.
    if (dealer.score() > g_maximumScore)
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool playBlackjack(Deck deck)
{
    // Index of the card that will be drawn next. This cannot overrun
    // the array, because a player will lose before all cards are used up.

    // Create the dealer and give them 1 card.
    Player dealer{ deck.dealCard().value() };

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.score() << '\n';

    // Create the player and give them 2 cards.
    Player player{ deck.dealCard().value() + deck.dealCard().value() };

    std::cout << "You have: " << player.score() << '\n';

    if (playerTurn(deck, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.score() > dealer.score());
}

int main()
{
    Deck deck{};

    deck.shuffle();

    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}*/