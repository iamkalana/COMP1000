#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readFile.h"
#include <unistd.h>
int **currentGen;
int **nextGen;
int **temp;

void loadMatrix(char fileName[]) /* Passing readFile 2d array data into new arrays */
{
    int i, j;

    temp = returnMatrix(fileName);

    currentGen = (int **)malloc(getNumOfRows() * sizeof(int *));
    for (i = 0; i < (getNumOfRows() + 1); i++)
    {
        currentGen[i] = (int *)malloc(getNumOfCols() * sizeof(int));
    }

    nextGen = (int **)malloc(getNumOfRows() * sizeof(int *));
    for (i = 0; i < (getNumOfRows() + 1); i++)
    {
        nextGen[i] = (int *)malloc(getNumOfCols() * sizeof(int));
    }

    for (i = 0; i < getNumOfRows(); i++) /* 2d array of current genaration */
    {
        for (j = 0; j < getNumOfCols(); j++)
        {
            currentGen[i][j] = temp[i][j];
        }
    }

    for (i = 0; i < getNumOfRows(); i++) /* 2d array of next genaration */
    {
        for (j = 0; j < getNumOfCols(); j++)
        {
            nextGen[i][j] = currentGen[i][j];
        }
    }
}

int checkNeighbors(int i, int j) /* Checking current genaration neighbors */
{
    int liveNeighbors = 0;
    if (j - 1 >= 0 && currentGen[i][j - 1] == 1)
    {
        liveNeighbors++;
    }
    if (j + 1 <= getNumOfCols() && currentGen[i][j + 1] == 1)
    {
        liveNeighbors++;
    }
    if (i - 1 >= 0 && currentGen[i - 1][j] == 1)
    {
        liveNeighbors++;
    }
    if (i + 1 <= getNumOfRows() && currentGen[i + 1][j] == 1)
    {
        liveNeighbors++;
    }
    if (j - 1 >= 0 && i - 1 >= 0 && currentGen[i - 1][j - 1] == 1)
    {
        liveNeighbors++;
    }
    if (j + 1 <= getNumOfCols() && i - 1 >= 0 && currentGen[i - 1][j + 1] == 1)
    {
        liveNeighbors++;
    }
    if (j - 1 >= 0 && i + 1 <= getNumOfRows() && currentGen[i + 1][j - 1] == 1)
    {
        liveNeighbors++;
    }
    if (j + 1 <= getNumOfCols() && i + 1 <= getNumOfRows() && currentGen[i + 1][j + 1] == 1)
    {
        liveNeighbors++;
    }
    return liveNeighbors;
}

void game() /* Checking game rules */
{
    int i, j;

    for (i = 0; i < getNumOfRows(); i++)
    {
        for (j = 0; j < getNumOfCols(); j++)
        {
            if (currentGen[i][j] == 1)
            {
                if (checkNeighbors(i, j) == 0 || checkNeighbors(i, j) == 1)
                {
                    nextGen[i][j] = 0;
                }
                else if (checkNeighbors(i, j) == 2 || checkNeighbors(i, j) == 3)
                {
                    nextGen[i][j] = 1;
                }
                else if (checkNeighbors(i, j) > 3)
                {
                    nextGen[i][j] = 0;
                }
            }
            else if (currentGen[i][j] == 0)
            {
                if (checkNeighbors(i, j) == 3)
                {
                    nextGen[i][j] = 1;
                }
            }
        }
    }

    for (i = 0; i < getNumOfRows(); i++)
    {
        for (j = 0; j < getNumOfCols(); j++)
        {
            currentGen[i][j] = nextGen[i][j];
        }
    }
}

void display() /* Displaying genaration */
{
    int i, j;
    for (i = 0; i < getNumOfRows(); i++)
    {
        for (j = 0; j < getNumOfCols(); j++)
        {
            if (nextGen[i][j] == 1)
            {
                printf("\033[0;100m");
                printf(" ");
            }
            else
            {
                printf("\033[0;107m");
                printf(" ");
            }
            printf("\033[0m");
        }
        printf("\n");
    }
}

void freeMalloc() /* Free mallocs */
{
    free(temp);

    free(currentGen);
    currentGen = NULL;

    free(nextGen);
    nextGen = NULL;
}