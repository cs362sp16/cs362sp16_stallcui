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

unittest1: unittest1.c
	gcc -o unittest1 unittest1.c -g $(CFLAGS)

unittest2: unittest2.c
	gcc -o unittest2 unittest2.c -g $(CFLAGS)

unittest3: unittest3.c
	gcc -o unittest3 unittest3.c -g $(CFLAGS)

unittest4: unittest4.c
	gcc -o unittest4 unittest4.c -g $(CFLAGS)

cardtest1: cardtest1.c
	gcc -o cardtest1 cardtest1.c -g $(CFLAGS)

cardtest2: cardtest2.c
	gcc -o cardtest2 cardtest2.c -g $(CFLAGS)

cardtest3: cardtest3.c
	gcc -o cardtest3 cardtest3.c -g $(CFLAGS)

cardtest4: cardtest4.c
	gcc -o cardtest4 cardtest4.c -g $(CFLAGS)

tests: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

suite:
	./cardtest1 
	./cardtest2 
	./cardtest3 
	./cardtest4 
	./unittest1 
	./unittest2 
	./unittest3 
	./unittest4

all: playdom player tests

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
