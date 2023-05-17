#include "sort.h"
/**
 * list_length - determines the length of a list
 * @list: list to be evaluated
 * Return: length
 */

size_t list_length(listint_t **list)
{
	size_t length = 0;
	listint_t *temp;

	if (list == NULL || (*list) == NULL)
	{
		return (0);
	}
	temp = *list;
	while (temp != NULL)
	{
		temp = temp->next;
		length = length + 1;
	}
	return (length);
}

/**
 * swap_node - swaps any two nodes
 * @list: list containing nodes to be swapped
 * @temp: one node to be swapped
 * @sectemp: other node to be swapped
 * Return: void
 */

void swap_node(listint_t **list, listint_t *temp, listint_t *sectemp)
{
	if (temp->prev == NULL)
	{
		*list = sectemp;
		sectemp->prev = NULL;
	}
	else
	{
		temp->prev->next = sectemp;
		sectemp->prev = temp->prev;
	}
	if (sectemp->next == NULL)
	{
		temp->next = NULL;
	}
	else
	{
		sectemp->next->prev = temp;
		temp->next = sectemp->next;
	}
	temp->prev = sectemp;
	sectemp->next = temp;
}

/**
 * insertion_sort_list - sort linked list using insertion method
 * @list: pointer to pointer to list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *sectemp;

	if (list_length(list) < 2)
	{
		return;
	}

	temp = *list;
	while (temp->next != NULL)
	{
		sectemp = temp->next;
		if (temp->n > sectemp->n)
		{
			swap_node(list, temp, sectemp);
			print_list(*list);
			temp = *list;
		}
		else
		{
			temp = temp->next;
		}
	}
}
