//
//  Player_test02.cpp
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
	Card four_hearts = Card(static_cast<Card::Rank>(2), static_cast<Card::Suit>(1));

	player->expose(four_hearts);

	assert(player->bet(100, 50) == 50);
	assert(player->bet(100, 10) == 10);
	assert(player->bet(100, 5) == 5);
	assert(player->bet(100, 0) == 0);
	
	return 0;
}
