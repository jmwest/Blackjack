//
//  Deck.cpp
//  proj4
//
//  Created by John West on 11/12/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Deck.h"
#include "Card.h"

using namespace std;

Deck::Deck()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck[(i * 13) + j] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	next = deck;
}
// EFFECTS: constructs a "newly opened" deck of cards.  first the
// spades from 2-A, then the hearts, then the clubs, then the
// diamonds.  The first card dealt should be the 2 of Spades.

void Deck::print()
{
	for (int i = 0; i < DECK_SIZE; i++)
	{
		cout << deck[i] << endl;
	}
}
void Deck::reset()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			deck[(i * 13) + j] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	next = deck;

	return;
}
// MODIFIES: this

// EFFECTS: resets the deck to the state of a "newly opened" deck
// of cards:

void Deck::shuffle(int n)
{
	next = deck;

	Card left[DECK_SIZE];
//	Card right[DECK_SIZE];

	int lesser = 0;

//	cout << endl << "left: " << endl;
	for (int i = 0; i < DECK_SIZE; i++)
	{
		left[i] = deck[i];
//		cout << left[i] << endl;
	}

//	cout << endl << "right: " << endl;
//	for (int j = n; j < DECK_SIZE; j++)
//	{
//		right[j] = Card(deck[j].get_rank(), deck[j].get_suit());
//		cout << deck[j] << endl;
//	}

//	right[0] = deck[n];
//	right[1] = deck[n + 1];
//	right[2] = deck[n + 2];
//	right[3] = deck[n + 3];
//	right[4] = deck[n + 4];
//	right[5] = deck[n + 5];
//	right[6] = deck[n + 6];
//	right[7] = deck[n + 7];
//	right[8] = deck[n + 8];
//	right[9] = deck[n + 9];
//	right[10] = deck[n + 10];
//	right[11] = deck[n + 11];
//	right[12] = deck[n + 12];
//	right[13] = deck[n + 13];
//	right[14] = deck[n + 14];
//	right[15] = deck[n + 15];
//	right[16] = deck[n + 16];
//	right[17] = deck[n + 17];
//	right[18] = deck[n + 18];
//	right[19] = deck[n + 19];
//	right[20] = deck[n + 20];
//	right[21] = deck[n + 21];
//	right[22] = deck[n + 22];
//	right[23] = deck[n + 23];
//	right[24] = deck[n + 24];
//	right[25] = deck[n + 25];

	if (n < DECK_SIZE - n)
	{
		lesser = n;
	}
	else
	{
		lesser = DECK_SIZE - n;
	}

//	cout << endl << "RIGHT: " << endl;
//	for (int x = 0; x < DECK_SIZE - n; x++) {
//		cout << right[x] << " " << x << endl;
//	}

//	cout << endl << "deck: " << endl;
	for (int k = 0; k < 2 * lesser; k++)
	{
		if (k % 2 == 0)
		{
			deck[k] = left[n + (k / 2)];
//			cout << "fr: " << left[n + (k / 2)] << endl;
		}
		else
		{
			deck[k] = left[k / 2];
//			cout << "fl: " << left[k / 2] << endl;
		}

//		cout << deck[k] << endl;
	}

	if (n < DECK_SIZE - n)
	{
		for (int l = 2 * n; l < DECK_SIZE; l++)
		{
			deck[l] = left[l];
		}
	}
	else if (n > DECK_SIZE - n)
	{
		for (int l = DECK_SIZE - n; l < (2 * n) - DECK_SIZE; l++)
		{
			deck[l] = left[l];
		}
	}

	return;
}
// REQUIRES: n is between 0 and 52, inclusive.

// MODIFIES: this

// EFFECTS: cut the deck into two segments: the first n cards,
// called the "left", and the rest called the "right".  Note that
// either right or left might be empty.  Then, rearrange the deck
// to be the first card of the right, then the first card of the
// left, the 2nd of right, the 2nd of left, and so on.  Once one
// side is exhausted, fill in the remainder of the deck with the
// cards remaining in the other side.  Finally, make the first
// card in this shuffled deck the next card to deal.  For example,
// shuffle(26) on a newly-reset() deck results in: 2-clubs,
// 2-spades, 3-clubs, 3-spades ... A-diamonds, A-hearts.
//
// Note: if shuffle is called on a deck that has already had some
// cards dealt, those cards should first be restored to the deck
// in the order in which they were dealt, preserving the most
// recent post-shuffled/post-reset state.
// This function produces no output.

Card Deck::deal()
{
	Card card(next->get_rank(), next->get_suit());

	next++;

	return card;
}
// REQUIRES: deck is not empty
// MODIFIES: this
// EFFECTS: returns the next card to be dealt.


int Deck::cards_remaining() const
{
	int remaining = 0;

	remaining = 52 - (int)(next - deck);

	return remaining;
}
// EFFECTS: returns the number of cards in the deck that have not
// been dealt since the last reset/shuffle.