CC		 = g++
CFLAGS = -Wall -g -O0
SRC		 = ./src
RM		 = rm

ep3: main.o graph.o regex.o
	$(CC) -o ep3 main.o graph.o regex.o

main.o: $(SRC)/main.cpp $(SRC)/graph.hpp $(SRC)/regex.hpp
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp

graph.o: $(SRC)/graph.cpp $(SRC)/graph.hpp 
	$(CC) $(CFLAGS) -c $(SRC)/graph.cpp

regex.o: $(SRC)/regex.cpp $(SRC)/regex.hpp $(SRC)/graph.hpp 
	$(CC) $(CFLAGS) -c $(SRC)/regex.cpp

clear:
	$(RM) -r *.o && $(RM) -r ep3