
#include <stdio.h>
#include <stdlib.h>


void initArray(int* arr, const int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand()%101-50;
    }
}


void printArray(int* arr, const int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n");
}

//====================================================================

void improvedQuickSort(int* arr, int first, int last)
{
    int buf = 0;

    if((last-first) > 9) // быстрая сортировка
    {
        int f = first;
        int l = last;

        if(arr[f] > arr[(f+l)/2])
        {
            buf = arr[f]; arr[f] = arr[(f+l)/2]; arr[(f+l)/2] = buf;
        }

        if(arr[(f+l)/2] > arr[l])
        {
            buf = arr[(f+l)/2]; arr[(f+l)/2] = arr[l]; arr[l] = buf;
        }

        if(arr[f] > arr[(f+l)/2])
        {
            buf = arr[f]; arr[f] = arr[(f+l)/2]; arr[(f+l)/2] = buf;
        }

        int m = arr[(f+l)/2];

        while(f <= l)
        {
            while(arr[f] < m) f++;
            while(arr[l] > m) l--;

            if(f <= l)
            {
                buf = arr[f]; arr[f] = arr[l]; arr[l] = buf;

                f++;
                l--;
            }
        }

        if(f < last) improvedQuickSort(arr, f, last);
        if(first < l) improvedQuickSort(arr, first, l);
    }

    else // сортировка вставками
    {
        int index = 0;

        for(int i = first; i < last; i++)
        {
            buf = arr[i+1];
            index = i;

            while((buf < arr[index]) && (index >= first))
            {
                arr[index+1] = arr[index];
                index--;
            }

            arr[index+1] = buf;
        }
    }
}

//====================================================================

void blockSort(int* arr, int size)
{
    int b[size] = {0};
    int ind = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i]%2 == 0)
        {
            b[ind] = arr[i];
            ind++;
        }
    }



    int buf = 0;
    int index = 0;

    for(int i = 0; i < (ind-1); i++)
    {
        buf = b[i+1];
        index = i;

        while((buf < b[index]) && (index >= 0))
        {
            b[index+1] = b[index];
            index--;
        }

        b[index+1] = buf;
    }



    ind = 0;

    for(int i = 0; i < size; i++)
    {
        if(arr[i]%2 == 0)
        {
            arr[i] = b[ind];
            ind++;
        }
    }
}

//====================================================================

int main()
{
    const int SIZE = 30;
    int Array[SIZE] = {0};

    initArray(Array, SIZE);
    printArray(Array, SIZE);
    improvedQuickSort(Array, 0, SIZE-1);
    printArray(Array, SIZE);



    const int S = 12;
    int Arr[S] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};

    printArray(Arr, S);
    blockSort(Arr, S);
    printArray(Arr, S);


    return 0;
}
