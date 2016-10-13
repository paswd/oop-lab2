FLAGS=-pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -std=c++11 -lm
COMPILLER=g++

all: start

start: geometry.o rectangle.o square.o trapeze.o main.o
	$(COMPILLER) $(FLAGS) -o oop-lab1 geometry.o rectangle.o square.o trapeze.o main.o

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

geometry.o: geometry.cpp
	$(COMPILLER) -c $(FLAGS) geometry.cpp

rectangle.o: rectangle.cpp
	$(COMPILLER) -c $(FLAGS) rectangle.cpp

square.o: square.cpp
	$(COMPILLER) -c $(FLAGS) square.cpp

trapeze.o: trapeze.cpp
	$(COMPILLER) -c $(FLAGS) trapeze.cpp

clear:
	-rm -f *.o *.gch da-lab1
