//
//  blackjack.cpp
//  proj4
//
//  Created by John West on 11/16/13.
//  Copyright (c) 2013 John West. All rights reserved.
//

#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>

#include "rand.h"
#include "Card.h"
#include "Hand.h"
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
static void deal_initial_cards(Deck *deck_ptr, Player *player_ptr, Hand *player_hand, Hand *dealer_hand, Card dealer_upcard_ptr[]);

//
static bool check_twenty_one(Hand *hand);

//
static void natural_twenty_one_payout(int &bankroll, const int &wager);

//
static void announce_player_card(const Card *card);

//
static void announce_dealer_card(const Card *card);

//
static void announce_dealer_hole_card(const Card *card);

//
static void announce_player_total(const Hand *player_hand);

//
static void announce_dealer_total(const Hand *dealer_hand);

//
static void announce_player_busts();

//
static void announce_dealer_busts();

//
static void announce_player_wins();

//
static void announce_dealer_wins();

//
static void player_lost_hand(int &bankroll, const int &wager, Hand *player_hand, Hand *dealer_hand);

//
static void player_won_hand(int &bankroll, const int &wager, Hand *player_hand, Hand *dealer_hand);

//
static void hand_is_push(Hand *player_hand, Hand *dealer_hand);

//
static void play_dealers_hand(Hand *dealer_hand, const Card dealer_cards[], Player *player_ptr, Deck *deck);

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
	Card dealer_cards[2];
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

		deal_initial_cards(&deck, player_ptr, &player_hand, &dealer_hand, dealer_cards);

		if (check_twenty_one(&player_hand))
		{
			natural_twenty_one_payout(bankroll, wager);

			player_hand.discard_all();
			dealer_hand.discard_all();
		}
		else
		{
			bool player_stands = false;
			bool player_busts = false;

			while (!player_stands && !player_busts)
			{
				if (player_ptr->draw(dealer_cards[0], player_hand))
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

			announce_player_total(&player_hand);

			if (player_busts)
			{
				player_lost_hand(bankroll, wager, &player_hand, &dealer_hand);
				announce_player_busts();
			}
			else
			{
				play_dealers_hand(&dealer_hand, dealer_cards, player_ptr, &deck);

				announce_dealer_total(&dealer_hand);

				if (dealer_hand.hand_value() > 21)
				{
					player_won_hand(bankroll, wager, &player_hand, &dealer_hand);
					announce_dealer_busts();
				}
				else
				{
					if (player_hand.hand_value() > dealer_hand.hand_value())
					{
						player_won_hand(bankroll, wager, &player_hand, &dealer_hand);
						announce_player_wins();
					}
					else if (player_hand.hand_value() < dealer_hand.hand_value())
					{
						player_lost_hand(bankroll, wager, &player_hand, &dealer_hand);
						announce_dealer_wins();
					}
					else
					{
						hand_is_push(&player_hand, &dealer_hand);
					}
				}
			}
		}

		thishand++;
	}

	cout << "Player has " << bankroll << " after "
		 << thishand-1 << " hands\n";

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

static void deal_initial_cards(Deck *deck_ptr, Player *player_ptr, Hand *player_hand, Hand *dealer_hand, Card dealer_cards_ptr[])
{
	Card player_cards[2];

	player_cards[0] = deck_ptr->deal();
	player_hand->add_card(player_cards[0]);

	player_ptr->expose(player_cards[0]);

	announce_player_card(&player_cards[0]);

	dealer_cards_ptr[0] = deck_ptr->deal();
	dealer_hand->add_card(dealer_cards_ptr[0]);

	player_ptr->expose(dealer_cards_ptr[0]);

	announce_dealer_card(&dealer_cards_ptr[0]);

	player_cards[1] = deck_ptr->deal();
	player_hand->add_card(player_cards[1]);

	player_ptr->expose(player_cards[1]);

	announce_player_card(&player_cards[1]);

	dealer_cards_ptr[1] = deck_ptr->deal();
	dealer_hand->add_card(dealer_cards_ptr[1]);

	return;
}

static bool check_twenty_one(Hand *hand)
{
	return hand->hand_value() == 21;
}

static void natural_twenty_one_payout(int &bankroll, const int &wager)
{
	cout << "Player dealt natural 21\n";

	bankroll = bankroll + ( (3 * wager) / 2 );

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

static void announce_dealer_hole_card(const Card *card)
{
	cout << "Dealer's hole card is " << *card << endl;

	return;
}

static void announce_player_total(const Hand *player_hand)
{
	cout << "Player's total is " << player_hand->hand_value() << endl;

	return;
}

static void announce_dealer_total(const Hand *dealer_hand)
{
	cout << "Dealer's total is " << dealer_hand->hand_value() << endl;

	return;
}

static void announce_player_busts()
{
	cout << "Player busts\n";

	return;
}

static void announce_dealer_busts()
{
	cout << "Dealer busts\n";

	return;
}

static void announce_player_wins()
{
	cout << "Player wins\n";

	return;
}


static void announce_dealer_wins()
{
	cout << "Dealer wins\n";

	return;
}

static void player_lost_hand(int &bankroll, const int &wager, Hand *player_hand, Hand *dealer_hand)
{
	bankroll = bankroll - wager;

	player_hand->discard_all();
	dealer_hand->discard_all();

	return;
}

static void player_won_hand(int &bankroll, const int &wager, Hand *player_hand, Hand *dealer_hand)
{
	bankroll = bankroll + wager;

	player_hand->discard_all();
	dealer_hand->discard_all();

	return;
}

static void hand_is_push(Hand *player_hand, Hand *dealer_hand)
{
	cout << "Push\n";

	player_hand->discard_all();
	dealer_hand->discard_all();
	
	return;
}

static void play_dealers_hand(Hand *dealer_hand, const Card dealer_cards[], Player *player_ptr, Deck *deck)
{
	Card dealt;

	announce_dealer_hole_card(&dealer_cards[1]);

	player_ptr->expose(dealer_cards[1]);

	while (dealer_hand->hand_value() < 17)
	{
		dealt = deck->deal();

		player_ptr->expose(dealt);

		dealer_hand->add_card(dealt);

		announce_dealer_card(&dealt);
	}

	return;
}
