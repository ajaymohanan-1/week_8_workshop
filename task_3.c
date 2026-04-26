/*
*******************************************************************************************************
                                        Task_3_description
*******************************************************************************************************
The main() function of the following C program calls a user-defined function split_list() utilizing the 
following input arguments:
1. The address of a pointer (Header_1) to the first node of a linked list containing nodes of type 
   struct node. 
2. The address of a pointer (Header_2) to struct node equal to NULL 
3. An integer (count_nodes)

The function split_list() splits the linked list into two sections after a certain number of nodes 
(node_count), such that Header_1 and Header_2 points to the beginning of the first and second sections, 
respectively, of the linked list.

For instance, if the initial version of the linked list after construction is as follows:
Header_1-> 7->4->6->5->1->2->3->NULL

and count_nodes = 4

The linked list should be split into two sections as follows:
Header_1-> 7->4->6->5->NULL
Header_2-> 1->2->3->NULL

The definition of the function split_list() contains two errors. You must correct these 
errors and verify that the function provides the correct output. In the process of correcting the 
function definition, you are only allowed to edit the existing lines of code in the function and 
therefore, not allowed add any new lines of code for this purpose. 
*******************************************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>

struct node
{
	char data;
	struct node* nextPtr;
};

void split_list(struct node **Header_1, struct node **Header_2, int count_nodes);

int main()
{
	struct node* Header_1 = NULL;
	struct node* Header_2 = NULL;
	struct node* curPtr = NULL;
	struct node* printPtr = NULL;
	int temp = 0;
    int count_nodes = 0;
	printf("Enter the value of the new data member: ");
	scanf("%d", &temp);
	for (count_nodes = 0; temp > 0; count_nodes++)
	{
		if (Header_1 == NULL)
		{
			Header_1 = (struct node*)malloc(sizeof(struct node));
			Header_1->data = temp;
			Header_1->nextPtr = NULL;
			curPtr = Header_1;
		}
		else
		{
			curPtr->nextPtr = (struct node*)malloc(sizeof(struct node));
			curPtr->nextPtr->data = temp;
			curPtr->nextPtr->nextPtr = NULL;
			curPtr = curPtr->nextPtr;
		}
        printf("Enter the value of the new data member: ");
		scanf("%d", &temp);
	}

	printf("Enter the count of nodes after which the list should be split: ");
	scanf("%d", &count_nodes);

    printf("Inital version of linked list:\n");
	printPtr = Header_1;
	while (printPtr != NULL)
	{
		printf("%d->", printPtr->data);
		printPtr = printPtr->nextPtr;
	}
	printf("NULL\n");

	split_list(&Header_1, &Header_2, count_nodes);

    printf("Split linked lists:\n");

    printPtr = Header_1;
	while (printPtr != NULL)
	{
		printf("%d->", printPtr->data);
		printPtr = printPtr->nextPtr;
	}
	printf("NULL\n");
	
	printPtr = Header_2;
	while (printPtr != NULL)
	{
		printf("%d->", printPtr->data);
		printPtr = printPtr->nextPtr;
	}
	printf("NULL\n");
	
	return 0;
}

void split_list(struct node **Header_1, struct node **Header_2, int count_nodes)
{
	struct node* prevPtr = NULL;
	struct node* curPtr = (*Header_1);
	for (int i = 0; i <= count_nodes; i++)
	{
		if (curPtr != NULL)
		{
			prevPtr = curPtr;
			curPtr = curPtr->nextPtr;
		}
	}
	if ((prevPtr == NULL) || (curPtr == NULL)) 
	{
		return;
	}
	else
	{
		curPtr->nextPtr = NULL;
		(*Header_2) = curPtr;
	}
}