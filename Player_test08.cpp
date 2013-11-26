//
//  Player_test08.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

// Check when count == 2, shuffled() makes player bet minimum

int main()
{
	Player *player = player_factory("counting");

	Card four_hearts = Card(static_cast<Card::Rank>(2), static_cast<Card::Suit>(1));
	Card six_diamonds = Card(static_cast<Card::Rank>(4), static_cast<Card::Suit>(3));

	player->expose(four_hearts);
	player->expose(six_diamonds);

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

	return 0;
}
