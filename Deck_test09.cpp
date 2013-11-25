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
#include <iostream>
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

	d.shuffle(26);

	for (int i = 0; i < 26; i++)
	{
		assert(d.deal() == c[i + 26]);
		assert(d.deal() == c[i]);
	}

	return 0;
}

bool operator== (const Card &a, const Card &b)
{
	return (a.get_rank() == b.get_rank()) && (a.get_suit() == b.get_suit());
}
