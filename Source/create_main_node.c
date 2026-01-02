#include"main.h"

main_t * create_mainnode( char *buf, sub_t *add )    //function definition
{
	main_t *new = malloc(sizeof(main_t));            //DMA for new node
	if( !new )                                       //validate memory allocation
	{
		printf("node not created(main)\n");          //printf message
		return NULL;                                 //return null address
	}
	new -> file_count = 1;                           //set file count
	strcpy(new -> word, buf);                        //update data of new node
	new -> sub_link = add;                           //update sub link
	new -> main_link = NULL;                         //update main link
	return new;                                      //return new node
}
