#include	"sort.h"

/**
	*	bubble_sort	-	sort	array	elements	from	min	to	max	value
	*	@array:	array
	*	using	the	Bubble	sort	algorithm.
	*	@size:	array	size
	*	Return:	(void)
	*/
void	bubble_sort(int	*array,	size_t	size)
{
	size_t	i,	index;
	int	tmp;
	int	swapped;

	if	(size	<	2	||	array	==	NULL)
	return;

	for	(i	=	0;	i	<	size	-	1;	i++)
	{
	swapped	=	0;

	for	(index	=	0;	index	<	size	-	1	-	i;	index++)
	{
	if	(array[index]	>	array[index	+	1])
	{
	tmp	=	array[index];
	array[index]	=	array[index	+	1];
	array[index	+	1]	=	tmp;
	swapped	=	1;
	print_array(array,	size);
	}
	}

	if	(!swapped)
	break;
	}
}
