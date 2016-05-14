CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o interface.o
	@gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o interface.o
	@gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o interface.o $(CFLAGS)
	
randomtestadventurer: randomtestadventurer.c dominion.o rngs.o interface.o
	@gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest1: unittest1.c dominion.o rngs.o interface.o
	@gcc -o unittest1 unittest1.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o interface.o
	@gcc -o unittest2 unittest2.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o interface.o
	@gcc -o unittest3 unittest3.c -g dominion.o rngs.o interface.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o interface.o
	@gcc -o unittest4 unittest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest1: cardtest1.c dominion.o rngs.o interface.o
	@gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o interface.o
	@gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o interface.o
	@gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o interface.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o interface.o
	@gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o interface.o $(CFLAGS)

buildutests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

buildrandom: randomtestcard1 randomtestcard2 randomtestadventurer

runrandomlog: buildrandom

runutestslog: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 playdom
	@rm -f "unittestresults.out"
	@./unittest1 
	@echo "GCOV AFTER UNIT TEST 1" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./unittest2 
	@echo "GCOV AFTER UNIT TEST 2" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./unittest3 
	@echo "GCOV AFTER UNIT TEST 3" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./unittest4
	@echo "GCOV AFTER UNIT TEST 4" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./cardtest1 >> unittestresults.out
	@echo "GCOV AFTER CARD TEST 1" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./cardtest2 
	@echo "GCOV AFTER CARD TEST 2" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./cardtest3 
	@echo "GCOV AFTER CARD TEST 3" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./cardtest4 
	@echo "GCOV AFTER CARD TEST 4" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out

runrandom:
	@./randomtestcard1 42 > randomtestcard1.out
	@echo "GCOV AFTER RANDOM CARD TEST 1" >> randomtestcard1.out
	@gcov -f dominion.c >> randomtestcard1.out
	@./randomtestcard2 42 > randomtestcard2.out
	@./randomtestadventurer 42 > randomtestadventurer.out
	@echo "GCOV AFTER RANDOM ADVENTURER TEST" >> randomtestadventurer.out
	@gcov -f dominion.c >> randomtestadventurer.out #again, total coverage!

runrandomlog: #runs all random tests, puts results in 1 convenient place
	@./randomtestcard1 42
	@echo "GCOV AFTER RANDOM CARD TEST 1" > randomtestresults.out
	@gcov dominion.c >> randomtestresults.out
	@./randomtestcard2 42
	@./randomtestadventurer 42
	@echo "GCOV AFTER RANDOM ADVENTURER TEST" >> randomtestresults.out
	@gcov dominion.c >> randomtestresults.out #again, total coverage!

runutests:
	@./cardtest1 
	@./cardtest2 
	@./cardtest3 
	@./cardtest4 
	@./unittest1 
	@./unittest2 
	@./unittest3 
	@./unittest4

log: buildutests runutestslog

suite: buildutests runutests

all: playdom player buildutests buildrandom

cleanout:
	rm -f *.o playdom.exe playdom test.exe test tests player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM randomtestcard1 randomtestcard2 randomtestadventurer *.out

clean:
	rm -f *.o playdom.exe playdom test.exe test tests player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM randomtestcard1 randomtestcard2 randomtestadventurer

coverage: clean all runtestslog
	cat unittestresults.out | grep -B 2 "executed"

