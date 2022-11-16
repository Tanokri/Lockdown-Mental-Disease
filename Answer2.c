//Consider a linked list with three fields: val, next, and next2. Here, next2 points two nodes ahead, i.e., next next. Given an array with n elements, convert it into such a linked list. All pointers should work correctly for full credit.

#include <stdio.h>
#include <stdlib.h>

struct NodeAddress
{
    int val;
    struct NodeAddress *next;
    struct NodeAddress *next2;
} NodeAddress;

void displayListWithNode(struct NodeAddress *root,int n)
{
    printf("-----------------------------------------\n");
    printf("Printing the linked list pointer elements:\n");
    int i =0;
    while(root!=NULL)
    {   
        if(i!=n)
        {
            printf("%d \t ", root->val);
        }
        root=root->next;
        i++;
        if(i == n)
        {
            printf("NULL/0\n");
        }
    }
}

void arrayToLLWithNext2(int a[], int n)
{
    
    struct NodeAddress *root = malloc(sizeof(struct NodeAddress));
    root->next = NULL;
    root->next2 = NULL;
    root->val = a[0];
    for(int i = 1; i<n; i++)
    {
        struct NodeAddress *temp = malloc(sizeof(struct NodeAddress));
        struct NodeAddress *ptr = malloc(sizeof(struct NodeAddress));
        temp->next = NULL;
        temp->val = a[i];
        ptr = root;

        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
    
    displayListWithNode(root,n);
    
    struct NodeAddress *nextptr = malloc(sizeof(struct NodeAddress));
    struct NodeAddress *ptr = malloc(sizeof(struct NodeAddress));
    ptr = root;

    while(ptr->next!=NULL)
    {
        nextptr = ptr->next;
        ptr->next2 = nextptr->next;
        ptr = ptr->next;
    }
    ptr->next2=NULL;
    
    printf("-----------------------------------------\n");
    printf("Printing the linked list next2 pointer elements:\n");
    ptr=root;
    int i =0;

    while(ptr!=NULL)
    {   
        if(i!=n)
        {
            if(ptr->next2!=NULL)
            {
                printf("%d \t ", ptr->next2->val);
            }
            else
            {
                printf("NULL/0 \t ");
            }
        }
        ptr=ptr->next;
        i++;
        if(i == n)
        {
            printf("NULL/0\n");
        }
    }

    printf("-----------------------------------------\n");

}

void main()
{   
    int a[5] = {11, 22, 33, 44, 55};
    //printing the given array
    printf("-----------------------------------------\n");
    printf("The given array is: \n");
    for(int i = 0; i < 5; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    arrayToLLWithNext2(a,5);
}





//Given the head pointer of such a list, write a function to reverse the list.

#include <stdio.h>
#include <stdlib.h>

struct NodeAddress
{
    int val;
    struct NodeAddressAddress* next;
    struct NodeAddress* next2;
} NodeAddress;

int n;

void displayListWithNode(struct NodeAddress *root,int n)
{
    printf("-----------------------------------------\n");
    printf("Printing the linked list pointer elements:\n");
    int i =0;
    while(root!=NULL)
    {   
        if(i!=n)
        {
            printf("%d  ", root->val);
        }
        root=root->next;
        i++;
        if(i == n)
        {
            printf("NULL/0\n");
        }
    }
}

struct NodeAddress *reverseLLWithNext2(struct NodeAddress *head)
{
    struct NodeAddress* current = head;
    struct NodeAddress* previous = NULL;
    struct NodeAddress* next = NULL;

    while(current!= NULL)
    {
        next = current->next;
        current->next = previous;
        
        previous = current;
        current = next;
    }
    head = previous;

    struct NodeAddress *nextptr = malloc(sizeof(struct NodeAddress));
    struct NodeAddress *ptr = malloc(sizeof(struct NodeAddress));
    ptr=head;
    while(ptr->next!=NULL)
    {
        nextptr=ptr->next;
        ptr->next2=nextptr->next;
        ptr=ptr->next;
    }
    ptr->next2=NULL;

    printf("Reversed linked list with next2 pointers\n");
    ptr=head;
    int i =0;
    while(ptr!=NULL)
    {
        printf("%d", ptr->val);
        if(ptr->next2!=NULL)
        {
            printf(" pointer next2 = %d\n", ptr->next2->val); 
            printf("");
        }
        else
        printf(" pointer next2 = NULL/0\n"); 
        if(ptr->next!=NULL)
        {
            printf("");
        }
        
        ptr=ptr->next;
        
    }
    printf("NULL/0\n");
    printf("-----------------------------------------\n");
}

void arrayToLLWithNext2(int a[], int n)
{
    
    struct NodeAddress *root = malloc(sizeof(struct NodeAddress));
    root->next = NULL;
    root->next2 = NULL;
    root->val = a[0];
    for(int i = 1; i<n; i++)
    {
        struct NodeAddress *temp = malloc(sizeof(struct NodeAddress));
        struct NodeAddress *ptr = malloc(sizeof(struct NodeAddress));
        temp->next = NULL;
        temp->val = a[i];
        ptr = root;

        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
    
    displayListWithNode(root,n);
    
    struct NodeAddress *nextptr = malloc(sizeof(struct NodeAddress));
    struct NodeAddress *ptr = malloc(sizeof(struct NodeAddress));
    ptr = root;

    while(ptr->next!=NULL)
    {
        nextptr = ptr->next;
        ptr->next2 = nextptr->next;
        ptr = ptr->next;
    }
    ptr->next2=NULL;
    
    printf("-----------------------------------------\n");
    printf("Printing the linked list next2 pointer elements:\n");
    ptr=root;
    int i =0;

    while(ptr!=NULL)
    {   
        if(i!=n)
        {
            if(ptr->next2!=NULL)
            {
                printf("%d  ", ptr->next2->val);
            }
            else
            {
                printf("NULL/0  ");
            }
        }
        ptr=ptr->next;
        i++;
        if(i == n)
        {
            printf("NULL/0\n");
        }
    }

    printf("-----------------------------------------\n");

    struct node *reverseLLWithNextTwo = reverseLLWithNext2(root);

}

void main()
{   
    int a[5] = {11, 22, 33, 44, 55};
    //printing the given array
    printf("-----------------------------------------\n");
    printf("The given array is: \n");
    for(int i = 0; i < 5; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n");
    arrayToLLWithNext2(a,5);
}





//Now, we have four fields: val, next, k and nextk. Given a value for k, nextk points k nodes ahead. (So the previous question merely had k=2, and a normal linked list has k=1.) k is essentially a look-ahead. We want you to generate a random value of k for EACH NodeAddress. k only takes values between 2 and 5 (both included). You can use a C random library for this, no issue. If at any point k overshoots the list i.e. k dictates that nextk points at an element beyond the list, nextk should just be Null. Given an array with n elements, convert it into such a linked list. All pointers should work correctly for full credit.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NodeAddress
{
    int val;
    struct NodeAddress* next;
    int k;
    struct NodeAddress* nextk;
} NodeAddress;

void displayListWithNode(struct NodeAddress *root,int n)
{
    printf("-----------------------------------------\n");
    printf("Printing the linked list pointer elements:\n");
    int i =0;
    while(root!=NULL)
    {   
        if(i!=n)
        {
            printf("%d  ", root->val);
        }
        root=root->next;
        i++;
        if(i == n)
        {
            printf("NULL/0\n");
        }
    }
}


void arrayToLLWithNextK(int a[], int n)
{
    struct NodeAddress* root = malloc(sizeof(struct NodeAddress));
    root->val=a[0];
    root->next=NULL;
    root->nextk=NULL;
    for(int i =1;i<n;i++)
    {
        struct NodeAddress *temp = malloc(sizeof(struct NodeAddress));
        struct NodeAddress *ptr = malloc(sizeof(struct NodeAddress));
        temp->next = NULL;
        temp->val = a[i];
        ptr = root;

        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
    displayListWithNode(root,n);
    
    struct NodeAddress *nextk= malloc(sizeof(struct NodeAddress));
    struct NodeAddress *ptr= malloc(sizeof(struct NodeAddress));
    struct NodeAddress *ptr1 = malloc(sizeof(struct NodeAddress));
    ptr=root;
    while(ptr->next!=NULL)
    {
        ptr1=ptr; 
        int k;
        k = rand()%4+2; //generates a random number between 2 and 5
        ptr->k=k; //assigns the random number to k
        int flag = -1; 
        for(int i =1; i<=k ;i++) //loop to find the nextk node
        {
            if(ptr1->next!=NULL)
            {
                ptr1=ptr1->next;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            ptr->nextk=NULL;
            ptr=ptr->next;
            
        }
        else
        {
            ptr->nextk=ptr1;
            ptr=ptr->next;
        }
    }
    ptr->nextk = NULL;
    
    printf("-----------------------------------------\n");
    printf("Printing the linked list pointer elements:\n");
    ptr=root;
    int i =0;
    while(ptr!=NULL)
    {
        if (i!=n)
        {
            printf("%d", ptr->val);
        }
        else
        {
            printf("NULL/0\n");
        }
        if(ptr->nextk!=NULL)
        {
            printf(" pointer nextk = %d\n", ptr->nextk->val);
            printf("");
        }
        else
        printf(" pointer nextk = NULL/0\n"); 
        if(ptr->next!=NULL)
        {
            printf("");
        }
        
        ptr=ptr->next;
    }
    printf("-----------------------------------------\n");
}

void main()
{   
    srand(time(0));
    int a[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 111};
    //printing the given array
    printf("-----------------------------------------\n");
    printf("The given array is: \n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
    arrayToLLWithNextK(a,10);
}





//Given the Head pointer of such a list, write a function to reverse the list.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NodeAddress
{
    int val;
    struct NodeAddress* next;
    int k;
    struct NodeAddress* nextk;
}NodeAddress;

void displayListWithNode(struct NodeAddress *root,int n)
{
    printf("-----------------------------------------\n");
    printf("Printing the linked list pointer elements:\n");
    int i =0;
    while(root!=NULL)
    {   
        if(i!=n)
        {
            printf("%d  ", root->val);
        }
        root=root->next;
        i++;
        if(i == n)
        {
            printf("NULL/0\n");
        }
    }
}

struct NodeAddress* reverseLLWithNextk(struct NodeAddress* head)
{
    struct NodeAddress* current = head;
    struct NodeAddress* previous = NULL;
    struct NodeAddress* next = NULL;

    while(current!=NULL)//reverse the linked list
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head=previous;

    struct NodeAddress* nextptr= malloc(sizeof(struct NodeAddress));
    struct NodeAddress* ptr= malloc(sizeof(struct NodeAddress));
    struct NodeAddress* ptr1 = malloc(sizeof(struct NodeAddress));
    ptr=head;
    ptr1=ptr;

    for(int i = 1; i<=ptr->k; i++)
    {
        ptr1=ptr1->next;
    }

    ptr->nextk=ptr1;
    ptr=ptr->next;

    int flag=-1;
    while(ptr->next!=NULL)
    {
        ptr1=ptr;
        for(int i =1;i<=ptr->k;i++)
        {
            if(ptr1->next!=NULL)
            {
                ptr1=ptr1->next;
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            ptr->nextk=NULL;
            ptr=ptr->next;
        }
        else
        {
            ptr->nextk=ptr1;
            ptr=ptr->next;
        }
    }
    ptr->nextk=NULL;
    
    printf("Reverse linked list with new pointer elements:\n");
    while(head!=NULL)
    {

        printf("%d ", head->val);
        if(head->nextk == NULL)
        {
            printf("pointer nextk = NULL/0");
        }
        else
        {
            printf("pointer nextk = %d", head->nextk->val);
        }

        if(head->next!=NULL)
        {   
            printf("\n");
        }
        head=head->next;
    }
    printf("\n-----------------------------------------\n");
}

void arrayToLLWithNextK(int a[], int n)
{
    struct NodeAddress* root = malloc(sizeof(struct NodeAddress));
    root->val=a[0];
    root->next=NULL;
    root->nextk=NULL;
    for(int i =1;i<n;i++)
    {
        struct NodeAddress *temp = malloc(sizeof(struct NodeAddress));
        struct NodeAddress *ptr = malloc(sizeof(struct NodeAddress));
        temp->next = NULL;
        temp->val = a[i];
        ptr = root;

        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
    displayListWithNode(root,n);
    
    struct NodeAddress *nextk= malloc(sizeof(struct NodeAddress));
    struct NodeAddress *ptr= malloc(sizeof(struct NodeAddress));
    struct NodeAddress *ptr1 = malloc(sizeof(struct NodeAddress));
    ptr=root;
    while(ptr->next!=NULL)
    {
        ptr1=ptr; 
        int k;
        k = rand()%4+2; //generates a random number between 2 and 5
        ptr->k=k; //assigns the random number to k
        int flag = -1; 
        for(int i =1; i<=k ;i++) //loop to find the nextk node
        {
            if(ptr1->next!=NULL)
            {
                ptr1=ptr1->next;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
        {
            ptr->nextk=NULL;
            ptr=ptr->next;
            
        }
        else
        {
            ptr->nextk=ptr1;
            ptr=ptr->next;
        }
    }
    ptr->nextk = NULL;
    
    printf("-----------------------------------------\n");
    printf("Printing the linked list pointer elements:\n");
    ptr=root;
    int i =0;
    while(ptr!=NULL)
    {
        if (i!=n)
        {
            printf("%d", ptr->val);
        }
        else
        {
            printf("NULL/0\n");
        }
        if(ptr->nextk!=NULL)
        {
            printf(" pointer nextk = %d\n", ptr->nextk->val);
            printf("");
        }
        else
        printf(" pointer nextk = NULL/0\n"); 
        if(ptr->next!=NULL)
        {
            printf("");
        }
        
        ptr=ptr->next;
    }
    printf("-----------------------------------------\n");
    struct NodeAddress* reverseLLWithNextK = reverseLLWithNextk(root);
}

void main()
{   
    srand(time(0));
    int a[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 111};
    //printing the given array
    printf("-----------------------------------------\n");
    printf("The given array is: \n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
    arrayToLLWithNextK(a,10);
}