//
//  Deck_test08.cpp
//  proj4
//
//  Created by John West on 11/24/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Deck.h"
#include <cassert>

// Tests that after a shuffle() then reset(), the deck will deal out in the proper order

bool operator== (const Card &a, const Card &b);

int main()
{
	Deck d;
	Card c[52];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; i < 13; i++)
		{
			c[(i * 4) + j] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	d.shuffle(0);

	for (int i = 0; i < 25; i++)
	{
		assert(d.deal() == c[i + 25]);
		assert(d.deal() == c[i]);
	}

	assert(d.deal() == c[50]);
	assert(d.deal() == c[51]);

	return 0;
}
