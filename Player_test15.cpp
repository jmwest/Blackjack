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

int main()
{
	Player *player = player_factory("counting");
	Hand player_hand;
	Card dealer_upcards[13];
	
	for (int i = 0; i < 13; i++)
	{
		dealer_upcards[i] = Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(i % 4));
	}
	
	assert(player->bet(100, 10) == 10);
	
	return 0;
}
