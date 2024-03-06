CC = gcc
CFLAGS = -Wall -pedantic -ansi -g
OBJ = main.o snakeGame.o terminal.o random.o fileRead.o linkedList.o
EXEC = snake

ifdef UNBEATABLE
CFLAGS += -D UNBEATABLE
UNBEATABLE: clean $(EXEC)
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c
	$(CC) $(CFLAGS) -c main.c

snakeGame.o : snakeGame.c snakeGame.h
	$(CC) $(CFLAGS) -c snakeGame.c

terminal.o : terminal.c terminal.h
	$(CC) $(CFLAGS) -c terminal.c 

random.o : random.c random.h
	$(CC) $(CFLAGS) -c random.c

fileRead.o : fileRead.c fileRead.h
	$(CC) $(CFLAGS) -c fileRead.c

linkedList.o : linkedList.c linkedList.h
	$(CC) $(CFLAGS) -c linkedList.c	

clean: 
	rm -f $(EXEC) $(OBJ)



