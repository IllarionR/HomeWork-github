
#include <stdio.h>

void prime()
{
    float n, dif;
    unsigned int sum = 0;

    printf("Enter a number: ");
    scanf("%f", &n);

    dif = n - int(n); // вычтем целую часть

//    printf("dif= %f \n", dif);

    if((!(dif==0))||(n<=0))                      // если разница не равна нулю, т.е. введенное число n не целое
    {                                            // или (и) оно отрицательное, то n не является простым числом
        printf("%f is not a prime number \n", n);
    }

    else
    {
        for(unsigned int i=1; i<=n; i++)
        {                                     // любое число делится на 1 и на само себя без остатка,
            if(((unsigned int)n%i)==0) sum++; // но если оно делится еще на какое-то число без остатка,
        }                                     // то оно не является простым

//        printf("sum= %d \n", sum);

        if(sum==2) printf("%f is a prime number \n", n);
        else       printf("%f is not a prime number \n", n);
    }
}

int main()
{
    prime();

    return 0;
}
