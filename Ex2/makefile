# הגדרת הקומפיילר
CXX = g++
CXXFLAGS = -Wall -g

# הגדרת שם קובץ ההדגמה
TARGET = Main

# הגדרת קבצי המקור (Source Files)
SRC = main.cpp SquareMat.cpp

# המרת קבצי ה- .cpp ל- .o (קבצי אובייקט)
main.o: main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp -o SquareMat.o

# יצירת קובץ ההדגמה (Executable)
$(TARGET): main.o SquareMat.o
	$(CXX) $(CXXFLAGS) main.o SquareMat.o -o $(TARGET)

# הפקודה make test – להרצת בדיקות יחידה
test:
	./$(TARGET)

# הפקודה make valgrind – לבדוק זליגת זיכרון עם valgrind
valgrind: $(TARGET)
	valgrind --leak-check=full ./$(TARGET)

# הפקודה make clean – מוחקת קבצים לא רלוונטיים לאחר הריצה
clean:
	rm -f *.o $(TARGET)
