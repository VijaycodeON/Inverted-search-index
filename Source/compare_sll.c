#include"main.h"

status compare_sll( slist *head, char *data)    //function definition
{
	slist *temp = head;                         //declare temp pointer 
	while( temp )                               //traverse through the list
	{
		if( strcmp(temp -> data, data) == 0)    //if data matched
			return failure;                     //return success macro
		temp = temp -> link;                    //update temp
	}
    return success;                             //return failure macro
}
