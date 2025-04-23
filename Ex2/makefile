# קומפיילר ודגלים
CXX = g++
CXXFLAGS = -Wall -g

# ברירת מחדל: קומפילציה של התוכנית הראשית
all: Main

# קומפילציה של Main
Main: main.o SquareMat.o
	$(CXX) $(CXXFLAGS) main.o SquareMat.o -o Main

main.o: main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp -o SquareMat.o

# קומפילציה של קובץ הטסטים והרצה
Tests: Tests.o SquareMat.o
	$(CXX) $(CXXFLAGS) Tests.o SquareMat.o -o Tests

Tests.o: Tests.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c Tests.cpp -o Tests.o

# הרצת הטסטים
test: Tests
	./Tests

# בדיקת זליגות זיכרון
valgrind: Tests
	ulimit -n 4096 && valgrind --leak-check=full ./Tests

# ניקוי קבצים
clean:
	rm -f main.o Tests.o SquareMat.o Main Tests
