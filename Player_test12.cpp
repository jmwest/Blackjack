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

// If bankroll < 2 * minimum, player bets bankroll

int main()
{
	Player *player = player_factory("counting");
	Card four_hearts = Card(static_cast<Card::Rank>(2), static_cast<Card::Suit>(1));
	Card six_diamonds = Card(static_cast<Card::Rank>(4), static_cast<Card::Suit>(3));

	player->expose(four_hearts);
	player->expose(six_diamonds);

	assert(player->bet(1000, 501) == 1000);
	assert(player->bet(30, 25) == 30);
	assert(player->bet(10, 10) == 10);
	assert(player->bet(9, 5) == 9);
	assert(player->bet(4, 2) == 4);
	assert(player->bet(0, 0) == 0);

	return 0;
}
