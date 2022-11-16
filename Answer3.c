//Given an array with n unique integers, produce a Reverse BST.Here,the left child is always larger and the right child is always smaller (opposite of a normal BST). Then, print the elements in prefix order (root, left child, right child).

#include <stdio.h>
#include <stdlib.h>

//defining a tree node
typedef struct NodeAddress
{
    int val;
    struct NodeAddress *left;
    struct NodeAddress *right;
    struct NodeAddress *parent;
} NodeAddress;

//creating a tree node
NodeAddress *createNode(int val)
{
    NodeAddress *newNode = (NodeAddress *)malloc(sizeof(NodeAddress));
    newNode->val = val; 
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

//converting the array to a reverse tree (left child is always larger and right child is always smaller)
NodeAddress *arrayToReverseBST(int *a, int n)
{
    NodeAddress *root = createNode(a[0]);
    NodeAddress *current = root;
    for (int i = 1; i < n; i++)
    {
        current = root;
        while (current != NULL)
        {
            if (a[i] > current->val)
            {
                if (current->left == NULL)
                {
                    //assigning the left child if it is larger than the parent
                    current->left = createNode(a[i]);
                    current->left->parent = current;
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            else if (a[i] < current->val)
            {
                //assigning the right child if it is smaller than the parent
                if (current->right == NULL)
                {
                    current->right = createNode(a[i]);
                    current->right->parent = current;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
            {
                //assigning the right child if it is smaller than the parent
                if (current->right == NULL)
                {
                    current->right = createNode(a[i]);
                    current->right->parent = current;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }
    return root;
}

//printing the tree in prefix order (root, left child, right child)
void prefixPrint(NodeAddress *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        prefixPrint(root->left);
        prefixPrint(root->right);
    }
}

void main()
{
    //initiallizing a random array
    int a[] = {398, 793, 748, 749, 38, 8929, 19};
    int n = sizeof(a) / sizeof(a[0]);
    NodeAddress *root = arrayToReverseBST(a, n);
    prefixPrint(root);
}





//Given an integer k, print the next largest element (successor) in the Reverse BST. If k does not exist in this BST, print "Pudding" and if k’s successor does not exist in this BST, print "Hamburger".

#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int val;
    struct node *left;
    struct node *right;
};

typedef struct node * NodeAddress;

NodeAddress insert(NodeAddress root, int val)
{
    if (root == NULL)
    {
        root = (NodeAddress)malloc(sizeof(struct node));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
    } 
    else 
    {
        if (val < root->val)
        {
            root->right = insert(root->right, val);
        }
        else 
        {
            root->left = insert(root->left, val);
        }
    }
    return root;
}

NodeAddress arrayToBST(int *a, int n)
{
    NodeAddress root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, *a);
        a+=1;
    }
    return root;
}

void prefixPrint(NodeAddress root)
{
    if (root != NULL)
    {
        prefixPrint(root->left);
        printf("%d ", root->val);
        prefixPrint(root->right);
    }
}

void successorReverseBST(NodeAddress root, int k)
{
    NodeAddress temp = root;
    NodeAddress successor = NULL;
    int flag = -1;
    while (temp != NULL)
    {
        if (temp->val == k)
        {
            flag = 1;
        }
        if (temp->val > k)
        {
            successor = temp;
            temp = temp->right;
        } 
        else 
        {
            temp = temp->right;
        }
    }
    if (flag == -1)
    {
        printf("Pudding\n");
    }
    else if (successor == NULL)
    {
        printf("Hamburger\n ");
    }
    else 
    {
        printf("Successor element is: %d", successor->val);
    }
}


int main()
{
    //initiallizing a random array
    int a[] = {398, 793, 748, 749, 38, 8929, 19};
    int n = sizeof(a)/sizeof(a[0]);
    NodeAddress head = arrayToBST(a, n);
    prefixPrint(head);
    printf("\n");
    int k;
    printf("Enter a number: ");
    scanf("%d", &k);
    successorReverseBST(head, k);
    return 0;
}





//Given any two integers x and y in the Reverse BST, find the distance between the two in sorted order. That is, count how many numbers lie in between these two integers x and y. If x, y or both x and y don’t exist in the BST, return -1.

#include <stdio.h>
#include <stdlib.h>

//defining a tree node
typedef struct NodeAddress
{
    int val;
    struct NodeAddress *left;
    struct NodeAddress *right;
    struct NodeAddress *parent;
} NodeAddress;

//creating a tree node
NodeAddress *createNode(int val)
{
    NodeAddress *newNode = (NodeAddress *)malloc(sizeof(NodeAddress));
    newNode->val = val; 
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

//converting the array to a reverse tree (left child is always larger and right child is always smaller)
NodeAddress *arrayToReverseBST(int *a, int n)
{
    NodeAddress *root = createNode(a[0]);
    NodeAddress *current = root;
    for (int i = 1; i < n; i++)
    {
        current = root;
        while (current != NULL)
        {
            if (a[i] > current->val)
            {
                if (current->left == NULL)
                {
                    //assigning the left child if it is larger than the parent
                    current->left = createNode(a[i]);
                    current->left->parent = current;
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            else
            {
                //assigning the right child if it is smaller than the parent
                if (current->right == NULL)
                {
                    current->right = createNode(a[i]);
                    current->right->parent = current;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }
    return root;
}

//sorting the reverse binary tree in ascending order
void sortReverseBST(NodeAddress *root)
{
    if (root == NULL)
    {
        return;
    }
    sortReverseBST(root->right);
    sortReverseBST(root->left);
}

//print values in the tree
void printTree(NodeAddress *root)
{
    if (root == NULL)
    {
        return;
    }
    printTree(root->right);
    printf("%d ", root->val);
    printTree(root->left);
}

//finding number of elements in the tree
int NumberOfElements(NodeAddress *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + NumberOfElements(root->left) + NumberOfElements(root->right);
}

//converting the tree to an array
void treeToArray(NodeAddress *root, int *a, int *i)
{
    if (root == NULL)
    {
        return;
    }
    treeToArray(root->right, a, i);
    a[*i] = root->val;
    *i = *i + 1;
    treeToArray(root->left, a, i);
}

//print the array
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//finding the distance between two integers in the reverse binary tree
int findDistance(NodeAddress *root, int x, int y)
{   
    int d = 0;
    int m = NumberOfElements(root);
    int b[m];
    int i = 0;
    treeToArray(root, b, &i);
    //printArray(b, m);

    int pc = -1;
    int pc1 = -1;

    //swapping x and y if x is larger than y
    if (x > y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    for(int i=0; i<m; i++)
    {   
        if(b[i] == x)
        {
            pc = i;
        }
        if(b[i] == y)
        {
            pc1 = i;
        }
    }
    d = pc1 - pc;

    return d;
}



void main()
{
    //ititializing a random array
    int a[] = {5,3,7,2,4,6,8,1};
    int n = sizeof(a) / sizeof(a[0]);
    NodeAddress *root = arrayToReverseBST(a, n);
    
    sortReverseBST(root);
    //printTree(root);

    //user input
    int x,y;
    printf("Enter the element 1: ");
    scanf("%d", &x);
    printf("Enter the element 2: ");
    scanf("%d", &y);
    int d= findDistance(root, x, y);
    printf("The distance between %d and %d is: %d\n", x, y, d);
}