//
//  Card.cpp
//  proj4
//
//  Created by John West on 11/11/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Card.h"

using namespace std;

const char *SUIT_NAMES[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
const char *RANK_NAMES[] = {"Two", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Jack",
    "Queen", "King", "Ace"};

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

//EFFECTS: Writes the Card to the stream
//  for example "Two of Spades"
std::ostream& operator<< (std::ostream& os, const Card& c)
{
	os << RANK_NAMES[c.get_rank()] << " of " << SUIT_NAMES[c.get_suit()];

	return os;
}