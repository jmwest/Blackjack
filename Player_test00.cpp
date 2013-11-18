//Player_test00.cpp
//
//put your first Player test here

#include "Hand.h"
#include "OperatorOverload.h"
#include "Player.h"

#include <cassert>

using namespace std;

int main(int argc, char *argv[])
{
	assert(argc == 2);

	Hand player_hand;
	Card dealer_card_up;
	Card dealer_card_array[13];

	for (int i = 0; i < 13; i++)
	{
		dealer_card_array[i] = Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(i % 4));
	}

	for (int i = 0; i < 13; i++)
	{
		assert(dealer_card_array[i] == Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(i % 4)));
	}

	//////////////////
	// Player tests //
	//////////////////

	assert((strcmp(argv[1], "simple") == 0)
		   or (strcmp(argv[1], "counting") == 0)
		   or (strcmp(argv[1], "competitor") == 0) );

	Player *player = player_factory(argv[1]);
	
//	assert(player == &simple);

	////////////
	// bet tests

	int wager = 0;

	wager = player->bet(100, 10);
	assert(wager == 10);

	for (int i = 0; i < 100; i++)
	{
		wager = player->bet(i + 10, i);
		assert(wager == i);
	}

	wager = player->bet(1000, 1000);
	assert(wager == 1000);

	/////////////
	// draw tests

	// hard
	///////

	dealer_card_up = Card(Card::EIGHT, Card::HEARTS);
	player_hand.add_card(Card(Card::THREE, Card::HEARTS));
	player_hand.add_card(Card(Card::SIX, Card::HEARTS));

	assert(player->draw(dealer_card_up, player_hand) == true);

	player_hand.add_card(Card(Card::TWO, Card::DIAMONDS));

	assert(player->draw(dealer_card_up, player_hand) == true);

	player_hand.add_card(Card(Card::ACE, Card::DIAMONDS));

	assert(player->draw(dealer_card_up, player_hand) == true);
	assert(player_hand.hand_is_soft() == false);

	player_hand.add_card(Card(Card::ACE, Card::SPADES));

	assert(player->draw(dealer_card_up, player_hand) == true);
	assert(player_hand.hand_is_soft() == false);

	player_hand.add_card(Card(Card::FIVE, Card::SPADES));

	assert(player->draw(dealer_card_up, player_hand) == false);

	// new hand
	for (int j = 0; j < 13; j++)
	{
		player_hand.discard_all();
		dealer_card_up = dealer_card_array[j];

		player_hand.add_card(Card(Card::FOUR, Card::HEARTS));
		player_hand.add_card(Card(Card::FOUR, Card::SPADES));

		assert(player->draw(dealer_card_up, player_hand) == true);

		player_hand.add_card(Card(Card::THREE, Card::DIAMONDS));

		assert(player->draw(dealer_card_up, player_hand) == true);

		player_hand.add_card(Card(Card::ACE, Card::DIAMONDS));

		if ((j < 2) or (j > 4))
		{
			assert(player->draw(dealer_card_up, player_hand) == true);
		}
		else
		{
			assert(player->draw(dealer_card_up, player_hand) == false);
		}
	}

	// new hand
	Card last_player_card_array[4];

	for (int x = 0; x < 4; x++)
	{
		last_player_card_array[x] = Card(static_cast<Card::Rank>(x), static_cast<Card::Suit>(x));
	}

	for (int k = 0; k < 13; k++)
	{
		for (int m = 0; m < 4; m++)
		{
			player_hand.discard_all();
			dealer_card_up = dealer_card_array[k];
			
			player_hand.add_card(Card(Card::TWO, Card::HEARTS));
			player_hand.add_card(Card(Card::FIVE, Card::SPADES));
			
			assert(player->draw(dealer_card_up, player_hand) == true);
			
			player_hand.add_card(Card(Card::FOUR, Card::DIAMONDS));
			
			assert(player->draw(dealer_card_up, player_hand) == true);
			
			player_hand.add_card(last_player_card_array[m]);

			if (k < 5)
			{
				assert(player->draw(dealer_card_up, player_hand) == false);
			}
			else
			{
				assert(player->draw(dealer_card_up, player_hand) == true);
			}
		}
	}

	// new hand
	Card player_cards[5];
	for (int y = 0; y < 5; y++)
	{
		player_cards[y] = Card(static_cast<Card::Rank>(y), static_cast<Card::Suit>(y % 4));
	}

	for (int z = 0; z < 5; z++)
	{
		assert(player_cards[z] == Card(static_cast<Card::Rank>(z), static_cast<Card::Suit>(z % 4)));
	}

	for (int p = 0; p < 52; p++)
	{
		for (int q = 0; q < 5; q++)
		{
			player_hand.discard_all();
			dealer_card_up = Card(static_cast<Card::Rank>(p % 13), static_cast<Card::Suit>(p / 13));
			
			player_hand.add_card(Card(Card::JACK, Card::HEARTS));
			player_hand.add_card(Card(Card::FIVE, Card::DIAMONDS));
			player_hand.add_card(player_cards[q]);
			
			assert(player->draw(dealer_card_up, player_hand) == false);
		}
	}

	// soft
	///////

	Card first_card_array[20];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			first_card_array[(i * 5) + j] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	// < 17
	for (int k = 0; k < 20; k++)
	{
		player_hand.discard_all();
		dealer_card_up = Card(static_cast<Card::Rank>(k % 13), static_cast<Card::Suit>(k % 4));
		
		player_hand.add_card(first_card_array[k]);
		player_hand.add_card(Card(Card::ACE, Card::DIAMONDS));
		
		assert(player->draw(dealer_card_up, player_hand) == true);
	}

	// == 18
	for (int x = 0; x < 13; x++)
	{
		player_hand.discard_all();
		dealer_card_up = Card(static_cast<Card::Rank>(x), static_cast<Card::Suit>(x / 4));
		
		player_hand.add_card(Card(Card::ACE, Card::SPADES));
		player_hand.add_card(Card(Card::SEVEN, Card::DIAMONDS));

		if ((x == 0) or (x == 5) or (x == 6))
		{
			assert(player->draw(dealer_card_up, player_hand) == false);
		}
		else
		{
			assert(player->draw(dealer_card_up, player_hand) == true);
		}
	}

	// > 19
	for (int y = 0; y < 52; y++)
	{
		for (int z = 0; z < 3; z++)
		{
			player_hand.discard_all();
			dealer_card_up = Card(static_cast<Card::Rank>(y % 13), static_cast<Card::Suit>(y / 13));
			
			player_hand.add_card(Card(Card::ACE, Card::SPADES));
			player_hand.add_card(Card(Card::SIX, Card::DIAMONDS));
			player_hand.add_card(Card(static_cast<Card::Rank>(z), static_cast<Card::Suit>(z)));

			assert(player->draw(dealer_card_up, player_hand) == false);
		}
	}

	///////////////
	// expose tests

	if (strcmp(argv[1], "simple") == 0)
	{
		return 0;
	}

	////////////////////////////////////
	// bet tests - Counting & Competitor

	

	return 0;
}
