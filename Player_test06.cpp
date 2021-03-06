//
//  Player_test06.cpp
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

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			card_array[(i * 5) + j] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

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
