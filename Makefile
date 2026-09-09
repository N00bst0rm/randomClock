CC=gcc
CFLAGS=-Wall -Wextra

all: randomClock

randomClock: randomClock.o main.o
	$(CC) $(CFLAGS)  obj/* -o bin/randomClock

randomClock.o: src/randomClock.c src/randomClock.h
	$(CC) $(CFLAGS) -c src/randomClock.c -o obj/randomClock.o

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o

clean:
	rm -f bin/*
	rm -f obj/*

