CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = main.o gameOfLife.o readFile.o
EXEC = life

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

gameOfLife.o : gameOfLife.c gameOfLife.h
	$(CC) $(CFLAGS) -c gameOfLife.c

readFile.o : readFile.c readFile.h
	$(CC) $(CFLAGS) -c readFile.c

clean: 
	rm -f $(EXEC) $(OBJ)

