#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *next;
 }node_t;

int push(node_t *push_head , int push_val)
{
  	if(push_head->next==NULL)
  		{
		node_t *temp = malloc (  sizeof ( node_t )); 
		if  ( temp  ==  NULL )  
		{ 
  			fprintf ( stderr ,  "malloc failed \n " ); 
  			return ( - 1 );
  		}
  		temp->val=push_val;
  		temp->next=NULL;
  		push_head->next=temp;
  	}
  	else
  	{
  		push(push_head->next ,  push_val);
  	}
}

void _print( node_t *print_head)
{
	if(print_head==NULL)
	{
		printf("\n");
		return;
	}
	else
	{
		printf("print_head.val=%d\n",print_head->val);
		_print(print_head->next); 
	}

}


int pop(node_t **pop_head )
{
	if((*pop_head)->next==NULL)
	{
		fprintf ( stderr ,  "pop fail , single element queue \n" ); 
  		return ( - 1 );
	}
	else
	{
		node_t *del_head=*pop_head;
		*pop_head=(*pop_head)->next;
		free(del_head);
	}

}

void clean(node_t **clean_head)
{
	do
	{
		pop(clean_head);
	}
	while((*(clean_head))->next!=NULL);
	free(*clean_head);
	*clean_head=NULL;
}

int main()
{
	node_t *head=malloc(sizeof(node_t));
	head->val=1;
	head->next=NULL;
	pop(&head);
	for(int i=2;i<=10;i++)
	{
		push(head,i);
	}
	pop(&head);
	_print(head);
	clean(&head);
	_print(head);
	return 0;
}







