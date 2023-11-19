#include	"sort.h"
/**
	*	insertion_sort_list	-	sorts	a	doubly	linked	list	of	integers
	*	in	ascending	order	using	insertion	sort.
	*	@list:	Pointer	to	the	head	of	the	doubly	linked	list.
	*	Return:	(void)
*/
void	insertion_sort_list(listint_t	**list)
{
	listint_t	*current;
	listint_t	*temp;

	if	(!list	||	!(*list)	||	!(*list)->next)
	return;

	current	=	(*list)->next;

	while	(current)
	{
	temp	=	current->prev;

	while	(temp	&&	temp->n	>	current->n)
	{
	listint_t	*prev_temp	=	temp->prev;

	if	(temp->next)
	temp->next->prev	=	temp->prev;

	temp->next	=	current->next;
	temp->prev	=	current;

	if	(current->next)
	current->next->prev	=	temp;

	current->next	=	temp;

	if	(prev_temp)
	prev_temp->next	=	current;
	else
	*list	=	current;

	print_list(*list);
	temp	=	prev_temp;
	}
	current	=	current->next;
	}
}
