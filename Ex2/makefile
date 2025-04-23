CXX = g++
CXXFLAGS = -Wall -g

all: Main

Main: main.o SquareMat.o
	$(CXX) $(CXXFLAGS) main.o SquareMat.o -o Main

main.o: main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp -o SquareMat.o

Tests: Tests.o SquareMat.o
	$(CXX) $(CXXFLAGS) Tests.o SquareMat.o -o Tests

Tests.o: Tests.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c Tests.cpp -o Tests.o

test: Tests
	./Tests

valgrind: Tests
	ulimit -n 4096 && valgrind --leak-check=full ./Tests

clean:
	rm -f main.o Tests.o SquareMat.o Main Tests
