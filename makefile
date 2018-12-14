INC = ./include/libfdr
LIB = ./include/libfdr
CC = gcc
SRC = ./src/main.c

all: main

main: $(SRC)
	$(CC) -I ./include/ -o ./lib/komut.o -c ./src/komut.c -w
	$(CC) -I$(INC) -I ./include/ -o ./lib/islem.o -L$(LIB) -c ./src/islem.c -lfdr -w
	$(CC) -I$(INC) $(SRC) -o ./bin/main ./lib/komut.o ./lib/islem.o -L$(LIB) -lfdr -w
	./bin/main
