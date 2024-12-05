#include<stdio.h>
#include<stdlib.h>
/* declaracion de la lista en el programa principal
         #include"linkedList.h"
         ll_node* start = NULL;
*/ 

/*funciones
node* ll_getNode()                  -> nodo = ll_getNode();
void ll_createList(node** start, int n)  -> ll_createList(&inicio, 5);
void ll_traversalList(node* start)      -> ll_traversalList(inicio);
int ll_countnodes(ll_node**start )     ->int n = ll_countnodes(&inicio);
void ll_insertAtBeg(node**start)      -> ll_insertAtBeg(&inicio);
void ll_insertAtEnd(node**start)       ->	ll_insertAtEnd(&inicio);
void ll_insertAtMid(ll_node**start)     ->	ll_insertAtMid(&inicio);
*/


//Para modificar el tipo de dato cambiar en el struct, getnode y mid


typedef struct linkedList
{
	char data;
	struct linkedList *next;
}ll_node;

void ll_traversalList(ll_node* start) 
{
    ll_node* temp = start;
    while (temp != NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int ll_countnodes(ll_node**start )
{
	if(*start == NULL)
	{
		return 0;
	}
	else
	{
		return(1+ll_countnodes(&(*start)->next));
	}
}

ll_node* ll_getNode()
{
	ll_node *newnode;
	newnode = (ll_node*) malloc(sizeof(ll_node));
	printf("Enter data: ");
	scanf(" %c", &newnode->data);
	newnode->next = NULL;
	return newnode;
}

void ll_createList(ll_node** start, int n)
{
	int i;
	ll_node* newnode;
	ll_node* temp;
	for(i=0;i<n;i++)
	{
		newnode = ll_getNode();
		if(*start == NULL)
		{
			*start = newnode;
		}
		else
		{
			temp = *start;
			while(temp->next != NULL)
			{
				temp = temp->next;

			}
			temp->next = newnode;
		}
	}
}
void ll_insertAtBeg(ll_node**start)
{
	ll_node *newnode;
	newnode = ll_getNode();
	if(*start == NULL)
	{
		*start = newnode;
	}
	else
	{
		newnode->next = *start;
		*start = newnode;
	}
}
void ll_insertAtEnd(ll_node**start)
{
	ll_node *newnode, *temp;
	newnode = ll_getNode();
	if(*start == NULL)
	{
		*start = newnode;
	}
	else
	{
		temp = *start;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

void ll_insertAtMid(ll_node**start)
{
	ll_node *newnode, *temp, *prev;
	int pos, nodectr, ctr=1;
	newnode = ll_getNode();
	printf("Enter position: ");
	scanf("%d",&pos);
	nodectr = ll_countnodes(&(*start));
	if(pos > 1 && pos < nodectr)
	{
		temp = prev = *start;
		while(ctr<pos)
		{
			prev = temp;
			temp = temp -> next;
			ctr++;
		}
		prev->next = newnode;
		newnode->next = temp;
	}
	else
	{
		printf("Position %d is not a middle position\n",pos);
	}
}

void ll_deleteAtBeg(ll_node**start)
{
	ll_node*temp;
	if(*start == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	else
	{
		temp = *start;
		*start = temp->next;
		free(temp);
	}
}
void ll_deleteAtEnd(ll_node**start)
{
	ll_node *temp, *prev;
	if(*start == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	else
	{
		temp = *start;
		prev = *start;
		while(temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		free(temp);
	}
}





