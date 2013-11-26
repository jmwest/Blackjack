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

Deck_test10 : Deck_test10.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test10.cpp Deck.cpp Card.cpp -o Deck_test10

Deck_test11 : Deck_test11.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test11.cpp Deck.cpp Card.cpp -o Deck_test11

Deck_test12 : Deck_test12.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test12.cpp Deck.cpp Card.cpp -o Deck_test12

Deck_test13 : Deck_test13.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test13.cpp Deck.cpp Card.cpp -o Deck_test13

Deck_test14 : Deck_test14.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test14.cpp Deck.cpp Card.cpp -o Deck_test14

Deck_test15 : Deck_test15.cpp Deck.cpp Card.cpp
	$(CC) $(CFLAGS) Deck_test15.cpp Deck.cpp Card.cpp -o Deck_test15

Player_test00 : Player_test00.cpp Card.cpp Hand.cpp Deck.cpp Player.cpp rand.cpp
	$(CC) $(CFLAGS) Player_test00.cpp Card.cpp Hand.cpp Deck.cpp Player.cpp rand.cpp -o Player_test00

Player_test01 : Player_test01.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test01.cpp Card.cpp Hand.cpp Player.cpp -o Player_test01

Player_test02 : Player_test02.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test02.cpp Card.cpp Hand.cpp Player.cpp -o Player_test02

Player_test03 : Player_test03.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test03.cpp Card.cpp Hand.cpp Player.cpp -o Player_test03

Player_test04 : Player_test04.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test04.cpp Card.cpp Hand.cpp Player.cpp -o Player_test04

Player_test05 : Player_test05.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test05.cpp Card.cpp Hand.cpp Player.cpp -o Player_test05

Player_test06 : Player_test06.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test06.cpp Card.cpp Hand.cpp Player.cpp -o Player_test06

Player_test07 : Player_test07.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test07.cpp Card.cpp Hand.cpp Player.cpp -o Player_test07

Player_test08 : Player_test08.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test08.cpp Card.cpp Hand.cpp Player.cpp -o Player_test08

Player_test09 : Player_test09.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test09.cpp Card.cpp Hand.cpp Player.cpp -o Player_test09

Player_test10 : Player_test10.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test10.cpp Card.cpp Hand.cpp Player.cpp -o Player_test10

Player_test11 : Player_test11.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test11.cpp Card.cpp Hand.cpp Player.cpp -o Player_test11

Player_test12 : Player_test12.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test12.cpp Card.cpp Hand.cpp Player.cpp -o Player_test12

Player_test13 : Player_test13.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test13.cpp Card.cpp Hand.cpp Player.cpp -o Player_test13

Player_test14 : Player_test14.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test14.cpp Card.cpp Hand.cpp Player.cpp -o Player_test14

Player_test15 : Player_test15.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test15.cpp Card.cpp Hand.cpp Player.cpp -o Player_test15

Player_test16 : Player_test16.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test16.cpp Card.cpp Hand.cpp Player.cpp -o Player_test16

Player_test17 : Player_test17.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test17.cpp Card.cpp Hand.cpp Player.cpp -o Player_test17

Player_test18 : Player_test18.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test18.cpp Card.cpp Hand.cpp Player.cpp -o Player_test18

Player_test19 : Player_test19.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test19.cpp Card.cpp Hand.cpp Player.cpp -o Player_test19

Player_test20 : Player_test20.cpp Card.cpp Hand.cpp Player.cpp
	$(CC) $(CFLAGS) Player_test20.cpp Card.cpp Hand.cpp Player.cpp -o Player_test20

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

testU : Deck_test01 Deck_test02 Deck_test03 Deck_test04 Deck_test05 Deck_test06 Deck_test07 Deck_test08 Deck_test09 Deck_test10 Deck_test11 Deck_test12 Deck_test13 Deck_test14 Deck_test15 Player_test01 Player_test02 Player_test03 Player_test04 Player_test05 Player_test06 Player_test07 Player_test08 Player_test09 Player_test10 Player_test11 Player_test12 Player_test13 Player_test14 Player_test15 Player_test16 Player_test17 Player_test18 Player_test19 Player_test20
	./Deck_test01
	./Deck_test02
	./Deck_test03
	./Deck_test04
	./Deck_test05
	./Deck_test06
	./Deck_test07
	./Deck_test08
	./Deck_test09
	./Deck_test10
	./Deck_test11
	./Deck_test12
	./Deck_test13
	./Deck_test14
	./Deck_test15
	./Player_test01
	./Player_test02
	./Player_test03
	./Player_test04
	./Player_test05
	./Player_test06
	./Player_test07
	./Player_test08
	./Player_test09
	./Player_test10
	./Player_test11
	./Player_test12
	./Player_test13
	./Player_test14
	./Player_test15
	./Player_test16
	./Player_test17
	./Player_test18
	./Player_test19
	./Player_test20

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
