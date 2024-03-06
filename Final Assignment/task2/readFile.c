#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rows, columns;
int **matrix;

void getRowsCols(char fileName[]) /* Read the file and get row and column count */
{
    int data[2];
    int i = 0;
    FILE *fptr;
    fptr = fopen(fileName, "r");
    if (fptr == NULL)
    {
        perror("Error: file can not open\n");
    }
    else
    {
        char line[100];
        while (fgets(line, sizeof(line), fptr) && i < 2)
        {
            char *token;
            token = strtok(line, " "); /* Split by white spaces */
            while (token != NULL)
            {
                data[i] = atoi(token);
                i++;

                token = strtok(NULL, " ");
            }
            rows = data[0];
            columns = data[1];
        }
    }
    if (ferror(fptr))
    {
        perror("Error while file reading");
    }
    fclose(fptr);
}

void getMetrix(char fileName[]) /* Read the file and passing its matrix data into a 2d Array */
{
    int i = 0;
    int j = 0;
    int lineNum = 1;
    FILE *fptr2;

    fptr2 = fopen(fileName, "r");
    if (fptr2 == NULL)
    {
        perror("Error: file can not open\n");
    }
    else
    {
        char line[100];
        while (fgets(line, sizeof(line), fptr2))
        {
            char *token;
            token = strtok(line, " "); /* Split by white spaces */
            while (token != NULL && lineNum > 1)
            {
                matrix[i][j] = atoi(token); /* Filling 2d array with text file data */
                j++;
                token = strtok(NULL, " ");
            }
            if (lineNum > 1)
            {
                i++;
                j = 0;
            }
            lineNum++;
        }
    }
    if (ferror(fptr2))
    {
        perror("Error while file reading");
    }
    fclose(fptr2);
}

void createMallocArray(int NumRows, int numCols) /* Creating a mallocd 2d array */
{
    int i;
    matrix = (int **)malloc(NumRows * sizeof(int *));
    for (i = 0; i < (NumRows + 1); i++)
    {
        matrix[i] = (int *)malloc(numCols * sizeof(int));
    }
}

int **returnMatrix(char fileName[]) /* Returning the 2d array */
{
    getRowsCols(fileName);
    createMallocArray(rows, columns);
    getMetrix(fileName);
    return matrix;
}

int getNumOfRows() /* Returning row count */
{
    return rows;
}

int getNumOfCols() /* Returning column count */
{
    return columns;
}