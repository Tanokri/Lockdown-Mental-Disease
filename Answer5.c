//Given a list of length n (random integers), sort every third element. All other elements should remain untouched.

#include <stdio.h>
#include <stdlib.h>

int* sortEveryThirdElement(int *a, int n)
{
    int *temp_a = malloc(n);
    int b[n/3]; //array to store every third eleement
    int c[n-n/3]; //array to store the rest of the elements

    int j=0, k=0;
    for(int i =0;i<n;i++)
    {
        if((i+1)%3==0)
        {
            b[j]=a[i];
            j++;
        }
        else
        {
            c[k]=a[i];
            k++;
        }
    }

    int min = 0;
    for(int i =0; i<(n/3-1); i++)
    {
        min=i;
        for(int j =i+1;j<(n/3);j++)
        {
            if(b[j]<b[min])
            {
                min=j;
            }
        }
        int temp = b[i];
        b[i]=b[min];
        b[min]=temp;
    }

    int p=0;
    int q=0;
    for(int i=0;i<n;i++)
    {
        if((i+1)%3==0)
        {
            temp_a[i]=b[p];
            p++;
        }
        else
        {
            temp_a[i]=c[q];
            q++;
        }
    }

    return temp_a;
}
void main()
{   
    //initiallizing a random array
    int a[] = {1,2,10000,3,4,1000,5,6,100,7,8,10,9,11,10829};
    int n = sizeof(a) / sizeof(a[0]);

    int* result = sortEveryThirdElement(a,n);
    for(int i =0;i<n-1;i++)
    {
        printf("%d, ", result[i] );
    }
    printf("%d", result[n-1]);
}





//Now, given a value of k, print the k smallest elements among the untouched elements. n is the length of the array.

#include <stdio.h>
#include <stdlib.h>

void kSmallestAmongUntouched(int *a, int k, int n)
{
    if(k>n || k>n/3)
    {
        printf("Invalid input, k has to be less than n and less than n/3");
        return;
    }

    int c[n-n/3];
    int p=0;
    for(int i =0;i<n;i++)
    {
        if((i+1)%3!=0)
        {
            c[p]=a[i];
            p++;
        }
    }

    int min = 0;
    for(int i =0; i<(n-(n/3))-1; i++)
    {
        min=i;
        for(int j = i+1; j<(n-n/3); j++)
        {
            if(c[j]<=c[min])
            {
                min=j;
            }
        }
        int temp = c[i];
        c[i]=c[min];
        c[min]=temp;
    }

    int i =1;
    while(i<k)
    {
        printf("%d ", c[i]);
        i++;
    }
    printf("%d",c[i]);
}

void  main()
{   
    //input an array of your choice
    int a[] = {1,2,10000,3,4,1000,5,6,100,7,8,10,9,11,10829};
    int n = sizeof(a) / sizeof(a[0]);
    printf("Enter the number k smallest elements of the untouched part you want: \n");
    int k;
    scanf("%d", &k);
    kSmallestAmongUntouched(a,k,n);
}