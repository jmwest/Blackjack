//
//  Card.cpp
//  proj4
//
//  Created by John West on 11/11/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"

using namespace std;

//EFFECTS: initializes Card to Two of Spades
Card::Card()
:rank(TWO), suit(SPADES) {}

//EFFECTS: initializes Card with rank_in and suit_in
Card::Card(Rank rank_in, Suit suit_in)
:rank(rank_in), suit(suit_in) {}

//EFFECTS: returns rank
Card::Rank Card::get_rank() const
{
	return rank;
}

//EFFECTS: returns suit
Card::Suit Card::get_suit() const
{
	return suit;
}