// This is an example test case which runs a simple test involving
// your shuffle and deal functions.

#include "Deck.h"
#include "Card.h"
#include <cassert>
#include <iostream>
using namespace std;

bool operator== (const Card &a, const Card &b);

int main()
{
    Deck d;
	Card unshuffledD[52];
	Card shuffledD[52];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			unshuffledD[(13 * i) + j] = Card(static_cast<Card::Rank>(j), static_cast<Card::Suit>(i));
		}
	}

	Card delt;
	for (int m = 0; m < 4; m++)
	{
		for (int n = 0; n < 13; n++)
		{
			delt = d.deal();
			assert(delt == Card(static_cast<Card::Rank>(n), static_cast<Card::Suit>(m)));
			cout << delt << endl;
		}
	}

	d.reset();

    Card before = d.deal();
    d.shuffle(26); // Should replace the dealt card before shuffling

	cout << endl << "AS: " << endl;
	d.print();

	assert(d.cards_remaining() == 52);
    shuffledD[0] = d.deal();
	assert(d.cards_remaining() == 51);
    Card after = d.deal(); // Should be the same as before.
	assert(d.cards_remaining() == 50);

    cout << "First card in new deck: " << before << endl;
    cout << "Second card in shuffled deck: " << after << endl;

    assert(before.get_rank() == after.get_rank());
    assert(before.get_suit() == after.get_suit());

	cout << endl << shuffledD[0] << endl << after << endl;
	shuffledD[1] = after;
	for (int i = 2; i < 52; i++)
	{
		shuffledD[i] = d.deal();

		cout << shuffledD[i] << endl;
	}

	for (int i = 0; i < 26; i++)
	{
		assert(unshuffledD[i + 26] == shuffledD[i * 2]);
		assert(unshuffledD[i] == shuffledD[(i * 2) + 1]);
	}

    return 0;
}

bool operator== (const Card &a, const Card &b)
{
	return (a.get_rank() == b.get_rank()) && (a.get_suit() == b.get_suit());
}
