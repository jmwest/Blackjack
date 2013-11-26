//
//  Player_test05.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

// Tests that each individual card will add to the count in its designated way

int main()
{
	Player *player = player_factory("counting");
	Card card_array[13];
	
	for (int j = 0; j < 13; j++)
	{
		card_array[j] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(3));
	}

	assert(player->bet(100, 25) == 25);
	assert(player->bet(100, 10) == 10);
	assert(player->bet(100, 5) == 5);
	assert(player->bet(100, 2) == 2);
	assert(player->bet(100, 0) == 0);

	for (int i = 0; i < 13; i++)
	{
		player->shuffled();

		assert(player->bet(100, 25) == 25);
		assert(player->bet(100, 10) == 10);
		assert(player->bet(100, 5) == 5);
		assert(player->bet(100, 2) == 2);
		assert(player->bet(100, 0) == 0);

		if (i < 5)
		{
			player->expose(card_array[i]);
			player->expose(card_array[i]);

			assert(player->bet(100, 25) == 50);
			assert(player->bet(100, 10) == 20);
			assert(player->bet(100, 5) == 10);
			assert(player->bet(100, 2) == 4);
			assert(player->bet(100, 0) == 0);
		}
		else if (i < 8)
		{
			player->expose(card_array[i]);
			player->expose(card_array[i]);

			assert(player->bet(100, 25) == 25);
			assert(player->bet(100, 10) == 10);
			assert(player->bet(100, 5) == 5);
			assert(player->bet(100, 2) == 2);
			assert(player->bet(100, 0) == 0);
		}
		else
		{
			player->expose(card_array[i]);
			player->expose(card_array[i]);

			assert(player->bet(100, 25) == 25);
			assert(player->bet(100, 10) == 10);
			assert(player->bet(100, 5) == 5);
			assert(player->bet(100, 2) == 2);
			assert(player->bet(100, 0) == 0);
		}
	}

	return 0;
}
