//
//  Player_test10.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

int main()
{
	Player *player = player_factory("counting");
	Card card_array[20];
	Card four_spades = Card(static_cast<Card::Rank>(2), static_cast<Card::Suit>(0));

	for (int i = 0; i < 4; i++)
	{
		for (int j = 8; j < 13; j++)
		{
			card_array[(i * 5) + j - 8] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	assert(player->bet(100, 25) == 25);
	assert(player->bet(100, 10) == 10);
	assert(player->bet(100, 5) == 5);
	assert(player->bet(100, 2) == 2);
	assert(player->bet(100, 0) == 0);

	player->shuffled();

	assert(player->bet(100, 25) == 25);
	assert(player->bet(100, 10) == 10);
	assert(player->bet(100, 5) == 5);
	assert(player->bet(100, 2) == 2);
	assert(player->bet(100, 0) == 0);

	player->expose(four_spades);

	assert(player->bet(100, 25) == 25);
	assert(player->bet(100, 10) == 10);
	assert(player->bet(100, 5) == 5);
	assert(player->bet(100, 2) == 2);
	assert(player->bet(100, 0) == 0);

	player->shuffled();

	assert(player->bet(100, 25) == 25);
	assert(player->bet(100, 10) == 10);
	assert(player->bet(100, 5) == 5);
	assert(player->bet(100, 2) == 2);
	assert(player->bet(100, 0) == 0);

	for (int k = 0; k < 20; k++)
	{
		for (int q = 0; q < k; q++)
		{
			player->expose(card_array[q]);
		}

		assert(player->bet(100, 25) == 25);
		assert(player->bet(100, 10) == 10);
		assert(player->bet(100, 5) == 5);
		assert(player->bet(100, 2) == 2);
		assert(player->bet(100, 0) == 0);

		player->shuffled();

		assert(player->bet(100, 25) == 25);
		assert(player->bet(100, 10) == 10);
		assert(player->bet(100, 5) == 5);
		assert(player->bet(100, 2) == 2);
		assert(player->bet(100, 0) == 0);
	}

	return 0;
}
