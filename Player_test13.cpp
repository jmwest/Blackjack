//
//  Player_test13.cpp
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
	Card card_array[12];
	Card dealer_upcard[13];

	for (int i = 0; i < 12; i++)
	{
		card_array[i] = Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(3));
		dealer_upcard[i] = Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(3));
	}

	dealer_upcard[12] = Card(static_cast<Card::Rank>(12), static_cast<Card::Suit>(3));

	for (int j = 0; j < 12; j++)
	{
		player_hand.add_card(card_array[j]);

		for (int k = 0; k < 13; k++)
		{
			assert(player->draw(dealer_upcard[k], player_hand) == true);
		}

		player_hand.discard_all();
	}

	player_hand.discard_all();
	player_hand.add_card(card_array[2]);
	player_hand.add_card(card_array[5]);

	for (int q = 0; q < 13; q++)
	{
		assert(player->draw(dealer_upcard[q], player_hand) == true);
	}

	return 0;
}
