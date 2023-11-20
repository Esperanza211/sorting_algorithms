#include "sort.h"
#include <stdio.h>

/**
 * swap_node - swap a node with its previous one
 * @node: node to be swapped
 * @list: pointer to the head of the list
 * Return: pointer to the node that was swapped
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;

	return (current);
}

/**
 * cocktail_sort_list - Cocktail sort implementation for a doubly linked list
 * @list: pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;

	node = *list;
	do {
		swapped = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swapped = 1;
				print_list(*list);
			}
			else
				node = node->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swapped = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	} while (swapped);
}

