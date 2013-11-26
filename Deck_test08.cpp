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

// Tests that after a shuffle(52) the deck will deal out in the proper order

bool operator== (const Card &a, const Card &b);

int main()
{
	Deck d;

	d.shuffle(52);

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
