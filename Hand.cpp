//
//  Hand.cpp
//  proj4
//
//  Created by John West on 11/15/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include "Hand.h"
#include <cassert>

using namespace std;

// EFFECTS: Adds the value from c to the value passed in and returns it. Softness of hand is not considered
// REQUIRES: c is an initialized and valid Card
static int add_card_to_value(const int &value, const Card *c);

Hand::Hand()
: value(0), soft(false)
{
	assert(value == 0);
	assert(soft == false);
}
// EFFECTS: establishes an empty blackjack hand.

void Hand::discard_all()
{
	value = 0;
	soft = false;

	return;
}
// MODIFIES: this
// EFFECTS: discards any cards presently held, restoring the state
// of the hand to that of an empty blackjack hand.

void Hand::add_card(Card c)
{
	if (hand_is_soft())
	{
		if (add_card_to_value(value, &c) > 21)
		{
			if (c.get_rank() == Card::ACE)
			{
				if (value + 1 <= 21)
				{
					value = value + 1;
				}
				else
				{
					value = value - 9;
				}
			}
			else if ((c.get_rank() != Card::KING)
					 and (c.get_rank() != Card::QUEEN)
					 and (c.get_rank() != Card::JACK))
			{
				value = value + static_cast<int>(c.get_rank()) - 8;
			}

			soft = false;
		}
		else
		{
			value = add_card_to_value(value, &c);
		}

//		if (c.get_rank() == Card::ACE)
//		{
//			if (value >= 21)
//			{
//				value = value - 9;
//
//				soft = false;
//			}
//			else
//			{
//				value = value + 1;
//			}
//		}
//		else if ((c.get_rank() == Card::KING)
//				 or (c.get_rank() == Card::QUEEN)
//				 or (c.get_rank() == Card::JACK))
//		{
//			value = value + 10;
//		}
	}

	if ((c.get_rank() == Card::ACE) and (value > 11))
	{
		value = value + 1;
	}
	else
	{
		if (c.get_rank() == Card::ACE)
		{
			value = value + 11;

			soft = true;
		}
		else if ((c.get_rank() == Card::KING)
				 or (c.get_rank() == Card::QUEEN)
				 or (c.get_rank() == Card::JACK))
		{
			value = value + 10;
		}
		else
		{
			value = value + static_cast<int>(c.get_rank()) + 2;
		}
	}

	return;
}
// MODIFIES: this
// EFFECTS: adds the card "c" to those presently held.

int Hand::hand_value() const
{
	return value;
}
// EFFECTS: returns the present value of the blackjack hand, the
// highest blackjack total possible without going over 21

bool Hand::hand_is_soft() const
{
	return soft;
}
// EFFECTS: return true if and only if at least one ACE is present, and
// its value is counted as 11 rather than 1.

static int add_card_to_value(const int &value, const Card *c)
{
	int added_value;

	if (c->get_rank() == Card::ACE)
	{
		added_value = value + 11;
	}
	else if ((c->get_rank() == Card::KING)
			 or (c->get_rank() == Card::QUEEN)
			 or (c->get_rank() == Card::JACK))
	{
		added_value = value + 10;
	}
	else
	{
		added_value = value + static_cast<int>(c->get_rank()) + 2;
	}

	return added_value;
}