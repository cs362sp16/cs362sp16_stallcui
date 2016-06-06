#modified by Isaac Stallcup to clean up files created by 
#his final assignment

CFLAGS = -w -fpic -coverage -lm

stallcui:
	gcc stallcuicardtest1.c dominion.o rngs.o $(CFLAGS) -o st-card1
	gcc stallcuicardtest2.c dominion.o rngs.o $(CFLAGS) -o st-card2
	gcc stallcuicardtest3.c dominion.o rngs.o $(CFLAGS) -o st-card3
	gcc stallcuicardtest4.c dominion.o rngs.o $(CFLAGS) -o st-card4
	gcc stallcuiunittest1.c dominion.o rngs.o $(CFLAGS) -o st-unit1 
	gcc stallcuiunittest2.c dominion.o rngs.o $(CFLAGS) -o st-unit2
	gcc stallcuiunittest3.c dominion.o rngs.o $(CFLAGS) -o st-unit3
	gcc stallcuiunittest4.c dominion.o rngs.o $(CFLAGS) -o st-unit4
	gcc stallcuirand1.c dominion.o rngs.o $(CFLAGS) -o st-rand1
	gcc stallcuirand2.c dominion.o rngs.o interface.o $(CFLAGS) -o st-rand2
	gcc stallcuiranda.c dominion.o rngs.o interface.o $(CFLAGS) -o st-randa

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o interface.o
	gcc -c dominion.c -g rngs.o interface.o $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest1: tests/unittest1.c dominion.o rngs.o
	gcc -o unittest1 tests/unittest1.c -g dominion.o rngs.o $(CFLAGS)

unittest2: tests/unittest2.c dominion.o rngs.o
	gcc -o unittest2 tests/unittest2.c -g dominion.o rngs.o $(CFLAGS)

unittest3: tests/unittest3.c dominion.o rngs.o
	gcc -o unittest3 tests/unittest3.c -g dominion.o rngs.o $(CFLAGS)

unittest4: tests/unittest4.c dominion.o rngs.o
	gcc -o unittest4 tests/unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest1: tests/cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 tests/cardtest1.c -g dominion.o rngs.o $(CFLAGS)

cardtest2: tests/cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 tests/cardtest2.c -g dominion.o rngs.o $(CFLAGS)

cardtest3: tests/cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 tests/cardtest3.c -g dominion.o rngs.o $(CFLAGS)

cardtest4: tests/cardtest4.c dominion.o rngs.o
	gcc -o cardtest4 tests/cardtest4.c -g dominion.o rngs.o $(CFLAGS)

randtesta: tests/randomtestadventurer.c dominion.o rngs.o
	gcc -o randtestadventurer tests/randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

randtestc1: tests/randomtestcard1.c dominion.o rngs.o
	gcc -o randtestcard1 tests/randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)

randtestc2: tests/randomtestcard2.c dominion.o rngs.o
	gcc -o randtestcard2 tests/randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

randtestex: tests/extrarandomtest.c dominion.o rngs.o
	gcc -o extrarandomtest tests/extrarandomtest.c -g dominion.o rngs.o $(CFLAGS)

buildtests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

unittestresults.out: buildtests playdom
	./unittest1 >> unittestresults.out
	echo "GCOV AFTER 1 TEST" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest2 >> unittestresults.out
	echo "GCOV AFTER 2 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest3 >> unittestresults.out
	echo "GCOV AFTER 3 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./unittest4 >> unittestresults.out
	echo "GCOV AFTER 4 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest1 >> unittestresults.out
	echo "GCOV AFTER 5 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest2 >> unittestresults.out
	echo "GCOV AFTER 6 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest3 >> unittestresults.out
	echo "GCOV AFTER 7 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./cardtest4 >> unittestresults.out
	echo "GCOV AFTER 8 TESTS" >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	./playdom 2 >> unittestresults.out
	echo "GCOV AFTER PLAYING A GAME" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

randcardtests: randtesta randtestc1 randtestc2 randtestex
	./randtestadventurer 42 >> randomtestadventurer.out
	echo "GCOV OF RANDOM TESTING: ADVENTURER" >> randomtestadventurer.out
	gcov -f randomtestadventurer.c >> randomtestadventurer.out
	echo "GCOV OF DOMINION" >> randomtestadventurer.out
	gcov dominion.c >> randomtestadventurer.out
	./randtestcard1  42>> randomtestcard1.out
	echo "GCOV OF RANDOM TESTING: CUTPURSE" >> randomtestcard1.out
	gcov -f randomtestcard1.c >> randomtestcard1.out
	echo "GCOV OF DOMINION" >> randomtestcard1.out
	gcov dominion.c >> randomtestcard1.out
	./randtestcard2 42 >> randomtestcard2.out
	echo "GCOV OF RANDOM TESTING: SMITHY" >> randomtestcard2.out
	gcov -f randomtestcard2.c >> randomtestcard2.out
	echo "GCOV OF DOMINION" >> randomtestcard2.out
	gcov dominion.c >> randomtestcard2.out
	echo "GCOV OF RANDOM TESTING: BARON" >> extrarandomtest.out
	./extrarandomtest 42 >> extrarandomtest.out
	gcov -f extrarandomtest.c >> extrarandomtest.out
	echo "GCOV OF DOMINION" >> extrarandomtest.out
	gcov dominion.c >> extrarandomtest.out

testdominion: dominion.o testdominion.c interface.o
	gcc -o testdominion testdominion.c -g dominion.o interface.o rngs.o $(CFLAGS)

testdominion.out: testdominion
	./testdominion 42 >> testdominion.out
	echo "GCOV OF RANDOM TESTER -- 1 RUN" >> testdominion.out
	gcov testdominion.c >> testdominion.out
	echo "GCOV OF DOMINION" >> testdominion.out
	gcov dominion.c >> testdominion.out 

all: playdom player buildtests randtesta randtestc1 randtestc2 testdominion stallcui

clean:
	@echo "MAKE: CLEANING DIRECTORY"; pwd
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randtestadventurer randtestcard1 extrarandomtest randtestcard2 player.exe testInit testInit.exe *.out *.gcov *.gcda *.gcno *.so *.a *.dSYM st-*

tidy:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randtestadventurer randtestcard1 extrarandomtest randtestcard2 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM st-*
