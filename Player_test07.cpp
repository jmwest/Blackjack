//
//  Player_test07.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

// Check that adding 7s, 8s, and 9s doesn't affect count. player bets minimum

int main()
{
	Player *player = player_factory("counting");
	Card card_array[12];
	Card two_clubs = Card(static_cast<Card::Rank>(0), static_cast<Card::Suit>(2));
	Card two_hearts = Card(static_cast<Card::Rank>(0), static_cast<Card::Suit>(1));

	for (int i = 0; i < 4; i++)
	{
		for (int j = 5; j < 8; j++)
		{
			card_array[(i * 3) + j - 5] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	for (int k = 0; k < 12; k++)
	{
		player->expose(card_array[k]);

		assert(player->bet(100, 25) == 25);
		assert(player->bet(100, 10) == 10);
		assert(player->bet(100, 5) == 5);
		assert(player->bet(100, 2) == 2);
		assert(player->bet(100, 0) == 0);
	}

	player->expose(two_clubs);
	player->expose(two_hearts);

	assert(player->bet(100, 25) == 50);
	assert(player->bet(100, 10) == 20);
	assert(player->bet(100, 5) == 10);
	assert(player->bet(100, 2) == 4);
	assert(player->bet(100, 0) == 0);

	return 0;
}
