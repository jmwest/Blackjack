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

int main()
{
	Player *player = player_factory("counting");
	Hand player_hand;
	Card card_array[13];

	for (int i = 0; i < 13; i++)
	{
		card_array[i] = Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(3));
	}

	player_hand.add_card(card_array[12]);
	
	assert(player_hand.hand_is_soft() == true);
	assert(player_hand.hand_value() == 11);

	for (int a = 0; a < 13; a++)
	{
		assert(player->draw(card_array[a], player_hand) == true);
	}

	player_hand.discard_all();

	for (int i = 0; i < 5; i++)
	{
		player_hand.add_card(card_array[12]);
		player_hand.add_card(card_array[i]);

		assert(player_hand.hand_is_soft() == true);
		assert(player_hand.hand_value() == (13 + i));

		for (int j = 0; j < 13; j++)
		{
			assert(player->draw(card_array[j], player_hand) == true);
		}

		player_hand.discard_all();
	}

	return 0;
}
