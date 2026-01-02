#include"main.h"

int char_to_int( char* buff)                      //function defintion 
{
	int num = 0, i= 0;                            //declare local variables

	while( buff[i] )                              //traverse through the array
		num = (num * 10) + (buff[i++] - 48);      //calculate integer

	return num;                                   //return int value
}
