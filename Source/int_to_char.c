#include"main.h"

char* int_to_char(int num, char* buff)     //function definition
{
	char ch[10];                           //declare array
	int i=0, temp, j=0;                    //declare variables

	if( num == 0 )                         //if num 0
	{
		buff[0] = 48;                      //update value
		buff[1] = ';';                     //update character
		buff[2] = '\0';                    //store null char
	}
	else                                   //if not 0
	{ 
		while( num )                       //condition for while
		{
			temp = num % 10;               //perform operation and store in temp
			ch[i] = 48 + temp;             //update array
			num = num / 10;                //perform operation
			i++;                           //increment i
		}
		ch[i] = '\0';                      //store null char
		i = i - 1 ;                        // i -1
		while( i >= 0 )                    //condition for while
		{ 
			buff[j] = ch[i];               //update the buff array
			i--;                           //decrement i
			j++;                           //increment j
		}
		buff[j] = ';';                     //store character in array
		buff[j+1] = '\0';                  //store null char
	}
	return buff;                           //return array 
}
