//
//  Player_test16.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

// Test if player has hard 17+, he always stands

int main()
{
	Player *player = player_factory("counting");
	Hand player_hand;
	Card card_array[13];

	for (int i = 0; i < 13; i++)
	{
		card_array[i] = Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(3));
	}

	for (int i = 0; i < 5; i++)
	{
		player_hand.add_card(card_array[10]);
		player_hand.add_card(card_array[3]);
		player_hand.add_card(card_array[i]);

		assert(player_hand.hand_value() == (17 + i));

		for (int j = 0; j < 13; j++)
		{
			assert(player->draw(card_array[j], player_hand) == false);
		}

		player_hand.discard_all();
	}

	return 0;
}
