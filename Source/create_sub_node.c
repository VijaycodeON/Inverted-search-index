#include"main.h"

sub_t * create_subnode( char *data )        //function definition
{
	sub_t *new = malloc(sizeof(sub_t));     //DMA for new sub node
	if( !new )                              //validate memory allocation
	{
		printf("node not created\n");       //print message
		return NULL;                        //return null address
	}
	new -> word_count = 1;                  //set word count
	strcpy(new -> filename,data);           //update data of new node
	new -> sub_link = NULL;                 //update sub link
	return new;                             //return new node
}
