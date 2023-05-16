#include "sort.h"

/**
 * insertion_sort_list - sort linked list using insertion method
 * @list: pointer to pointer to list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp;
	listint_t *sectemp;

	temp = *list;
	sectemp = temp->next;
	int k;

	k = 0;
	while (sectemp->next != NULL)
	{
		while (k == 0)
		{
			if (temp->n > sectemp->n)
			{
				if (temp->prev != NULL)
				{
					temp->prev->next = sectemp;
					sectemp->prev = temp->prev;
				}
				else
				{
					*list = sectemp;
					sectemp->prev = NULL;
				}
				if (sectemp->next == NULL)
				{
					temp->next = NULL;
					temp->prev = sectemp;
					sectemp->next = temp;
					return;
				}
				sectemp->next->prev = temp;
				temp->next = sectemp->next;
				temp->prev = sectemp;
				sectemp->next = temp;
				print_list(*list);
				k = 1;
			}
			else
			{
				temp = temp->next;
				sectemp = sectemp->next;
			}
		}
		temp = *list;
		sectemp = temp->next;
		k = 0;
	}
}
