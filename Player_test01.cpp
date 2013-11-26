//
//  Player_test01.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

// Check when count == 0, player bets minimum

int main()
{
	Player *player = player_factory("counting");

	assert(player->bet(100, 50) == 50);
	assert(player->bet(100, 10) == 10);
	assert(player->bet(100, 5) == 5);
	assert(player->bet(100, 0) == 0);

	return 0;
}