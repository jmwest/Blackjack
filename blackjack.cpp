//
//  blackjack.cpp
//  proj4
//
//  Created by John West on 11/16/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include <cstring>
#include <cassert>
#include <iostream>

#include "rand.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

static const int MINIMUM_BET = 5;

// REQUIRES: deck_ptr is an initialized Deck
//			 player_ptr is an initialized Player
// MODIFIES: deck_ptr
//			 player_ptr
// EFFECTS: Shuffles the deck according to the spec.
//			Notifies the player that the deck is shuffled.
//			Uses rand.cpp to obtain a random cut value from 13 to 39 inclusive.
//			Shuffles the deck 7 times
static void shuffle_deck(Deck *deck_ptr, Player *player_ptr);

// REQUIRES: deck_ptr is an initialized Deck
//			 player_ptr is an initialized Player
//			 player_hand is an initialized Hand
//			 dealer_hand is an initialized Hand
// MODIFIES: deck_ptr
//			 player_ptr
//			 player_hand
//			 dealer_hand
// EFFECTS:
static void deal_initial_cards(Deck *deck_ptr, Player *player_ptr, Hand *player_hand, Hand *dealer_hand, Card *dealer_upcard_ptr);

//
static bool check_twenty_one(Hand *hand);

//
static void natural_twenty_one_payout(int &bankroll);

//
static void announce_player_card(const Card *card);

//
static void announce_dealer_card(const Card *card);

int main(int argc, char *argv[])
{
	assert(argc == 4);
	assert(strcmp(argv[0], "./blackjack") == 0);
	assert(atoi(argv[1]) >= 0);
	assert(atoi(argv[2]) >= 0);
	assert( (strcmp(argv[3], "simple") == 0)
		   or (strcmp(argv[3], "counting") == 0)
		   or (strcmp(argv[3], "competitor") == 0) );

	Player* player_ptr;
	Deck deck;
	Hand player_hand;
	Hand dealer_hand;
	Card dealer_upcard;
	int bankroll = atoi(argv[1]);
	int thishand = 1;
	int max_hands = atoi(argv[2]);
	int wager = 0;

	player_ptr = player_factory(argv[3]);

	shuffle_deck(&deck, player_ptr);

	while ((thishand <= max_hands) and (bankroll >= MINIMUM_BET))
	{
		cout << "Hand " << thishand << " bankroll " << bankroll << endl;

		if (deck.cards_remaining() < 20)
		{
			shuffle_deck(&deck, player_ptr);
		}

		wager = player_ptr->bet(bankroll, MINIMUM_BET);

		cout << "Player bets " << wager << endl;

		deal_initial_cards(&deck, player_ptr, &player_hand, &dealer_hand, &dealer_upcard);

		if (check_twenty_one(&player_hand))
		{
			natural_twenty_one_payout(bankroll);
		}
		else
		{
			bool player_stands = false;
			bool player_busts = false;

			while (player_stands == false)
			{
				if (player_ptr->draw(dealer_upcard, player_hand))
				{
					Card player_card;

					player_card = deck.deal();

					player_hand.add_card(player_card);
					player_ptr->expose(player_card);

					announce_player_card(&player_card);
				}
				else
				{
					player_stands = true;
				}

				if (player_hand.hand_value() > 21)
				{
					player_busts = true;
				}
			}
		}
	}

	return 0;
}

static void shuffle_deck(Deck *deck, Player *player_ptr)
{
	int cut;
	
	cout << "Shuffling the deck\n";

	for (int i = 0; i < 7; i++)
	{
		cut = get_cut();

		cout << "cut at " << cut << endl;

		deck->shuffle(cut);
	}

	player_ptr->shuffled();

	return;
}

static void deal_initial_cards(Deck *deck_ptr, Player *player_ptr, Hand *player_hand, Hand *dealer_hand, Card *dealer_upcard_ptr)
{
	Card player_cards[2];
	Card dealer_cards[2];

	player_cards[0] = deck_ptr->deal();
	player_hand->add_card(player_cards[0]);

	player_ptr->expose(player_cards[0]);

	announce_player_card(&player_cards[0]);

	dealer_cards[0] = deck_ptr->deal();
	dealer_hand->add_card(dealer_cards[0]);

	player_ptr->expose(dealer_cards[0]);

	announce_dealer_card(&dealer_cards[0]);

	player_cards[1] = deck_ptr->deal();
	player_hand->add_card(player_cards[1]);

	player_ptr->expose(player_cards[1]);

	announce_player_card(&player_cards[1]);

	dealer_cards[1] = deck_ptr->deal();
	dealer_hand->add_card(dealer_cards[1]);

	*dealer_upcard_ptr = dealer_cards[0];

	return;
}

static bool check_twenty_one(Hand *hand)
{
	return hand->hand_value() == 21;
}

static void natural_twenty_one_payout(int &bankroll)
{
	cout << "Player dealt natural 21\n";

	bankroll = (3 * bankroll) / 2;

	return;
}

static void announce_player_card(const Card *card)
{
	cout << "Player dealt " << *card << endl;

	return;
}

static void announce_dealer_card(const Card *card)
{
	cout << "Dealer dealt " << *card << endl;

	return;
}
