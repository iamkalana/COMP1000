#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
#include "snakeGame.h"

int game;
int main(int argc, char *argv[])
{
    int r, c, l;
    if (argc == 4)
    {
        r = atof(argv[1]);
        c = atof(argv[2]);
        l = atof(argv[3]);

        system("clear");
        getUserInput(r, c, l);
        creatMalloc();
        snakeInitialization();
        fruitCords();
        map();
        while (game == 0)
        {
            movement();
            clearTail();
            system("clear");
            map();
            errorMsg();
        }
        freeMalloc();

        endMsg();
    }
    else
    {
        printf("Invalid number of arguments!\n");
        printf("Type: ./snake <row_map> <col_map> <snake_length>\n");
    }

    return 0;
}