
#include <stdio.h>
#include <cstdlib>


#define SIZE 10

typedef struct
{
    int priority;
    int data;
}
Element;

Element* arr[SIZE];

int tail = 0;


void initQueue()
{
    for(int i = 0; i < SIZE; i++)
    {
        arr[i] = NULL;
    }
}


void insert(int priority, int data)
{
    Element* element = (Element*) malloc(sizeof(Element));

    element->priority = priority;
    element->data = data;

    if(tail < SIZE)
    {
        arr[tail] = element;
        tail++;
    }

    else
    {
        printf("Queue is full \n");
    }
}


Element* remove()
{
    if(tail > 0)
    {
        int min = 0;

        for(int i = 0; i < (tail-1); i++)
        {
            if(arr[i+1]->priority < arr[min]->priority)
            {
                min = (i+1);
            }
        }

        Element* elementToRemove = arr[min];

        for(int i = min; i < (tail-1); i++)
        {
            arr[i] = arr[i+1];
        }

        arr[tail-1] = NULL;
        tail--;

        return elementToRemove;
    }

    else
    {
        printf("Queue is empty \n");

        return NULL;
    }
}


void printQueue()
{
    for(int i = 0; i < SIZE; i++)
    {
        if(arr[i] == NULL)
        {
            printf("[_, _] ");
        }

        else
        {
            printf("[%d, %d] ", arr[i]->priority, arr[i]->data);
        }
    }

    printf("\n");
}

//========================================================================

#define Size 100
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

int Stack[Size];
int pointer = -1;


boolean push(int bin)
{
    if(pointer < Size)
    {
        Stack[++pointer] = bin;
        return true;
    }

    else
    {
        printf("Stack overflow \n");
        return false;
    }
}


int pop()
{
    if(pointer != -1)
    {
        return Stack[pointer--];
    }

    else
    {
        printf("Stack is empty \n");
        return -1;
    }
}


void binary(int decimal)
{
    while(decimal > 0)
    {
        push(decimal%2);
        decimal = decimal/2;
    }
}

//========================================================================

int main()
{
    initQueue();

    insert(3, 10);
    insert(1, 20);
    insert(5, 30);
    insert(2, 40);
    insert(5, 50);
    insert(3, 60);
    insert(2, 70);
    insert(1, 80);
    insert(4, 90);
    insert(8, 100);

    printQueue();

    for(int i = 0; i < 7; i++)
    {
        Element* e = remove();
        printf("Removed element: [%d, %d]\n", e->priority, e->data);
    }

    printQueue();

    insert(4, 110);
    insert(7, 120);
    insert(6, 130);

    printQueue();

    for(int i = 0; i < 5; i++)
    {
        Element* e = remove();
        printf("Removed element: [%d, %d]\n", e->priority, e->data);
    }

    printQueue();

    // ******************************

    int dec;

    printf("Enter decimal number: ");
    scanf("%d", &dec);

    binary(dec);

    while(pointer != -1)
    {
        printf("%d", pop());
    }

    printf("\n");



    return 0;
}
