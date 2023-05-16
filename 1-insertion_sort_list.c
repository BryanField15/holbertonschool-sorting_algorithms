#include "sort.h"

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
				temp->next = sectemp->next;
				sectemp->next->prev = temp->next;
				sectemp->next = temp;
				temp->prev = sectemp;
				temp->prev->next = sectemp;
				sectemp->prev = temp->prev;
				print_list(*list);
				k = 1;
			}
			else
			{
				temp = temp->next;
				sectemp = sectemp->next;
			}
		}
	}
}
