//
//  Player_test09.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

// Check when count >= 3, player bets 2 * minimum

int main()
{
	Player *player = player_factory("counting");
	Card card_array[20];

	Card four_hearts = Card(static_cast<Card::Rank>(2), static_cast<Card::Suit>(1));
	Card six_diamonds = Card(static_cast<Card::Rank>(4), static_cast<Card::Suit>(3));
	Card two_clubs = Card(static_cast<Card::Rank>(0), static_cast<Card::Suit>(2));

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			card_array[(i * 5) + j] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	player->expose(four_hearts);
	player->expose(six_diamonds);
	player->expose(two_clubs);

	assert(player->bet(100, 25) == 50);
	assert(player->bet(100, 10) == 20);
	assert(player->bet(100, 5) == 10);
	assert(player->bet(100, 2) == 4);
	assert(player->bet(100, 0) == 0);

	player->shuffled();

	assert(player->bet(100, 25) == 25);
	assert(player->bet(100, 10) == 10);
	assert(player->bet(100, 5) == 5);
	assert(player->bet(100, 2) == 2);
	assert(player->bet(100, 0) == 0);

	player->expose(card_array[0]);
	player->expose(card_array[1]);
	player->expose(card_array[2]);

	for (int k = 3; k < 20; k++)
	{
		player->expose(card_array[k]);

		assert(player->bet(100, 25) == 50);
		assert(player->bet(100, 10) == 20);
		assert(player->bet(100, 5) == 10);
		assert(player->bet(100, 2) == 4);
		assert(player->bet(100, 0) == 0);
	}

	return 0;
}
