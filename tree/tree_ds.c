#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* left, * right;
};

void createtree(int);
int search(int);

struct node* head = NULL;
struct node* temp = NULL;
struct node* prev = NULL;

int main()
{
	int choice = 0, num, flag = 0, key;

	do
	{
		printf("enter your choice: \n 1. insert\n2. search\n3. exit\n");
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
				printf("\nnode FOUND in the tree/n");
			}
			else
			{
				printf("\nnode NOT found\n");
			}

		case 3:
			free(head);
			break;
		}
	} while (choice != 3);

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
	while (head != NULL)
	{
		if (key > head->data)
		{
			head = head->right;
		}
		else if (key < head->data)
		{
			head = head->left;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}