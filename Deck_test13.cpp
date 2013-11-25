//
//  Deck_test12.cpp
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
		for (int j = 0; j < 13; j++)
		{
			c[(i * 13) + j] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	d.shuffle(33);

	for (int i = 0; i < 19; i++)
	{
		assert(d.deal() == c[i + 33]);
		assert(d.deal() == c[i]);
	}

	for (int j = 19; j < 33; j++)
	{
		assert(d.deal() == c[j]);
	}

	return 0;
}

bool operator== (const Card &a, const Card &b)
{
	return (a.get_rank() == b.get_rank()) && (a.get_suit() == b.get_suit());
}
