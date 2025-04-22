# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -g

# Target name for the executable
TARGET = Main

# Source files
SRC = main.cpp SquareMat.cpp

# Object files
OBJ = main.o SquareMat.o

# Default rule to build the target
$(TARGET):  main.o SquareMat.o
	$(CXX) $(CXXFLAGS)  main.o SquareMat.o -o $(TARGET)

# Rule to compile main.cpp to main.o
main.o: main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Rule to compile SquareMat.cpp to SquareMat.o
SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp -o SquareMat.o

# Rule to run the program (test)
test: $(TARGET)
	./$(TARGET)

# Rule to check for memory leaks using valgrind
valgrind: $(TARGET)
	ulimit -n 4096 && valgrind --leak-check=full ./$(TARGET)

# Clean up object and executable files
clean:
	rm -f  main.o SquareMat.o $(TARGET)
