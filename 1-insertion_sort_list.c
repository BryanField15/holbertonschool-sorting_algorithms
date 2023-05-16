#include "sort.h"

/**
 * insertion_sort_list - sort linked list using insertion method
 * @list: pointer to pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *sectemp;
	int k;

	temp = *list;
	sectemp = temp->next;

	if (temp == NULL || (temp->prev == NULL && temp->next == NULL))
	{
		return;
	}
	k = 0;
	while (sectemp->next != NULL)
	{
		while (k == 0)
		{
			if (temp->n > sectemp->n)
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
				print_list(*list);
				k = 1;
			}
			else
			{
				temp = temp->next;
				sectemp = sectemp->next;
				if (temp->next == NULL)
				{
					return;
				}
			}
		}
		temp = *list;
		sectemp = temp->next;
		k = 0;
	}
}
