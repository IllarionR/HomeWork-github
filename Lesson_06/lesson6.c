
#include <stdio.h>
#include <cmath>

/*
void bubbleSort()
{
    const int SIZE = 3;
    int Array[SIZE][SIZE] = {{1, 9, 2}, {5, 7, 6}, {4, 3, 8}};

    int bufSIZE = SIZE*SIZE;
    int bufArray[bufSIZE] = {0};

    int buf = 0;

// печать исходного двумерного массива

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("%2d", Array[i][j]);
        }

        printf("\n");
    }

    printf("\n");

// преобразование исходного двумерного массива в одномерный

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            bufArray[(i*SIZE)+j] = Array[i][j];
        }
    }

// печать одномерного массива

    for(int i=0; i<bufSIZE; i++)
    {
        printf("%2d", bufArray[i]);
    }

    printf("\n\n");

// сортировка методом пузырька

    for(int i=0; i<(bufSIZE-1); i++)
    {
        for(int j=0; j<(bufSIZE-1-i); j++)
        {
            if(bufArray[j] > bufArray[j+1])
            {
                buf = bufArray[j]; bufArray[j] = bufArray[j+1]; bufArray[j+1] = buf;
            }
        }
    }

// печать отсортированного одномерного массива

    for(int i=0; i<bufSIZE; i++)
    {
        printf("%2d", bufArray[i]);
    }

    printf("\n\n");

// преобразование отсортированного одномерного массива в двумерный

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            Array[i][j] = bufArray[(i*SIZE)+j];
        }
    }

// печать отсортированного двумерного массива

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("%2d", Array[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}
*/


void printArray(int* array, const int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            printf("%2d", array[(i*size)+j]);
        }

        printf("\n");
    }

    printf("\n");
}



void bubbleSort(int* array, const int size)
{
    int bufSIZE = size*size;
    int buf = 0;

    for(int i=0; i<(bufSIZE-1); i++)
    {
        for(int j=0; j<(bufSIZE-1-i); j++)
        {
            if(array[j] > array[j+1])
            {
                buf = array[j]; array[j] = array[j+1]; array[j+1] = buf;
            }
        }
    }
}

//===================================================================================

void fillSequence(float Seq[], const int seqSize)
{
    printf("Enter %d numbers: ", seqSize);

    for(int i=0; i<seqSize; i++)
    {
        scanf("%f", &Seq[i]);
    }
}



void invertSequence(float Seq[], const int seqSize)
{
    float bufSeq = 0;

    for(int i=0; i<(seqSize/2); i++)
    {
        bufSeq = Seq[i]; Seq[i] = Seq[seqSize-1-i]; Seq[seqSize-1-i] = bufSeq;
    }
}



void printSequence(float Seq[], const int seqSize)
{
    printf("\n");

    for(int i=0; i<seqSize; i++)
    {
        printf("%f  ", Seq[i]);
    }

    printf("\n\n");
}



void calculateSequence(float Seq[], const int seqSize)
{
    float result = 0;

    for(int i=0; i<seqSize; i++)
    {
        result = sqrt(fabs(Seq[i]))+5*pow(Seq[i], 3);

        if(result > 400)
        {
            printf("For %f result more than 400 \n", Seq[i]);
        }
    }
}

//===================================================================================

int main()
{
    // bubbleSort();

    const int SIZE = 3;
    int Array[SIZE][SIZE] = {{1, 9, 2}, {5, 7, 6}, {4, 3, 8}};

    printArray(*Array, SIZE);
    bubbleSort(*Array, SIZE);
    printArray(*Array, SIZE);



    const int sequenceSize = 11;
    float Sequence[sequenceSize] = {0};

    fillSequence(Sequence, sequenceSize);
    invertSequence(Sequence, sequenceSize);
    printSequence(Sequence, sequenceSize);
    calculateSequence(Sequence, sequenceSize);



    return 0;
}
