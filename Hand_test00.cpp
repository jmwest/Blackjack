//
//  Hand_test00.cpp
//  proj4
//
//  Created by John West on 11/15/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Hand.h"
#include <cassert>

using namespace std;

int main()
{
	Hand hand;
	cout << hand.hand_value() << endl;

	hand.add_card(Card());
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 2);
	assert(hand.hand_is_soft() == false);

	hand.add_card(Card(Card::SEVEN, Card::DIAMONDS));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 9);
	assert(hand.hand_is_soft() == false);

	hand.add_card(Card(Card::ACE, Card::SPADES));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 20);
	assert(hand.hand_is_soft() == true);

	hand.add_card(Card(Card::ACE, Card::HEARTS));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 21);
	assert(hand.hand_is_soft() == true);

	hand.add_card(Card(Card::THREE, Card::CLUBS));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 14);
	assert(hand.hand_is_soft() == false);

	hand.add_card(Card(Card::SEVEN, Card::DIAMONDS));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 21);
	assert(hand.hand_is_soft() == false);

	hand.discard_all();
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 0);
	assert(hand.hand_is_soft() == false);

	// New hand

	hand.add_card(Card(Card::KING, Card::DIAMONDS));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 10);
	assert(hand.hand_is_soft() == false);

	hand.add_card(Card(Card::JACK, Card::DIAMONDS));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 20);
	assert(hand.hand_is_soft() == false);

	hand.discard_all();
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 0);
	assert(hand.hand_is_soft() == false);

	// New hand

	hand.add_card(Card(Card::QUEEN, Card::DIAMONDS));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 10);
	assert(hand.hand_is_soft() == false);

	hand.add_card(Card(Card::SEVEN, Card::DIAMONDS));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 17);
	assert(hand.hand_is_soft() == false);

	hand.add_card(Card(Card::ACE, Card::DIAMONDS));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 18);
	assert(hand.hand_is_soft() == false);

	hand.add_card(Card(Card::SEVEN, Card::DIAMONDS));
	cout << hand.hand_value() << endl;

	assert(hand.hand_value() == 25);
	assert(hand.hand_is_soft() == false);

	return 0;
}