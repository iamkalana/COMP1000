#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int data[20];

void fileR(char fileName[])
{
    /* READ FILE */
    int lineNum = 0;
    int i = 1;
    FILE *fptr;
    fptr = fopen(fileName, "r");
    if (fptr == NULL)
    {
        perror("Error: file can not open\n");
    }
    else
    {
        char line[100];
        while (fgets(line, sizeof(line), fptr))
        {
            char *token;
            token = strtok(line, " ");
            while (token != NULL)
            {
                data[i] = atoi(token);
                i++;

                token = strtok(NULL, " ");
            }
            lineNum++;
        }
    }
    data[0] = lineNum - 1;
    fclose(fptr);
}

int snakeLength(void)
{
    int length = data[0];
    return length;
}

int getRows(void)
{
    int rows = data[1];
    return rows;
}

int getCols(void)
{
    int columns = data[2];
    return columns;
}