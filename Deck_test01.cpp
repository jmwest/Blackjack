//
//  Deck_test01.cpp
//  proj4
//
//  Created by John West on 11/24/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Deck.h"
#include <cassert>

// Tests that an initialized Deck initializes with the correct card order. Relies upon deal() working correctly. If deal doesn't work right, it would also catch that.

bool operator== (const Card &a, const Card &b);

int main()
{
	Deck d;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			assert(d.deal() == Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i)));
		}
	}

	return 0;
}

bool operator== (const Card &a, const Card &b)
{
	return (a.get_rank() == b.get_rank()) && (a.get_suit() == b.get_suit());
}
