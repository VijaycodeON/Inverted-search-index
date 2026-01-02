#include"main.h"

status single_ll(slist **head, char *data)
{
	/* create new node */
	slist *new = malloc(sizeof(slist));
	if (!new)
	{
		return failure;
	}

	/* if new node created, update data + link */
	strcpy(new->data,data);
	new->link = NULL;

	/* If list is empty */
	if (*head == NULL)
	{
		/* add new node to first position */
		*head = new;
		return success;
	}

	/* else */
	/* temp points to first node */
	slist *temp = *head;

	/* traverse to next node check next node is present or not */
	while (temp->link != NULL)
	{
		temp = temp->link;
	}

	/* establish the link between last and new node*/
	temp->link = new;

	return success;
}
