#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_PEOPLE 10
#define MAX_TRANSACTIONS 100

// Data structure to represent a transaction between two people
typedef struct
{
	int from;  // index of person who owes the money
	int to;    // index of person who is owed the money
	int amount; // amount of money involved in the transaction
} Transaction;

// Data structure to represent a node in the graph
typedef struct Node
{
	int index;       // index of the person in the graph
	int balance;     // balance of the person (positive if they owe money, negative if they are owed money)
	struct Node *next; // pointer to the next node in the list
} Node;

// Data structure to represent a linked list
typedef struct
{
	Node *head; // pointer to the head of the list
} LinkedList;

// Data structure to represent a graph
typedef struct
{
	LinkedList adjList[MAX_PEOPLE]; // adjacency list for each person in the graph
	int numPeople; // number of people in the graph
} Graph;

// Function to add a transaction to the graph
void addTransaction(Graph *g, Transaction t)
{
	int from = t.from;
	int to = t.to;
	int amount = t.amount;

	// add the amount to the balance of the person who owes the money
	g->adjList[from].head->balance += amount;

	// subtract the amount from the balance of the person who is owed the money
	g->adjList[to].head->balance -= amount;
}

// Function to create a new node in the linked list
Node *createNode(int index)
{
	Node *node = (Node*)malloc(sizeof(Node));
	node->index = index;
	node->balance = 0;
	node->next = NULL;

	return node;
}

// Function to add a node to the linked list
void addNode(LinkedList *list, Node *node)
{
	node->next = list->head;
	list->head = node;
}

// Function to create a graph with the given number of people
Graph createGraph(int numPeople)
{
	Graph g;
	g.numPeople = numPeople;

	// create a linked list for each person in the graph
	for (int i = 0; i < numPeople; i++)
	{
		Node *node = createNode(i);
		addNode(&g.adjList[i], node);
	}

	return g;
}

// Function to find the person with the maximum balance
int findMaxBalance(Graph g)
{
	int maxIndex = -1;
	int maxBalance = 0;

	// iterate through each person in the graph
	for (int i = 0; i < g.numPeople; i++)
	{
		Node *node = g.adjList[i].head;
int balance = node->balance;
// update the maximum balance and index if necessary
	if (balance > maxBalance)
	{
		maxBalance = balance;
		maxIndex = i;
	}
}

return maxIndex;
}

// Function to print the most efficient way to settle all debts
void settleDebts(Graph g)
{
// continue until all debts are settled
while (1)
{
// find the person with the maximum balance
int maxIndex = findMaxBalance(g);
if (maxIndex == -1)
break;

	Node *maxNode = g.adjList[maxIndex].head;
	int maxBalance = maxNode->balance;

	// find the person with the minimum balance
	int minIndex = -1;
	int minBalance = 0;

	for (int i = 0; i < g.numPeople; i++)
	{
		if (i == maxIndex)
			continue;

		Node *node = g.adjList[i].head;
		int balance = node->balance;

		// update the minimum balance and index if necessary
		if (balance < minBalance)
		{
			minBalance = balance;
			minIndex = i;
		}
	}

	// if there is a person with a negative balance, pay them back
	if (minIndex != -1)
	{
		Node *minNode = g.adjList[minIndex].head;
		int amount = (maxBalance < -minBalance) ? maxBalance : -minBalance;

		// update the balances of both people
		maxNode->balance -= amount;
		minNode->balance += amount;

		// print the transaction
		printf("Person %d pays Person %d %d Rs\n", maxIndex, minIndex, amount);
	}
	// if there are no people with a negative balance, find the person with the least positive balance
	else
	{
		minIndex = -1;
		minBalance = INT_MAX;

		for (int i = 0; i < g.numPeople; i++)
		{
			if (i == maxIndex)
				continue;

			Node *node = g.adjList[i].head;
			int balance = node->balance;

			// update the minimum balance and index if necessary
			if (balance > 0 && balance < minBalance)
			{
				minBalance = balance;
				minIndex = i;
			}
		}

		// if there is a person with a positive balance, pay them back
		if (minIndex != -1)
		{
			Node *minNode = g.adjList[minIndex].head;
			int amount = (maxBalance < minBalance) ? maxBalance : minBalance;

			
// update the balances of both people
maxNode->balance -= amount;
minNode->balance += amount;
			// print the transaction
			printf("P%d pays P%d %d Rs\n", maxIndex, minIndex, amount);
		}
	}
}
}

int main()
{
	int numPeople;
	printf("Enter the number of people: ");
	scanf("%d", &numPeople);

    //print people names
    printf("-----------------------------------------------\n");
    printf("People names:\n");
    for(int i=0;i<numPeople;i++)
    {
        printf("Person %d ",i);
        printf("\n");
    }
    printf("-----------------------------------------------\n");

	// create a graph with the given number of people
	Graph g = createGraph(numPeople);

	printf("Enter the number of transactions: ");
	int numTransactions;
	scanf("%d", &numTransactions);
    printf("-----------------------------------------------\n");

    //give an example input
    printf("Example input: 0 1 1000\n");
    printf("This means that Person 0 owes Person 1 1000 Rs\n");
    printf("-----------------------------------------------\n");

	// add transactions to the graph
	for (int i = 0; i < numTransactions; i++)
	{
		int from, to, amount;
		printf("Enter transaction %d (from, to, amount): ", i + 1);
		scanf("%d%d%d", &from, &to, &amount);
        //print error message if the transaction is invalid
        if(from<0 || from>=numPeople || to<0 || to>=numPeople)
        {
            printf("Invalid transaction, exiting program\n");
            exit(0);
        }
		addTransaction(&g, (Transaction){from, to, amount});
	}

	// print the most efficient way to settle all debts
    printf("-----------------------------------------------\n");
	printf("To settle all debts in the most efficient way:\n");
	settleDebts(g);
    printf("-----------------------------------------------\n");

	return 0;
}
