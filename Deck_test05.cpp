//
//  Deck_test05.cpp
//  proj4
//
//  Created by John West on 11/24/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Deck.h"
#include <cassert>

// REQUIRES: a and b are initialized Cards
// EFFECTS: Function overload that compares the member variables, rank and suit, of each Card, and returns true if the values of the variables are equal. Otherwise returns false.
bool operator== (const Card &a, const Card &b);

int main()
{
	Deck d;

	d.shuffle(17);

	d.reset();

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
