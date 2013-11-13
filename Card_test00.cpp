#include "Card.h"
#include <cassert>
#include <iostream>

using namespace std;

Card::Suit SUIT_ENUM_TEST_ARRAY[] = {Card::SPADES, Card::HEARTS, Card::CLUBS, Card::DIAMONDS};
Card::Rank RANK_ENUM_TEST_ARRAY[] = {Card::TWO, Card::THREE, Card::FOUR, Card::FIVE, Card::SIX, Card::SEVEN, Card::EIGHT, Card::NINE, Card::TEN, Card::JACK, Card::QUEEN, Card::KING, Card::ACE};

int main()
{
	
	Card c1;
	assert(c1.get_rank() == Card::TWO);
	assert(c1.get_suit() == Card::SPADES);
	cout << c1 << endl;
  
	Card c2(Card::FIVE, Card::HEARTS);
	assert(c2.get_rank() == Card::FIVE);
	assert(c2.get_suit() == Card::HEARTS);
	cout << c2 << endl << endl;

	Card deck[52];
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck[(13 * i) + j] = Card(RANK_ENUM_TEST_ARRAY[j], SUIT_ENUM_TEST_ARRAY[i]);
		}
	}
	
	for (int k = 0; k < 4; k++)
	{
		for (int m = 0; m < 13; m++)
		{
			assert(deck[(13 * k) + m].get_rank() == RANK_ENUM_TEST_ARRAY[m] && deck[(13 * k) + m].get_suit() == SUIT_ENUM_TEST_ARRAY[k]);
		}
	}

	for (int l = 0; l < 52; l++)
	{
		cout << deck[l] << endl;
	}
}
