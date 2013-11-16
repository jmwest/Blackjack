//
//  Deck_test00.1.cpp
//  proj4
//
//  Created by John West on 11/16/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Deck.h"
#include "Card.h"
#include "OperatorOverload.h"
#include <cassert>
#include <iostream>

using namespace std;

int main()
{
	Deck deck;

	cout << "Original: " << endl;
	deck.print();

	cout << endl << "Shuffled with 0: " << endl;
	deck.shuffle(0);
	deck.print();

	cout << endl << "Shuffled with 25: " << endl;
	deck.shuffle(25);
	deck.print();

	cout << endl << "Shuffled with 12: " << endl;
	deck.shuffle(12);
	deck.print();

	cout << endl << "Deck reset: " << endl;
	deck.reset();
	deck.print();

	cout << endl << "Shuffled with 52: " << endl;
	deck.shuffle(52);
	deck.print();

	cout << endl << "Shuffled with 30: " << endl;
	deck.shuffle(30);
	deck.print();
	
	cout << endl << "Shuffled with 0: " << endl;
	deck.shuffle(0);
	deck.print();

	return 0;
}
