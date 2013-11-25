//
//  Deck_test06.cpp
//  proj4
//
//  Created by John West on 11/24/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Deck.h"
#include <cassert>

// Tests that after a deal() then shuffle(), the deck has the proper number of cards remaining

int main()
{
	Deck d;

	assert(d.cards_remaining() == 52);

	for (int i = 51; i >= 0; i--)
	{
		d.deal();

		assert(d.cards_remaining() == i);
	}

	d.shuffle(17);

	assert(d.cards_remaining() == 52);
	
	return 0;
}
