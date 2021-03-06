#dominion makefile
#Isaac Stallcup

CFLAGS = -w -g -fpic -coverage -lm

U = cd cardtest;

T = cd thaia; 

#help

help:
	@echo "useful commands:"
	@echo "testdominion - creates testdominion.out from testdominion.c"
	@echo "all - build all available runnable files"
	@echo "clean - removes all generated files"
	@echo "tidy - removes all generated files EXCEPT log files"
	@echo "suiterand/suiteunit - run all random/unit tests together, log them"
	@echo "lograndom/logunit - run each individual unit/random test, log them"
	@echo "covrand/covunit - outputs only coverage data for dominion.c to stdout"
	@echo "test - run all available tests"
	@echo "spider - run tarantula script 'handler'"

#makefile commands

#runs tarantula for final
spider: all
	./handler 3 randomdump1.out randomdump2.out randomdump3.out

testthaia: buildthaia
	./thaia/st-card1 > ./thaia/card1.out
	./thaia/st-card2 > ./thaia/card2.out
	./thaia/st-card3 > ./thaia/card3.out
	./thaia/st-card4 > ./thaia/card4.out

buildthaia: # "$T" changes directory to the thaia directory
	@$T make rngs.o; make dominion.o; make interface.o
	@$T gcc stallcuicardtest1.c dominion.o rngs.o $(CFLAGS) -o st-card1 
	@$T gcc stallcuicardtest2.c dominion.o rngs.o $(CFLAGS) -o st-card2
	@$T gcc stallcuicardtest3.c dominion.o rngs.o $(CFLAGS) -o st-card3
	@$T gcc stallcuicardtest4.c dominion.o rngs.o $(CFLAGS) -o st-card4
	@$T gcc stallcuiunittest1.c dominion.o rngs.o $(CFLAGS) -o st-unit1 
	@$T gcc stallcuiunittest2.c dominion.o rngs.o $(CFLAGS) -o st-unit2
	@$T gcc stallcuiunittest3.c dominion.o rngs.o $(CFLAGS) -o st-unit3
	@$T gcc stallcuiunittest4.c dominion.o rngs.o $(CFLAGS) -o st-unit4
	@$T gcc stallcuirand1.c dominion.o rngs.o $(CFLAGS) -o st-rand1
	@$T gcc stallcuirand2.c dominion.o rngs.o interface.o $(CFLAGS) -o st-rand2
	@$T gcc stallcuiranda.c dominion.o rngs.o interface.o $(CFLAGS) -o st-randa

test: all suiterandom suiteunit coverage

all: playdom player buildunit buildrandom buildtestdom buildthaia

clean:
	@echo "MAKE: CLEANING DIRECTORY"; pwd
	rm -f *.o *.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM cardtest1 cardtest2 cardtest3 cardtest4 log playdom player randomtestadventurer randomtestcard1 randomtestcard2 unittest1 unittest2 unittest3 unittest4 dominion testdominion *.out 
	@$T make clean #clean up thaia directory

tidy: #leaves .out files alone
	rm -f *.o *.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM cardtest1 cardtest2 cardtest3 cardtest4 log playdom player randomtestadventurer randomtestcard1 randomtestcard2 unittest1 unittest2 unittest3 unittest4

buildunit: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4

buildrandom: randomtestcard1 randomtestcard2 randomtestadventurer

buildtestdom: dominion.o rngs.o interface.o testdominion.c
	@gcc -o testdominion testdominion.c  dominion.o interface.o rngs.o $(CFLAGS)

testdominion: all buildtestdom #runs testdominion, generates testdominion.out
	@echo "TESTING DOMINION.C" > testdominion.out
	@./testdominion 42 >> testdominion.out

testdominioncoverage:clean all
	@./testdominion 42 
	@./testdominion 41
	@./testdominion 87
	@./testdominion 40
	@./testdominion 5
	@./testdominion 16
	@./testdominion 7
	@./testdominion 8
	@./testdominion 70
	@./testdominion 10
	@./testdominion 11
	@./testdominion 12
	@./testdominion 131
	@./testdominion 140
	@./testdominion 15
	@./testdominion 16
	@./testdominion 173
	@./testdominion 186
	@./testdominion 187
	@./testdominion 214
	@gcov dominion.c > testdominioncoverage.out

#coverage commands
#run tests, output coverage data for fine dominion.c to
#a single file

coverage: lograndom logunit
	@echo "COVERAGE FOR RANDOM CARD TEST 1" > coverage.out
	@cat randomtestcard1.out | grep "File 'dominion.c'" -A 6 >> coverage.out
	@echo "COVERAGE FOR RANDOM CARD TEST 2" >> coverage.out
	@cat randomtestcard2.out | grep "File 'dominion.c'" -A 6  >> coverage.out
	@echo "COVERAGE FOR RANDOM ADVENTURER TEST" >> coverage.out
	@cat randomtestadventurer.out | grep "File 'dominion.c'" -A 6 >> coverage.out  
	@echo "COVERAGE FOR UNIT TEST 1" >> coverage.out
	@cat unittest1.out | grep "File 'dominion.c'" -A 6 >> coverage.out
	@echo "COVERAGE FOR UNIT TEST 2" >> coverage.out
	@cat unittest2.out | grep "File 'dominion.c'" -A 6 >> coverage.out
	@echo "COVERAGE FOR UNIT TEST 3" >> coverage.out
	@cat unittest3.out | grep "File 'dominion.c'" -A 6 >> coverage.out
	@echo "COVERAGE FOR UNIT TEST 4" >> coverage.out
	@cat unittest4.out | grep "File 'dominion.c'" -A 6 >> coverage.out
	@echo "COVERAGE FOR CARD TEST 1" >> coverage.out
	@cat cardtest1.out | grep "File 'dominion.c'" -A 6 >> coverage.out
	@echo "COVERAGE FOR CARD TEST 2" >> coverage.out
	@cat cardtest2.out | grep "File 'dominion.c'" -A 6 >> coverage.out
	@echo "COVERAGE FOR CARD TEST 3" >> coverage.out
	@cat cardtest3.out | grep "File 'dominion.c'" -A 6 >> coverage.out
	@echo "COVERAGE FOR CARD TEST 4" >> coverage.out
	@cat cardtest4.out | grep "File 'dominion.c'" -A 6 >> coverage.out

covrand: lograndom
	@echo "COVERAGE FOR RANDOM CARD TEST 1"
	@cat randomtestcard1.out | grep "File 'dominion.c'" -A 4 
	@echo "COVERAGE FOR RANDOM CARD TEST 2"
	@cat randomtestcard2.out | grep "File 'dominion.c'" -A 4  
	@echo "COVERAGE FOR RANDOM ADVENTURER TEST"
	@cat randomtestadventurer.out | grep "File 'dominion.c'" -A 4  

covunit: logunit
	@echo "COVERAGE FOR UNIT TEST 1"
	@cat unittest1.out | grep "File 'dominion.c'" -A 4
	@echo "COVERAGE FOR UNIT TEST 2"
	@cat unittest2.out | grep "File 'dominion.c'" -A 4
	@echo "COVERAGE FOR UNIT TEST 3"
	@cat unittest3.out | grep "File 'dominion.c'" -A 4
	@echo "COVERAGE FOR UNIT TEST 4"
	@cat unittest4.out | grep "File 'dominion.c'" -A 4
	@echo "COVERAGE FOR CARD TEST 1"
	@cat cardtest1.out | grep "File 'dominion.c'" -A 4
	@echo "COVERAGE FOR CARD TEST 2"
	@cat cardtest2.out | grep "File 'dominion.c'" -A 4
	@echo "COVERAGE FOR CARD TEST 3"
	@cat cardtest3.out | grep "File 'dominion.c'" -A 4
	@echo "COVERAGE FOR CARD TEST 4"
	@cat cardtest4.out | grep "File 'dominion.c'" -A 4
	

#logging commands
#run all tests of a singular type individually, outputs results
#and coverage data. Beware, cleans up first.

lograndom:
	@make tidy
	@make all
	@./randomtestcard1 42 > randomdump1.out
	@echo "GCOV AFTER RANDOM CARD TEST 1" > randomtestcard1.out
	@gcov -fb dominion.c >> randomtestcard1.out
	#done with card 1, now do card 2
	@make tidy
	@make all
	@./randomtestcard2 42 > randomdump2.out
	@echo "GCOV AFTER RANDOM CARD TEST 2" > randomtestcard2.out
	@gcov -fb dominion.c >> randomtestcard2.out
	#done with card 2, now do adventurer
	@make tidy
	@make all
	@./randomtestadventurer 42 > randomdumpadv.out
	@echo "GCOV AFTER RANDOM TEST ADVENTURER" > randomtestadventurer.out
	@gcov -fb dominion.c >> randomtestadventurer.out

logunit:
	@make tidy
	@make all
	@./unittest1 > unitdump1.out
	@echo "COVERAGE AFTER UNIT TEST 1" > unittest1.out
	@gcov -fb dominion.c >> unittest1.out
	#done with test, move on to next
	@make tidy
	@make all
	@./unittest2 > unitdump2.out
	@echo "COVERAGE AFTER UNIT TEST 2" > unittest2.out
	@gcov -fb dominion.c >> unittest2.out
	#done with test, move on to next
	@make tidy
	@make all
	@./unittest3 > unitdump3.out
	@echo "COVERAGE AFTER UNIT TEST 3" > unittest3.out
	@gcov -fb dominion.c >> unittest3.out
	#done with test, move on to next
	@make tidy
	@make all
	@./unittest4 > unitdump4.out
	@echo "COVERAGE AFTER UNIT TEST 4" > unittest4.out
	@gcov -fb dominion.c >> unittest4.out
	#done with test, move on to next
	@make tidy
	@make all
	@./cardtest1 > carddump1.out
	@echo "COVERAGE AFTER CARD TEST 1" > cardtest1.out
	@gcov -fb dominion.c >> cardtest1.out
	#done with test, move on to next
	@make tidy
	@make all
	@./cardtest2 > carddump2.out
	@echo "COVERAGE AFTER CARD TEST 2" > cardtest2.out
	@gcov -fb dominion.c >> cardtest2.out
	#done with test, move on to next
	@make tidy
	@make all
	@./cardtest3 > carddump3.out
	@echo "COVERAGE AFTER CARD TEST 3" > cardtest3.out
	@gcov -fb dominion.c >> cardtest3.out
	#done with test, move on to next
	@make tidy
	@make all
	@./cardtest4 > carddump4.out
	@echo "COVERAGE AFTER CARD TEST 4" > cardtest4.out
	@gcov -fb dominion.c >> cardtest4.out
	#all done

#test suites
#create log .out files with coverage data for all tests

suiteunit:
	@./unittest1 > unittest1.out 
	@echo "COVERAGE AFTER UNIT TEST 1" > unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./unittest2 > unittest2.out
	@echo "COVERAGE AFTER UNIT TEST 2" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./unittest3 > unittest3.out
	@echo "COVERAGE AFTER UNIT TEST 3" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./unittest4 > unittest4.out
	@echo "COVERAGE AFTER UNIT TEST 4" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./cardtest1 > cardtest1.out
	@echo "COVERAGE AFTER CARD TEST 1" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./cardtest2 > cardtest2.out
	@echo "COVERAGE AFTER CARD TEST 2" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./cardtest3 > cardtest3.out
	@echo "COVERAGE AFTER CARD TEST 3" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out
	@./cardtest4 > cardtest4.out
	@echo "COVERAGE AFTER CARD TEST 4" >> unittestresults.out
	@gcov dominion.c >> unittestresults.out

suiterandom:
	@./randomtestcard1 42 > dump.out
	@echo "GCOV AFTER RANDOM CARD TEST 1" > randomtestresults.out
	@gcov -fb dominion.c >> randomtestresults.out
	@./randomtestcard2 42 >> dump.out
	@echo "GCOV AFTER RANDOM CARD TEST 2" >> randomtestresults.out
	@gcov -fb dominion.c >> randomtestresults.out #care; includes test #1
	@./randomtestadventurer 42 >> dump.out
	@echo "GCOV AFTER RANDOM ADVENTURER TEST" >> randomtestresults.out
	@gcov -fb dominion.c >> randomtestresults.out #again, total coverage!

#.o files

rngs.o: rngs.h rngs.c
	gcc -c rngs.c $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c  $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c  $(CFLAGS)

#runnable files

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c dominion.o rngs.o $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c dominion.o rngs.o interface.o $(CFLAGS)

#random tests

randomtestcard1: randomtestcard1.c dominion.o rngs.o interface.o
	@gcc -o randomtestcard1 randomtestcard1.c dominion.o rngs.o interface.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o interface.o
	@gcc -o randomtestcard2 randomtestcard2.c dominion.o rngs.o interface.o $(CFLAGS)
	
randomtestadventurer: randomtestadventurer.c dominion.o rngs.o interface.o
	@gcc -o randomtestadventurer randomtestadventurer.c dominion.o rngs.o interface.o $(CFLAGS)

#unit tests

unittest1: unittest1.c dominion.o rngs.o interface.o
	@gcc -o unittest1 unittest1.c dominion.o rngs.o interface.o $(CFLAGS)

unittest2: unittest2.c dominion.o rngs.o interface.o
	@gcc -o unittest2 unittest2.c dominion.o rngs.o interface.o $(CFLAGS)

unittest3: unittest3.c dominion.o rngs.o interface.o
	@gcc -o unittest3 unittest3.c dominion.o rngs.o interface.o $(CFLAGS)

unittest4: unittest4.c dominion.o rngs.o interface.o
	@gcc -o unittest4 unittest4.c dominion.o rngs.o interface.o $(CFLAGS)

#card tests

cardtest1: cardtest1.c dominion.o rngs.o interface.o
	@gcc -o cardtest1 cardtest1.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest2: cardtest2.c dominion.o rngs.o interface.o
	@gcc -o cardtest2 cardtest2.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest3: cardtest3.c dominion.o rngs.o interface.o
	@gcc -o cardtest3 cardtest3.c dominion.o rngs.o interface.o $(CFLAGS)

cardtest4: cardtest4.c dominion.o rngs.o interface.o
	@gcc -o cardtest4 cardtest4.c dominion.o rngs.o interface.o $(CFLAGS)
