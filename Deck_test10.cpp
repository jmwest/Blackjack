//
//  Deck_test10.cpp
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
	Card c[52];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			c[(i * 13) + j] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	d.shuffle(25);

	for (int i = 0; i < 25; i++)
	{
		assert(d.deal() == c[i + 25]);
		assert(d.deal() == c[i]);
	}

	assert(d.deal() == c[50]);
	assert(d.deal() == c[51]);

	return 0;
}

bool operator== (const Card &a, const Card &b)
{
	return (a.get_rank() == b.get_rank()) && (a.get_suit() == b.get_suit());
}
