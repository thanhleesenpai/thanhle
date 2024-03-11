#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
typedef struct node
{
	int val;
	struct node *next;
} node;

node *make_node(int v)
{
	node *newnode = (node *)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->val = v;
	return newnode;
}
void push_back(node **head, int v)
{
	node *newnode = make_node(v);
	if (*head == NULL)
		*head = newnode;
	else
	{
		node *tmp = *head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newnode;
	}
}
void create_list(node **head1)
{
	printf("DSLK:\n");
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		push_back(head1, x);
	}
}