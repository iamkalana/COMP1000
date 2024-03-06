#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameOfLife.h"
#include "readFile.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int run = 0;
    system("clear");
    if (argc == 3)
    {
        char fileName[50];
        strcpy(fileName, argv[1]);
        loadMatrix(fileName);
        display();
        sleep(1);
        while (run < atof(argv[2]))
        {
            system("clear");
            game();
            display();
            sleep(1);
            run++;
        }
        freeMalloc();
    }
    else
    {
        printf("Not enough arguments provided!\n");
        printf("./life <cell_file> <cycles>\n");
    }
    return 0;
}
