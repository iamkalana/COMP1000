#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"
#include "random.h"

int **array;
int x, y, temp, head, tail, game, a, b, msg, err = 5, last;
int rows;
int colms;
char click;

void getUserInput(int r, int c, int l) /*GET USER ARGUMENTS*/
{
    rows = r;
    colms = c;
    head = l;
}
void creatMalloc() /*CREATE 2D MALLOCED ARRAY*/
{
    int i;
    array = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < (rows + 1); i++)
        array[i] = (int *)malloc(colms * sizeof(int));
}
void freeMalloc() /*FREEING MALLOCED ARRAY*/
{
    int i;
    for (i = 0; i < rows + 1; i++)
    {
        free(array[i]);
    }
    free(array);
    array = NULL;
}
void endMsg() /*PRINT GAME END MESSAGES*/
{
    switch (msg)
    {
    case 0:
        printf("YOU LOSE - GAME OVER\n");
        break;
    case 1:
        printf("YOU WIN\n");
        break;
    }
}
void errorMsg() /*PRINT ERROR MESSAGES*/
{
    if (err != 5)
    {
        switch (err)
        {
        case 0:
            printf("YOU CANT GO THROUGH THE WALLS\n");
            break;
        case 1:
            printf(" ");
            break;
        case 2:
            printf("Invalid key");
            break;
        }
    }
    else
        printf(" ");
}
int denyInvalidKey() /*RETURN 0 IF USER ENTER A INVALID KEY*/
{
    int bl;
    if (((click == 'd' || click == 'a') || (click == 'w' || click == 's')))
        bl = 1;
    else
        bl = 0;
    return bl;
}
int denyBackward() /*RETURN 0 WHEN USER TRYIED TO MOVE SNAKE BACKWARD*/
{
    int bl;
    if ((click == 'a' && last == 'd') || (click == 'd' && last == 'a'))
        bl = 0;
    else if ((click == 'w' && last == 's') || (click == 's' && last == 'w'))
        bl = 0;
    else if (click == 'a' && last == 0)
        bl = 0;
    else
        bl = 1;
    return bl;
}

void snakeInitialization() /*INITIALIZING THE SNAKE*/
{
    int i, j;

    for (i = 0; i < rows; i++) /*FILLING THE WHOLE 2D ARRAY WITH ZEROS*/
    {
        for (j = 0; j < colms; j++)
        {
            array[i][j] = 0;
        }
    }

    x = 0; /*SET SNAKE COORDINATES*/
    y = head;
    tail = 1;
    temp = y;

    for (i = 0; i < head; i++)
    {
        temp++;
        array[x][temp - head] = i + 1;
    }
}

void fruitCords() /*CREATE RANDOM COORDINATES FOR FRUIT*/
{
    initRandom();
    a = randomx(1, rows - 1);
    b = randomx(1, colms - 1);
}
void chngHead() /*CHANGE HEAD CHARACTER WITH WASD KEYS*/
{
    switch (click)
    {
    case 'd':
        printf("%c", '>');
        break;
    case 'a':
        printf("%c", '<');
        break;
    case 'w':
        printf("%c", '^');
        break;
    case 's':
        printf("%c", 'v');
        break;
    default:
        printf("%c", '>');
        break;
    }
}
void unbeatable() /*UNBEATABLE FUNCTION*/
{
    if (array[x][y] != 0 && array[x][y] != -1)
    {
        game = 1;
        msg = 0;
    }
}

void map() /*PRINT THE SCREEN*/
{
    int i, j;

    for (i = 0; i <= colms + 1; i++)
    {
        printf("%c", '*');
    }
    printf("\n");

    for (i = 0; i < rows; i++)
    {
        printf("%c", '*');
        for (j = 0; j < colms; j++)
        {
            if (array[i][j] == 0)
            {
                if ((i != a) || (j != b))
                {
                    printf(" ");
                }
            }
            if (array[i][j] >= 1 && array[i][j] != head)
            {
                if (array[i][j] == tail)
                    printf("%c", '#');
                else
                    printf("%c", '-');
            }
            if (array[i][j] == head)
                chngHead();
            if ((i == a) && (j == b))
            {
                if (array[i][j] != head)
                {
                    printf("%c", '@');
                }
            }
            if (j == colms - 1)
                printf("%c\n", '*');
        }
    }

    for (i = 0; i <= colms + 1; i++)
    {
        printf("%c", '*');
    }
    printf("\n");
}

void movement() /*SET SNAKE MOVEMENT CONTROLS*/
{
    disableBuffer();  
    scanf("%c", &click);
    enableBuffer();

    if (denyInvalidKey() == 1)
    {
        if (click == 'd' && denyBackward() == 1)
        {
            err = 1; /*CLEAR THE ERROR MESSAGE*/

            if (y < colms - 1) /*CHECK IF THE SNAKE REACHED THE BOARDER*/
            {
                y++;
                #ifndef UNBEATABLE
                unbeatable();
                #endif

                if ((x == a) && (y == b)) /*CHECK IF THE SNAKE COORDINATES EQUALS TO THE FRUIT COORDINATES*/
                {
                    if (array[x][y] != head)
                    {
                        game = 1;
                        msg = 1;
                    }
                }
                head++;   /*UPDATE THE SNAKE HEAD VALUE*/
                array[x][y] = head; /*UPDATE THE SNAKE HEAD COORDINATES */
                last = click;  /*"click" VALUE SAVE AS "last"*/
            }
            else
            {
                err = 0; /*RETURN AN ERROR MESSAGE*/
            }
        }

        if (click == 'a' && denyBackward() == 1)
        {
            err = 1;

            if (y > 0)
            {
                y--;
                #ifndef UNBEATABLE
                unbeatable();
                #endif
                if ((x == a) && (y == b)) 
                {
                    if (array[x][y] != head)
                    {
                        game = 1;
                        msg = 1;
                    }
                }
                head++;
                array[x][y] = head;
                last = click;
            }
            else
            {
                err = 0;
            }
        }

        if (click == 'w' && denyBackward() == 1)
        {
            err = 1;

            if (x > 0)
            {
                x--;
                #ifndef UNBEATABLE
                unbeatable();
                #endif
                if ((x == a) && (y == b))
                {
                    if (array[x][y] != head)
                    {
                        game = 1;
                        msg = 1;
                    }
                }
                head++;
                array[x][y] = head;
                last = click;
            }
            else
            {
                err = 0;
            }
        }
        if (click == 's' && denyBackward() == 1)
        {
            err = 1;

            if (x < rows - 1)
            {
                x++;
                #ifndef UNBEATABLE
                unbeatable();
                #endif
                if ((x == a) && (y == b))
                {
                    if (array[x][y] != head)
                    {
                        game = 1;
                        msg = 1;
                    }
                }
                head++;
                array[x][y] = head;
                last = click;
            }
            else
            {
                err = 0;
            }
        }
    }
    else
    {
        err = 2;
    }
}
void clearTail() /*CLEAR THE SNAKE TAIL WHEN SNAKE IS MOVING*/
{
    int i, j;
    if (((y < colms - 1) || ((click == 's' && x < rows - 1) || (click == 'w' && x > 0))) && /*CHECK RIGHT BORDER WITH 'S' & 'W' KEYS*/
        ((y > 0) || ((click == 's' && x < rows - 1) || (click == 'w' && x > 0))) &&         /*CHECK LEFT BORDER WITH 'S' & 'W' KEYS*/
        ((x > 0) || ((click == 'a' && y > 0) || (click == 'd' && y < colms - 1))) &&        /*CHECK TOP BORDER WITH 'A' & 'D' KEYS*/
        ((x < rows - 1) || ((click == 'a' && y > 0) || (click == 'd' && y < colms - 1))) && /*CHECK BOTTOM BORDER WITH 'A' & 'D' KEYS*/
        denyInvalidKey() == 1 && denyBackward() == 1) /*CHECK IF THE USER ENTERED AN INVALID KEY OR TRIED TO MOVE BACKWARD*/
    {
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < colms; j++)
            {

                if (array[i][j] == tail)
                {
                    array[i][j] = 0;
                }
            }
        }
        tail++;
    }
}