//
//  Player_test20.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

// Test player hits or stands with random multiple ace combinations

int main()
{
	Player *player = player_factory("counting");
	Hand player_hand;
	Card card_array[13];

	for (int i = 0; i < 13; i++)
	{
		card_array[i] = Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(3));
	}

	for (int p = 0; p < 4; p++)
	{
		player_hand.add_card(card_array[12]);

		assert(player_hand.hand_is_soft() == true);
		assert(player_hand.hand_value() == 11 + p);

		for (int q = 0; q < 13; q++)
		{
			assert(player->draw(card_array[q], player_hand) == true);
		}
	}

	player_hand.add_card(card_array[11]);

	assert(player_hand.hand_value() == 14);
	assert(player_hand.hand_is_soft() == false);

	for (int a = 0; a < 13; a++)
	{
		if (a <= 4)
		{
			assert(player->draw(card_array[a], player_hand) == false);
		}
		else
		{
			assert(player->draw(card_array[a], player_hand) == true);
		}
	}

	player_hand.discard_all();

	return 0;
}
