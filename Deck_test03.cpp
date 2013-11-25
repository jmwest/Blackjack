//
//  Deck_test03.cpp
//  proj4
//
//  Created by John West on 11/24/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Deck.h"
#include <cassert>

// Tests that after a reset(), the deck again has 52 cards remaining

int main()
{
	Deck d;

	for (int i = 51; i >= 0; i--)
	{
		d.deal();
	}

	d.reset();

	assert(d.cards_remaining() == 52);

	return 0;
}
