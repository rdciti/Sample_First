#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left, * right;
};

struct stackNode
{
	struct stackNode* top;
	struct stackNode* next;
};

void createtree(int);
int search(int);

void traverse();
void push(struct node*);
struct stackNode *pop();

struct node* head = NULL;
struct node* temp = NULL;
struct node* prev = NULL;

struct stackNode* q   = NULL;
struct stackNode* top = NULL;
struct stackNode* np  = NULL;

int main()
{
	int choice = 0, num, flag = 0, key;

	do
	{
		printf("enter your choice: \n 1. insert\n2. search\n3. traverse\n4. exit\n");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("enter the element to insert: ");
			scanf_s("%d", &num);
			createtree(num);
			break;

		case 2:
			printf("enter the node to search:");
			scanf_s("%d", &key);
			flag = search(key);

			if (flag)
			{
				printf("\nFOUND in the tree\n");
			}
			else
			{
				printf("\nNOT found\n");
			}

		case 3:
			printf("\n\nINORDER traversal: ");
			traverse(head);

		case 4:
			printf("\n\nFreeing the memory\n\n");
			head = NULL;
			free(head);
			break;
		}
	} while (choice != 4);

	return 0;
}

void createtree(int num)
{
	temp = head;
	prev = head;

	if (head == NULL)
	{
		head = (struct node*)malloc(sizeof(struct node));
		head->data = num;
		head->left = head->right = NULL;
	}
	else
	{
		while (temp != NULL)
		{
			if (num > temp->data)
			{
				prev = temp;
				temp = temp->right;
			}
			else
			{
				prev = temp;
				temp = temp->left;
			}
		}
		 
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = num;
		temp->right = NULL;
		temp->left = NULL;

		if (num >= prev->data)
		{
			prev->right = temp;
		}
		else
		{
			prev->left = temp;
		}
	}
}

int search(int key)
{
	temp = head;
	while (temp != NULL)
	{
		if (key > temp->data)
		{
			temp = temp->right;
		}
		else if (key < temp->data)
		{
			temp = temp->left;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

void traverse()
{
	push(head);

	temp = head;

	while (top != NULL)
	{
		while (temp != NULL)
		{
			push(temp);
			temp = temp->left;
		}
		if (top != NULL && temp == NULL)
		{
			temp = pop();
			printf(" %d,", temp->data);
			temp = temp->right;
		}
	}
}

void push(struct node *ptr)
{
	np = (struct stackNode*)malloc(sizeof(struct stackNode));
	np->top = ptr;
	np->next = NULL;
	if (top == NULL)
	{
		top = np;
	}
	else
	{
		q = top;
		top = np;
		np->next = q;
	}
}

struct stackNode *pop()
{
	if (top == NULL)
	{
		printf("underflow\n");
	}
	else
	{
		q = top;
		top = top->next;
		return(q->top);
		q = NULL;
		free(q);
	}
}