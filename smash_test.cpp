//
//  smash_test.cpp
//  proj4
//
//  Created by John West on 11/28/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

using namespace std;

int main()
{
	Player *player = player_factory("competitor");
	Deck deck;
	Hand player_hand;
	Card two_spades;

	cerr << "start:" << endl;
	cerr << &deck << endl;
	player->draw(two_spades, player_hand);

	return 0;
}
