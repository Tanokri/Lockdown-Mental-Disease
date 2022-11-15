//Write a program which inputs an integer x and prints “fizz” if it’s divisible by 3 or 5, prints “buzz” if it’s divisible by 11 or 13, and prints “fizzbuzz” if it’s divisible by 33, 39,55, or 65. It should print the integer itself in all other cases.
#include <stdio.h>

void basicFizzBuzz(int x)
{
    if (x % 33 == 0 || x % 39 == 0 || x % 55 == 0 || x % 65 == 0)
    {
        printf("fizzbuzz");
    }
    else if (x % 3 == 0 || x % 5 == 0)
    {
        printf("fizz");
    }
    else if (x % 11 == 0 || x % 13 == 0)
    {
        printf("buzz");
    }
    else
    {
        printf("%d", x);
    }
}

void main()
{
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    basicFizzBuzz(x);
}
    




//Assume you have an array f of length nf, and an array b of length nb, each con- taining the integers you need to check for to print fizz and buzz. So, for each integer in your input array a of length m, you need to check if it’s divisible by something in f. If so, you should print “fizz”; if it’s divisible by something in b, you should print “buzz”; and if it is divisible by something in f and b, you should print “fizzbuzz”. (The previous question has f = [3,5] and b = [11,13], and both nf and nb are 2.) You may assume there are no repetitions in the arrays and nothing appears in both.

#include <stdio.h>

void advancedFizzBuzz(int *a,int m,int *b,int nb,int *f,int nf) 
{
    int i,j;
    for (i = 0; i < m; i++)
    {
        int fizz = 0;
        int buzz = 0;

        //checking if something is divisible in array f
        for (j = 0; j < nf; j++)
        {
            if (a[i] % f[j] == 0)
            {
                buzz = 1;
            }
        }

        //checking if something is divisible in array b
        for (j = 0; j < nb; j++)
        {
            if (a[i] % b[j] == 0)
            {
                fizz = 1;
            }
        }

        if (fizz == 1 && buzz == 1)
        {
            printf("fizzbuzz\n");
        }
        else if (fizz == 1)
        {
            printf("fizz\n");
        }
        else if (buzz == 1)
        {
            printf("buzz\n");
        }
    }
}
void main()
{
    int a[5] = {39, 22, 15, 1, 2};
    int b[2] = {11,13};
    int f[2] = {3,5};
    advancedFizzBuzz(a,5,b,2,f,2);
}






