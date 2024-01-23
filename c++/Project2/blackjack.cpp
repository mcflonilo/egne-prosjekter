

#include <cstdint> 
#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iterator>
#include <utility>
#include <algorithm>
#include <array>
#include <numeric>
#include <vector>
#include <random>
#include <ctime>



enum class suit {
	diamond,
	spades,
	clubs,
	hearts,
};
enum class value {
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace,
};

struct card {
	suit suit{};
	value rank{};

};

void printcard(card x)
{
	switch (x.rank) {
	case value::two:	std::cout << '2' << "\n"; break;
	case value::three:	std::cout << '3' << "\n"; break;
	case value::four:	std::cout << '4' << "\n"; break;
	case value::five:	std::cout << '5' << "\n"; break;
	case value::six:	std::cout << '6' << "\n"; break;
	case value::seven:	std::cout << '7' << "\n"; break;
	case value::eight:	std::cout << '8' << "\n"; break;
	case value::nine:	std::cout << '9' << "\n"; break;
	case value::ten:	std::cout << 't' << "\n"; break;
	case value::jack:	std::cout << 'j' << "\n"; break;
	case value::queen:	std::cout << 'q' << "\n"; break;
	case value::king:	std::cout << 'k' << "\n"; break;
	case value::ace:	std::cout << 'a' << "\n"; break;
	default:			std::cout << '?' << "\n"; break;
	}
	switch (x.suit) {
	case suit::diamond:	std::cout << 'D'; break;
	case suit::hearts:	std::cout << 'H'; break;
	case suit::spades:	std::cout << 'S'; break;
	case suit::clubs:	std::cout << 'C'; break;
	default:			std::cout << '?'; break;
	}
}

void printdeck(std::array<card, 52> x)
{
	for (auto card : x) {
		printcard(card);
	}
}

std::array<card, 52> createdeck() {

	std::array<card, 52> deck;
	int index{ 0 };
	for (int b{ 0 }; b < 4; ++b) {
		for (int c{ 0 }; c < 13; ++c) {
			deck[index].suit = static_cast<suit>(b);
			deck[index].rank = static_cast<value>(c);
			++index;
		}

	}

	return deck;
}

void shuffledeck(std::array<card, 52>& deck) {

	static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
	std::shuffle(deck.begin(), deck.end(), mt);
}

int getcardvalue(card x)
{
	switch (x.rank) {
	case value::two:	return 2; break;
	case value::three:	return 3; break;
	case value::four:	return 4; break;
	case value::five:	return 5; break;
	case value::six:	return 6; break;
	case value::seven:	return 7; break;
	case value::eight:	return 8; break;
	case value::nine:	return 9; break;
	case value::ten:	return 10; break;
	case value::jack:	return 10; break;
	case value::queen:	return 10; break;
	case value::king:	return 10; break;
	case value::ace:	return 11; break;
	default:			return 0; break;
	}

}

bool playblackjack(std::array<card, 52> deck) {
	int cardspulled{ 0 };
	int dealerhand{ getcardvalue(deck[cardspulled]) };
	++cardspulled;
	int playerhand{ getcardvalue(deck[cardspulled]) + getcardvalue(deck[cardspulled + 1]) };
	++cardspulled;
	std::cout << "dealer has " << dealerhand << "\n";
	std::cout << "you have " << playerhand << "\n press y to hit, n to stand ";
	while (playerhand < 21) {

		char response{};
		std::cin >> response;
		if (response == 'y') {
			playerhand = playerhand + getcardvalue(deck[cardspulled]);
			++cardspulled;
			std::cout << "you have " << playerhand << "\n";
		}

		else if (response == 'n') {
			while (dealerhand < 17)
			{
				dealerhand = dealerhand + getcardvalue(deck[cardspulled]);
				++cardspulled;
				std::cout << "dealer has " << dealerhand << "\n";

			}

			if (dealerhand > 21)
				return true;
			else if (dealerhand > playerhand)
				return false;
			else if (dealerhand < playerhand)
				return true;
			else if (dealerhand == playerhand)
				std::cout << "tie";

		}
	}
	return false;
}

int main()
{

	auto deck{ createdeck() };
	shuffledeck(deck);
	if (playblackjack(deck))
		std::cout << "you win!!";
	else
		std::cout << "you lose :(";


	return 0;
}
