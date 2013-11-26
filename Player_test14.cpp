//
//  Player_test14.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

// Tests player stands if he has hard 12 and dealer has 4, 5, or 6

int main()
{
	Player *player = player_factory("counting");
	Hand player_hand;
	Card card_array[13];

	for (int i = 0; i < 13; i++)
	{
		card_array[i] = Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(3));
	}

	player_hand.add_card(card_array[2]);
	player_hand.add_card(card_array[6]);

	assert(player_hand.hand_value() == 12);

	for (int j = 0; j < 13; j++)
	{
		if ((j >= 2) and (j <= 4))
		{
			assert(player->draw(card_array[j], player_hand) == false);
		}
		else
		{
			assert(player->draw(card_array[j], player_hand) == true);
		}
	}

	return 0;
}
