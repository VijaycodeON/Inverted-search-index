#include"main.h"

status remove_duplicates( slist **head )                           //function definition
{
	if( !*head )                                                   //if the list is empty
		return failure;                                            //return failure macro
	if( (*head) -> link == NULL )                                  //if only one node 
		return success;                                            //return success macro
	slist *temp1 = *head, *temp2 = *head, *dup;                    //declare temp pointers
	while( temp1 != NULL && temp1 -> link != NULL )                //traverse one pointer through the list
	{
		temp2 = temp1;                                             //assign temp1 to temp2
		while( temp2 -> link != NULL )                             //traverse temp2 through the list
		{
			if( strcmp(temp1 -> data,temp2 -> link -> data) == 0 )           //if temp1 of data and temp2 link of data equal
			{
				dup = temp2 -> link;                                         //take a dup pointer
				temp2 -> link = temp2 -> link -> link;                       //move temp2 froward
				free(dup);                                                   //free dup pointer node
			}
			else
				temp2 = temp2 -> link;                                       //update temp2
		}
		temp1 = temp1 -> link;                                               //update temp1
	}
	return success;                                                          //return success macro
}

