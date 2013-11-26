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

int main()
{
	Deck d;

	for (int i = 51; i >= 0; i--)
	{
		d.deal();
	}

	assert(d.cards_remaining() == 0);

	d.reset();

	assert(d.cards_remaining() == 52);

	return 0;
}
