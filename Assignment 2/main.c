#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"
#include "snakeGame.h"
#include "fileRead.h"
#include "linkedList.h"

int game;
int main(int argc, char *argv[])
{
    int r, c, l, w;
    char fileName[20];
    
    if (argc == 3)
    {
        strcpy(fileName,argv[1]);
        fileR(fileName);
        w = atof(argv[2]);

        r = getRows();
        c = getCols();
        l = snakeLength();

        system("clear");
        getUserInput(r, c, l);
        snakeInitialization();
        fruitCords();
        map();
        printScore(w);
        while (game == 0)
        {
            movement();
            clearTail();
            system("clear");
            map();
            errorMsg();
            printScore(w);
        }

        endMsg();
        freeLinkedList();
    }
    else
    {
        printf("Invalid number of arguments!\n");
        printf("Type: ./snake <snake_file_name> <food_amount_to_win>\n");
    }
    return 0;
}