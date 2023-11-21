#include	"sort.h"
#include	<stdio.h>

/**
	*	swap_nodes	-	Swaps	two	nodes	in	a	doubly	linked	list.
	*	@node:	The	node	to	be	swapped.
	*	@list:	The	pointer	to	the	head	of	the	list.
	*	Return:	The	new	current	node.
	*/
listint_t	*swap_nodes(listint_t	*node,	listint_t	**list)
{
	listint_t	*prev	=	node->prev,	*current	=	node;

	prev->next	=	current->next;
	if	(current->next)
	current->next->prev	=	prev;
	current->next	=	prev;
	current->prev	=	prev->prev;
	prev->prev	=	current;
	if	(current->prev)
	current->prev->next	=	current;
	else
	*list	=	current;

	return	(current);
}

/**
	*	cocktail_sort_list	-	Sorts	a	doubly	linked	list	using	Cocktail	Shaker	Sort.
	*	@list:	The	pointer	to	the	head	of	the	list.
	*/
void	cocktail_sort_list(listint_t	**list)
{
	listint_t	*current;
	int	swap_done	=	1;

	if	(list	==	NULL	||	*list	==	NULL	||	(*list)->next	==	NULL)
	return;

	current	=	*list;
	while	(swap_done	==	1)
	{
	swap_done	=	0;
	while	(current->next	!=	NULL)
	{
	if	(current->n	>	current->next->n)
	{
	current	=	swap_nodes(current->next,	list);
	swap_done	=	1;
	print_list(*list);
	}
	else
	current	=	current->next;
	}

	if	(swap_done	==	0)
	break;

	swap_done	=	0;
	while	(current->prev	!=	NULL)
	{
	if	(current->n	<	current->prev->n)
	{
	current	=	swap_nodes(current,	list);
	swap_done	=	1;
	print_list(*list);
	}
	else
	current	=	current->prev;
	}
	}
}
