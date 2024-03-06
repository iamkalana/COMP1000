#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct LinkedListNode
{
    int data;
    int row;
    int column;
    struct LinkedListNode *next;
} LinkedListNode;
typedef struct
{
    LinkedListNode *head;
} LinkedList;

LinkedList *list;

void createList()
{
    list = (LinkedList *)malloc(sizeof(LinkedList));
    (*list).head = NULL;
}
void insertFirst(int inRow, int inColumn,int inData)
{
    struct LinkedListNode *temp = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
    if (temp != NULL)
    {
        temp->row = inRow;
        temp->column = inColumn;
        temp->data = inData;
        temp->next = NULL;
        if (list->head == NULL)
        {
            list->head = temp;
        }
        else
        {
            temp->next = list->head;
            list->head = temp;
        }
    }
}

void insertLast(int inRow, int inColumn,int inData)
{
    struct LinkedListNode *p;
    struct LinkedListNode *temp = (struct LinkedListNode *)malloc(sizeof(struct LinkedListNode));
    if (temp != NULL)
    {
        temp->row = inRow;
        temp->column = inColumn;
        temp->data = inData;
        temp->next = NULL;
        if (list->head == NULL)
        {
            list->head = temp;
        }
        else
        {
            p = list->head;
            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;
        }
    }
}

void display()
{
    struct LinkedListNode *p;
    if (list->head != NULL)
    {
        p = list->head;
        printf("Linked List: \n");
        while (p != NULL)
        {
            printf("%d %d %d \n", p->row, p->column, p->data);
            p = p->next;
        }
    }
    printf("\n");
}

int getData(int inRow, int inCol)
{
    int found = 0;
    int data;
    struct LinkedListNode *p;
    if (list->head != NULL)
    {
        p = list->head;
        while (p != NULL)
        {
            if ((p->row == inRow) && (p->column == inCol))
            {
                data = p->data;
                found = 1;
            }
            p = p->next;
        }
    }
    if(found == 0){
        printf("Not found! ");
    } 
    return data;
}

void setData(int inRow, int inCol, int inData)
{
    int found = 0;
    struct LinkedListNode *p;
    if (list->head != NULL)
    {
        p = list->head;
        while (p != NULL)
        {
            if ((p->row == inRow) && (p->column == inCol))
            {
                p->data = inData;
                found = 1;
            }
            p = p->next;
        }
    }
    if(found == 0){
        printf("Not found! ");
    }
}

void freeNode(LinkedListNode *node)
{
    if (node != NULL)
    {
        freeNode((*node).next);
        free(node);
    }
}

void freeLinkedList()
{
    freeNode(list->head);
    free(list);
}

/* int main(void)
{
    createList();
    insertLast(0,1,20);
    insertLast(0,2,98);
    insertLast(3,6,34);
    insertLast(2,7,50);
    display();
    return 0;
} */