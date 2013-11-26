//
//  Player_test17.cpp
//  proj4
//
//  Created by John West on 11/25/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <cassert>

// Test player stands if he has hard 13 - 16 and dealer upcard is 2 - 6

int main()
{
	Player *player = player_factory("counting");
	Hand player_hand;
	Card card_array[13];

	for (int i = 0; i < 13; i++)
	{
		card_array[i] = Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(3));
	}

	for (int i = 0; i < 4; i++)
	{
		player_hand.add_card(card_array[4]);
		player_hand.add_card(card_array[5 + i]);

		assert(player_hand.hand_value() == (13 + i));

		for (int j = 0; j < 13; j++)
		{
			if (j <= 4)
			{
				assert(player->draw(card_array[j], player_hand) == false);
			}
			else
			{
				assert(player->draw(card_array[j], player_hand) == true);
			}
		}

		player_hand.discard_all();
	}
	
	return 0;
}
