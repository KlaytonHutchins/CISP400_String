CC=g++
CFLAGS= -c -g -Wall -std=c++17 -fpermissive
EXENAME= String

default: string.o main.o
	$(CC) string.o main.o -o $(EXENAME)

string.o: string.cpp
	$(CC) $(CFLAGS) string.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o $(EXENAME)

run:
	./$(EXENAME)

