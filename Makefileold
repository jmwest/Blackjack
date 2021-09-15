CC     := g++
CFLAGS := -Wall -Werror -pedantic -g

Card_test00 : Card_test00.cpp Card.cpp
	$(CC) $(CFLAGS) Card_test00.cpp Card.cpp -o Card_test00

Deck_test00 : Deck_test00.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test00.cpp Deck.cpp Card.cpp -o Deck_test00

Deck_test01 : Deck_test01.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test01.cpp Deck.cpp Card.cpp -o Deck_test01

Deck_test02 : Deck_test02.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test02.cpp Deck.cpp Card.cpp -o Deck_test02

Deck_test03 : Deck_test03.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test03.cpp Deck.cpp Card.cpp -o Deck_test03

Deck_test04 : Deck_test04.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test04.cpp Deck.cpp Card.cpp -o Deck_test04

Deck_test05 : Deck_test05.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test05.cpp Deck.cpp Card.cpp -o Deck_test05

Deck_test06 : Deck_test06.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test06.cpp Deck.cpp Card.cpp -o Deck_test06

Deck_test07 : Deck_test07.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test07.cpp Deck.cpp Card.cpp -o Deck_test07

Deck_test08 : Deck_test08.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test08.cpp Deck.cpp Card.cpp -o Deck_test08

Deck_test09 : Deck_test09.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test09.cpp Deck.cpp Card.cpp -o Deck_test09

Player_test00 : Player_tst00.cpp Card.cpp Hand.cpp Deck.cpp Player.cpp rand.cpp
	$(CC) $(CFLAGS) Player_test00.cpp Card.cpp Hand.cpp Deck.cpp Player.cpp rand.cpp -o Player_test00

Hand_test00 : Hand_test00.cpp Hand.cpp Card.cpp
	$(CC) $(CFLAGS) Hand_test00.cpp Hand.cpp Card.cpp -o Hand_test00

Deck_test00.1 : Deck_test00.1.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test00.1.cpp Deck.cpp Card.cpp -o Deck_test00.1

blackjack : Card.cpp rand.cpp Hand.cpp Deck.cpp Player.cpp blackjack.cpp
	$(CC) $(CFLAGS) Card.cpp rand.cpp Hand.cpp Deck.cpp Player.cpp blackjack.cpp -o blackjack

test : blackjack Card_test00 Deck_test00
	./Card_test00
	./Deck_test00
	./blackjack 100 3 simple > blackjack.out
	diff -q blackjack_test00.out.correct blackjack.out

testU : Deck_test01 Deck_test02 Deck_test03 Deck_test04 Deck_test05 Deck_test06 Deck_test07 Deck_test08 Deck_test09
	./Deck_test01
	./Deck_test02
	./Deck_test03
	./Deck_test04
	./Deck_test05
	./Deck_test06
	./Deck_test07
	./Deck_test08
	./Deck_test09

testC : Card_test00
	./Card_test00 > Card_test00.out
	diff Card_test00.out Card_test00.out.correct

testD : Deck_test00 Deck_test00.1
	./Deck_test00 > Deck_test00.out
	diff Deck_test00.out Deck_test00.out.correct
	./Deck_test00.1 > Deck_test00.1.out
	diff Deck_test00.1.out Deck_test00.1.out.correct

testH : Hand_test00
	./Hand_test00 > Hand_test00.out
	diff Hand_test00.out Hand_test00.out.correct

testP : Player_test00
	./Player_test00 simple
	./Player_test00 counting
	./Player_test00 competitor

clean :
	rm -vf blackjack *.out \
         Card_test[0-9][0-9] \
         Deck_test[0-9][0-9] \
         Player_test[0-9][0-9]
