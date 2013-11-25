//
//  Player.cpp
//  proj4
//
//  Created by John West on 11/16/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Player.h"
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>

using namespace std;

/////////////////////////////////////////////////
//                Simple Player                //
/////////////////////////////////////////////////

class Simple : public Player {
public:

	virtual int bet(unsigned int bankroll, unsigned int minimum);
    // REQUIRES: bankroll >= minimum
    // EFFECTS: returns the player's bet, between minimum and bankroll
    // inclusive
	
    virtual bool draw(Card dealer, // Dealer's "up card"
                      const Hand &player // Player's current hand
                      );
    // EFFECTS: returns true if the player wishes to be dealt another
    // card, false otherwise.
	
    virtual void expose(Card c);
    // EFFECTS: allows the player to "see" the newly-exposed card c.
    // For example, each card that is dealt "face up" is expose()d.
    // Likewise, if the dealer must show his "hole card", it is also
    // expose()d.  Note: not all cards dealt are expose()d---if the
    // player goes over 21 or is dealt a natural 21, the dealer need
    // not expose his hole card.
	
    virtual void shuffled();
    // EFFECTS: tells the player that the deck has been re-shuffled.
	
//    virtual ~Simple() {}
//    // Note: this is here only to suppress a compiler warning.
//    //       Destructors are not needed for this project.
};

bool Simple::draw(Card dealer, const Hand &player)
{
//	unsigned int dealer_value = static_cast<int>(dealer.get_rank()) + 2;

	if (player.hand_is_soft())
	{
		if (player.hand_value() <= 17)
		{
			return true;
		}
		else if (player.hand_value() == 18)
		{
			if ((dealer.get_rank() == Card::TWO)
				or (dealer.get_rank() == Card::SEVEN)
				or (dealer.get_rank() == Card::EIGHT))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (player.hand_value() <= 11)
		{
			return true;
		}
		else if (player.hand_value() == 12)
		{
			if ((dealer.get_rank() == Card::FOUR)
				or (dealer.get_rank() == Card::FIVE)
				or (dealer.get_rank() == Card::SIX))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else if (player.hand_value() <= 16)
		{
			if ((dealer.get_rank() == Card::TWO)
				or (dealer.get_rank() == Card::THREE)
				or (dealer.get_rank() == Card::FOUR)
				or (dealer.get_rank() == Card::FIVE)
				or (dealer.get_rank() == Card::SIX))
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}

	// Should never reach this
//	return false;
}

int Simple::bet(unsigned int bankroll,
						unsigned int minimum)
{
	return minimum;
}

void Simple::expose(Card c)
{
	return;
}

void Simple::shuffled()
{
	return;
}

/////////////////////////////////////////////////
//               Counting Player               //
/////////////////////////////////////////////////

class Counting : public Simple {
public:
	Counting();

	virtual int bet(unsigned int bankroll, unsigned int minimum);
    // REQUIRES: bankroll >= minimum
    // EFFECTS: returns the player's bet, between minimum and bankroll
    // inclusive
	
//    virtual bool draw(Card dealer, // Dealer's "up card"
//                      const Hand &player // Player's current hand
//                      );
    // EFFECTS: returns true if the player wishes to be dealt another
    // card, false otherwise.
	
    virtual void expose(Card c);
    // EFFECTS: allows the player to "see" the newly-exposed card c.
    // For example, each card that is dealt "face up" is expose()d.
    // Likewise, if the dealer must show his "hole card", it is also
    // expose()d.  Note: not all cards dealt are expose()d---if the
    // player goes over 21 or is dealt a natural 21, the dealer need
    // not expose his hole card.
	
    virtual void shuffled();
    // EFFECTS: tells the player that the deck has been re-shuffled.
	
//    virtual ~Counting() {}
//    // Note: this is here only to suppress a compiler warning.
//    //       Destructors are not needed for this project.

private:
	int count;
};

Counting::Counting()
: count(0)
{
	assert(count == 0);
}

int Counting::bet(unsigned int bankroll, unsigned int minimum)
{
	if (count >= 2)
	{
		if (bankroll > 2 * minimum)
		{
			return 2 * minimum;
		}
		else
		{
			return bankroll;
		}
	}
	else
	{
		return minimum;
	}

	// should never get here
//	return minimum;
}

void Counting::expose(Card c)
{
	if (c.get_rank() >= Card::TEN)
	{
		count--;
	}
	else if (c.get_rank() <= Card::SIX)
	{
		count++;
	}
}

void Counting::shuffled()
{
	count = 0;

	return;
}


////////////////////////////////////////////////
//                 Competitor                 //
////////////////////////////////////////////////

class Competitor : public Simple {
public:
	Competitor();
	
	virtual int bet(unsigned int bankroll, unsigned int minimum);
    // REQUIRES: bankroll >= minimum
    // EFFECTS: returns the player's bet, between minimum and bankroll
    // inclusive
	
//    virtual bool draw(Card dealer, // Dealer's "up card"
//                      const Hand &player // Player's current hand
//                      );
    // EFFECTS: returns true if the player wishes to be dealt another
    // card, false otherwise.
	
    virtual void expose(Card c);
    // EFFECTS: allows the player to "see" the newly-exposed card c.
    // For example, each card that is dealt "face up" is expose()d.
    // Likewise, if the dealer must show his "hole card", it is also
    // expose()d.  Note: not all cards dealt are expose()d---if the
    // player goes over 21 or is dealt a natural 21, the dealer need
    // not expose his hole card.
	
    virtual void shuffled();
    // EFFECTS: tells the player that the deck has been re-shuffled.
	
	//    virtual ~Counting() {}
	//    // Note: this is here only to suppress a compiler warning.
	//    //       Destructors are not needed for this project.
	
private:
	int count;
	int ace_count;
};

Competitor::Competitor()
: count(0), ace_count(0)
{
	assert(count == 0);
	assert(ace_count == 0);
}

int Competitor::bet(unsigned int bankroll, unsigned int minimum)
{
	if (count < 2)
	{
		return minimum;
	}
	else if (count < 6)
	{
		if (minimum * 4 > bankroll)
		{
			return bankroll;
		}
		else
		{
			return minimum * 4;
		}
	}
	else if (count < 9)
	{
		if (minimum * 6 > bankroll)
		{
			return bankroll;
		}
		else
		{
			return minimum * 6;
		}
	}
	else if (count < 11)
	{
		if (minimum * 10 > bankroll)
		{
			return bankroll;
		}
		else
		{
			return minimum * 10;
		}
	}
	else
	{
		if (minimum * 20 > bankroll)
		{
			return bankroll;
		}
		else
		{
			if (ace_count == 4)
			{
				if (bankroll > 40 * minimum)
				{
					return minimum * 40;
				}
				else
				{
					return bankroll;
				}
			}
			else
			{
				return minimum * 20;
			}
		}
	}
}

void Competitor::expose(Card c)
{
	if (c.get_rank() <= Card::THREE)
	{
		count++;
	}
	else if (c.get_rank() <= Card::SIX)
	{
		count += 2;
	}
	else if (c.get_rank() == Card::SEVEN)
	{
		count++;
	}
	else if (c.get_rank() == Card::NINE)
	{
		count--;
	}
	else if ((c.get_rank() >= Card::TEN)
			 and  (c.get_rank() <= Card::KING))
	{
		count -= 2;
	}
	else if (c.get_rank() == Card::ACE)
	{
		ace_count++;
	}

	return;
}

void Competitor::shuffled()
{
	count = 0;
	ace_count = 0;

	return;
}

////////////////////////////////////////////////
//               Static Players               //
////////////////////////////////////////////////

static Simple simple;
static Counting counting;
static Competitor competitor;

////////////////////////////////////////////////
//               Player Factory               //
////////////////////////////////////////////////

Player* player_factory(const char * s)
{
	if (strcmp(s, "simple") == 0)
	{
		return &simple;
	}
	else if (strcmp(s, "counting") == 0)
	{
		return &counting;
	}
	else if (strcmp(s, "competitor") == 0)
	{
		return &competitor;
	}
	else
	{
		// Should never get here because of the Requires clause
		cout << "Player was not simple, counting, or competitor. Exit_Failure" << endl;
		exit(EXIT_FAILURE);
	}
}
