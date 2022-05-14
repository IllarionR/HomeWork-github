
#include <stdio.h>


int binary(int decimal)
{
    if(decimal > 1)
    {
        binary(decimal/2);
    }

    printf("%d", decimal%2);

    return decimal;
}

//=====================================================================

int degree(int base, int exponent)
{
    if(exponent != 0) return degree(base, exponent-1)*base;
    else              return 1;
}

//=====================================================================

int degree_2(int Base, int Exponent)
{
    if(Exponent != 0)
    {
        if((Exponent%2) != 0) return degree_2(Base, Exponent-1)*Base;
        else                  return degree_2(Base*Base, Exponent/2);
    }

    else return 1;
}

//=====================================================================

void routes()
{
    const int SIZE = 8;
    int Routes[SIZE][SIZE] = {0},
        Obstacles[SIZE][SIZE] = {{0, 1, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 1, 0, 1, 0},
                                 {0, 0, 1, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {1, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 1, 0, 0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0}};

    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("%2d", Obstacles[i][j]);
        }

        printf("\n");
    }

    printf("\n");



    Routes[0][0] = 0; // стартовая позиция короля

    if(Obstacles[0][1]==1) Routes[0][1] = 0;
    else                   Routes[0][1] = 1;

    if(Obstacles[1][0]==1) Routes[1][0] = 0;
    else                   Routes[1][0] = 1;


    for(int j=2; j<SIZE; j++) // для нулевой строки
    {
        if(Obstacles[0][j]==1) Routes[0][j] = 0;
        else                   Routes[0][j] = Routes[0][j-1];
    }

    for(int i=2; i<SIZE; i++) // для нулевого столбца
    {
        if(Obstacles[i][0]==1) Routes[i][0] = 0;
        else                   Routes[i][0] = Routes[i-1][0];
    }

    for(int i=1; i<SIZE; i++) // для остальных клеток
    {
        for(int j=1; j<SIZE; j++)
        {
            if(Obstacles[i][j]==1) Routes[i][j] = 0;
            else                   Routes[i][j] = Routes[i-1][j] + Routes[i][j-1];
        }
    }



    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            printf("%6d", Routes[i][j]);
        }

        printf("\n\n");
    }

}

//=====================================================================

int main()
{
    int dec;
    printf("Enter decimal number: ");
    scanf("%d", &dec);
    binary(dec);
    printf("\n");

    int b, e;
    printf("Enter base: ");
    scanf("%d", &b);
    printf("Enter exponent: ");
    scanf("%d", &e);
    printf("degree= %d \n", degree(b, e));

    int B, E;
    printf("Enter Base: ");
    scanf("%d", &B);
    printf("Enter Exponent: ");
    scanf("%d", &E);
    printf("Degree= %d \n", degree_2(B, E));

    routes();

    return 0;
}
