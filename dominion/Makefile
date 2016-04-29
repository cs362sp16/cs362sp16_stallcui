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

buildtests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

runtestslog: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 playdom
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

runtests:
	@./cardtest1 
	@./cardtest2 
	@./cardtest3 
	@./cardtest4 
	@./unittest1 
	@./unittest2 
	@./unittest3 
	@./unittest4

log: buildtests runtestslog

suite: buildtests runtests

all: playdom player buildtests

clean:
	rm -f *.o unittestresults.out playdom.exe playdom test.exe test tests player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM

coverage: clean all runtestslog
	cat unittestresults.out | grep -B 2 "executed"

