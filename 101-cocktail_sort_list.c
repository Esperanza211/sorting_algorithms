#include	"sort.h"
#include	<stdio.h>

/**
	*	swap_node	-	Swap	a	node	with	its	previous	one	in	a	doubly	linked	list
	*	@node:	Node	to	be	swapped
	*	@list:	Pointer	to	the	head	of	the	list
	*	Return:	Pointer	to	the	node	that	was	swapped
	*/
listint_t	*swap_node(listint_t	*node,	listint_t	**list)
{
	listint_t	*back	=	node->prev,	*current	=	node;

	if	(!back)
	{
	*list	=	current;
	current->prev	=	NULL;
	current->next	=	back->next;
	if	(back->next)
	back->next->prev	=	current;
	back->next	=	back;
	return	(current);
	}

	back->next	=	current->next;
	if	(current->next)
	current->next->prev	=	back;
	current->next	=	back;
	current->prev	=	back->prev;
	back->prev	=	current;
	if	(current->prev)
	current->prev->next	=	current;
	else
	*list	=	current;

	return	(current);
}

/**
	*	cocktail_sort_list	-	Cocktail	sort	implementation	for	a	doubly	linked	list
	*	@list:	Pointer	to	the	head	of	the	list
	*/
void	cocktail_sort_list(listint_t	**list)
{
	listint_t	*node	=	*list;
	int	swapped;

	if	(!list	||	!(*list)	||	!(*list)->next)
	return;

	do	{
	swapped	=	0;
	while	(node	&&	node->next)
	{
	if	(node->n	>	node->next->n)
	{
	node	=	swap_node(node->next,	list);
	swapped	=	1;
	print_list(*list);
	}
	else
	node	=	node->next;
	}

	if	(!swapped)
	break;

	swapped	=	0;
	while	(node	&&	node->prev)
	{
	if	(node->n	<	node->prev->n)
	{
	node	=	swap_node(node,	list);
	swapped	=	1;
	print_list(*list);
	}
	else
	node	=	node->prev;
	}
	}	while	(swapped);
}

