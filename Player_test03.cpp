//
//  Player_test03.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

// Check when count < 0, player bets minimum

int main()
{
	Player *player = player_factory("counting");
	Card card_array[20];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 8; j < 13; j++)
		{
			card_array[(i * 5) + j - 8] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	for (int k = 0; k < 20; k++)
	{
		player->expose(card_array[k]);

		assert(player->bet(100, 50) == 50);
		assert(player->bet(100, 10) == 10);
		assert(player->bet(100, 5) == 5);
		assert(player->bet(100, 0) == 0);
	}

	return 0;
}
