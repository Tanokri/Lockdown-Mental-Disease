//Given a max heap, print the third largest number. n is the size of the heap.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void thirdLargestNumber(int* maxHeap,int n)
{
    int f1,f2;
    if(n<3)
    {
      printf("Not enough elements in the heap\n");
      exit(0);
    }

    f1 = maxHeap[1];//first largest
    f2 = maxHeap[2];//second largest
    
    printf("The third largest number is: ");
    if(f1>f2)
    {
        printf("%d",f2);
    }

    else if(f1<f2)
    {
       printf("%d",f1);
    }

    else
    {  
        int temp = 0;
        for(int i=3; i<n; i++)
        {
         int d = maxHeap[i];
         if(d>=temp)
         {
            temp = d;
         }
        }
        printf("%d",temp);
    }
}
void main()
{   
    int n;
    printf("Enter the size of the heap: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the heap:-\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter an element: ");
        scanf("%d",&a[i]);
    }
  
    thirdLargestNumber(a,n);

}





#include <stdio.h>

void returnSmallestNum(int* maxHeap, int n)
{
    int b = n/2;
    int temp;
    temp= maxHeap[b];
    b++;

    while(b<n)
    {
       if(temp>maxHeap[b])
       {
        temp = maxHeap[b];
       }
       b++;
    }
    printf("The smallest number in the heap is: ");
    printf("%d",temp);
}

void main ()
{
    int n;
    printf("Enter the size of the heap: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the heap:-\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter an element: ");
        scanf("%d",&a[i]);
    }
  
    returnSmallestNum(a,n);
}