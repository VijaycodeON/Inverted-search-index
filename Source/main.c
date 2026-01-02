/*
Name : Vijay M
Date : 29/11/2022
Description : INVERTED SEARCH
Sample I/P  :
Sample 0/P  :
*/

#include"main.h"                                         //include user defined header file

int main(int argc, char *argv[])
{
	/*declare local variables*/
	char ch, string[50], buff[10], line[90];            
	char* token;
	hast_t arr[27];
	int i, index, flag = 0, option, k=0;
	slist *head = NULL;
	FILE *fptr;
	//update all hash table array indexes with null
	for(i=0; i<=26; i++)
		arr[i].main_link = NULL;

	while(1)
	{   
		//print messages and take input from the user
		printf("1. Create Database\n2. Display Database\n3. Search\n4. Update Database\n5. Save\n6. Exit\n");
		printf(" Enter the choice : ");
		scanf("%d", &option);
		printf("\n");

		switch(option)
		{
			//case 1 -> CREATE DATABASE
			case 1:                   

				if( argc > 1 )                                                              //CLA must be greater than 1
				{
					for( i=1; i<argc; i++)                                                  //run untill argc times
					{
						fptr = fopen(argv[i], "r");                                         //check passed argument files exist
						if (fptr == NULL)                                                   //if fptr is null
						{
							perror("fopen");
							fprintf(stderr, "ERROR: Unable to open file %s\n", argv[i]);    //print error message

							return failure;                                                 //return failure macro
						}

						fseek( fptr, 0, SEEK_END );                                         //check file empty or not
						if( ftell(fptr) != 0 )                                              //condition if file not empty
						{
							if( single_ll(&head, argv[i]) == failure )                      //function call compare SLL
								printf("single linked list failed\n");                      //print message
						}
					}

					if (remove_duplicates(&head) == failure)                                //function call -> remove dup elements in SLL
						flag = 100;                                                         //set flag value 

					slist *temp = head;                                                     //declare a temp pointer
					while( temp != NULL )                                                   //yraverse through the SLL
					{
						fptr = fopen( temp -> data, "r" );                                  //check file exist or not
						if (fptr == NULL)                                                   //if fptr is null
						{
							perror("fopen");
							fprintf(stderr, "ERROR: Unable to open file %s\n", argv[i]);    //print error message

							return failure;                                                 //return failure macro
						}
						char buffer[50] = {0,0};                                            //declare buffer array
						while( fscanf(fptr,"%s", buffer) != EOF )                           //scan input from file to buffer
						{
							index = toupper(buffer[0]) % 65;                                //calculate index
							if( index > 25 )                                                //if index is greater than 25
								index = 26;                                                 //set index to 26
							sub_t *add;                                                     //declare temp pointer for sub node
							main_t *address;                                                //declare temp pointer for main node
							if( arr[index].main_link == NULL )                              //check main array address is null
							{
								add = create_subnode(temp -> data);                         //create sub node function
								address = create_mainnode(buffer, add);                     //create main node call function

								arr[index].main_link = address;                             //update main node to main array
							}
							else                                                            //if main array index is not null
							{
								main_t *temp_main = arr[index].main_link, *prev_main;       //declare a temp pointer for the main node
								flag = 0;                                                   //set flag value
								while( temp_main )                                          //traverse through the main node list
								{
									prev_main = temp_main;                                  //assign a backup pointer
									if( strcmp(temp_main -> word, buffer) == 0 )            //if word match with the buffer
									{
										sub_t *temp_sub = temp_main -> sub_link, *prev_sub; //decalre a temp pointer for the sub node
										while( temp_sub )                                   //traverse through the sub node
										{
											prev_sub = temp_sub;                            //take a backup pointer for the main
											if( strcmp( temp_sub -> filename, temp -> data ) == 0 )  //if filename match with current file
											{
												temp_sub -> word_count = temp_sub -> word_count + 1; //update word count
												flag = 1;                                            //assign flag value
											}
											temp_sub = temp_sub -> sub_link;                         //upadte temp sub node pointer
										}
										if( flag != 1 )                                              //check flag conditon
										{
											prev_sub -> sub_link = create_subnode(temp -> data);     //create sub node and update to prev
											temp_main -> file_count = temp_main -> file_count +1;    //update file count in the main node
											flag = 2;                                                //assgin value to the flag
										}
									}
									temp_main = temp_main -> main_link;                              //update temp main node pointer
								}                                                     
								if( flag == 0 )                                                      //check flag condition
								{
									add = create_subnode(temp -> data);                              //create a sub node
									address = create_mainnode(buffer, add);                          //create a main node
									prev_main -> main_link = address;                                //update main node to prev
								}
							}
						}
						temp = temp -> link;                                                         //update temp
					}
					if( flag != 100 )                                                                //check flag condition
						printf("----------------\nDATABASE CREATED\n----------------\n\n");          //print message
				}
				else 
					printf("--------------------\nDATABASE NOT CREATED\n--------------------\n*** INFO : Check CLA ***\n\n"); //print message
				if( flag == 100 )
					printf("--------------------\nDATABASE NOT CREATED\n--------------------\n*** INFO : LIST IS EMPTY ***\n\n"); //print message
				break;

			case 2 :
				printf("[index]\t\t[word]\t\t[filecount]\t:\t [filename] -> [wordcount]\n");          //print template message

				for(i=0; i<=26; i++)                                                                  //run the loop for all index
				{
					if(arr[i].main_link != NULL)                                                      //main array index is not null
					{
						main_t *temp_main_d = arr[i].main_link;                                       //declare a temp pointer for the main node
						while( temp_main_d )                                                          //traverse through the main node
						{
							printf("[%d]\t\t", i);                                                    //print index
							sub_t *temp_sub_d = temp_main_d -> sub_link;                              //declare a tem pointer for the sub node
							if( strlen( temp_main_d -> word ) > 5 )                                   //word size > 5
								printf("[%s]\t", temp_main_d -> word );                               //print word
							else
								printf("[%s]\t\t", temp_main_d -> word );                             //print word
							printf("[%d]\t\t", temp_main_d -> file_count );                           //print file count
							printf(":\t");                                                            //print message

							while( temp_sub_d )                                                       //travers ethrough the sub node
							{
								printf(" [%s] -> ", temp_sub_d -> filename );                         //print filename
								printf("[%d] time(s)", temp_sub_d -> word_count );                    //print word count
								temp_sub_d = temp_sub_d -> sub_link;                                  //update temp of sub node
							}

							temp_main_d = temp_main_d -> main_link;                                   //update temp of main node
							printf("\n");                        
						}
					}
				}
				printf("\n");
				break;

			case 3 :
				printf("Enter the word to be searched : ");                                           //print message
				scanf("%s", string);                                                                  //get word from the user
				index = toupper(string[0]) % 65;                                                      //calculate index

				if(arr[index].main_link != NULL)                                                      //index not equal to null
				{
					printf("[index]\t\t[word]\t\t[filecount]\t:\t [filename] -> [wordcount]\n");      //print template message

					main_t *temp_main_d = arr[index].main_link;                                       //declare a temp pointer for the main node

					while( temp_main_d )                                                              //traverse through the main node list
					{
						if( strcmp(temp_main_d -> word, string) == 0 )                                //if main node word match user word
						{
							printf("[%d]\t\t", index);                                                //print index
							sub_t *temp_sub_d = temp_main_d -> sub_link;                              //declare a temp pointer for the sub node
							if( strlen( temp_main_d -> word ) > 5 )                                   //word size > 5
								printf("[%s]\t", temp_main_d -> word );                               //print word
							else
								printf("[%s]\t\t", temp_main_d -> word );                             //print word
							printf("[%d]\t\t", temp_main_d -> file_count );                           //printf file count
							printf(":\t");                                                            //print message

							while( temp_sub_d )                                                       //traverse through the sub node list
							{
								printf(" [%s] -> ", temp_sub_d -> filename );                         //print file name
								printf("[%d] time(s)", temp_sub_d -> word_count );                    //print word count
								temp_sub_d = temp_sub_d -> sub_link;                                  //update temp pointer of sub node
							}
						}
						temp_main_d = temp_main_d -> main_link;                                       //update temp pointer of the main node
					}
					printf("\n\n");
				}
				else
					printf("---------------\nWORD NOT FOUND\n---------------\n\n");                   //print message
				break;

			case 5 :
				printf("Enter the file name : ");                      
				scanf("%s", string);

				//if( i = compare_sll( head, string ) )
				//	printf("file %s already exist\n", string);

				fptr = fopen( string, "w");
				if (fptr == NULL)
				{
					perror("fopen");
					fprintf(stderr, "ERROR: Unable to open file %s\n", string);
					return failure;
				}

				printf("%s file created & good to go\n", string);

				for(i=0; i<=26; i++)
				{
					if(arr[i].main_link != NULL)
					{
						main_t *temp_main_d = arr[i].main_link;

						while( temp_main_d )
						{
							buff[0] = '#';
							fwrite(&buff, 1, 1, fptr);
							int_to_char(i,buff);
							k = strlen(buff);
							fwrite(&buff, 1, k, fptr);
							sub_t *temp_sub_d = temp_main_d -> sub_link;
							k= strlen(temp_main_d -> word);
							fwrite(temp_main_d -> word, 1, k, fptr);
							buff[0] = ';';
							fwrite(&buff, 1, 1, fptr);
							k = temp_main_d -> file_count;
							int_to_char(k,buff);
							k = strlen(buff);
							fwrite(&buff, 1, k, fptr);

							while( temp_sub_d )
							{
								k= strlen(temp_sub_d -> filename);
								fwrite(temp_sub_d -> filename, 1, k, fptr);
								buff[0] = ';';
								fwrite(&buff, 1, 1, fptr);
								k = temp_sub_d -> word_count;
								int_to_char(k,buff);
								k = strlen(buff);
								fwrite(&buff, 1, k, fptr);
								temp_sub_d = temp_sub_d -> sub_link;
							}

							temp_main_d = temp_main_d -> main_link;
							buff[0] = '#';
							buff[1] ='\n';
							fwrite(&buff, 1, 2, fptr);
						}
					}
				}
				printf("\n-------------\n*** SAVED ***\n-------------\n\n");                          //print message
				
				break;

			case 4 :
				printf("Enter the file name : ");
				scanf("%s", string);
				flag = 0;

				fptr = fopen( string, "r+");
				if (fptr == NULL)
				{
					perror("fopen");
					fprintf(stderr, "ERROR: Unable to open file %s\n", string);
					return failure;
				}

				fseek( fptr, 0, SEEK_END );
				if( ftell(fptr) != 0 )
				{
					fseek( fptr, 0, SEEK_SET );

					while( fscanf( fptr, "%s", line ) > 0 )
					{
						index =char_to_int( strtok(line+1, ";"));
						sub_t *add;
						main_t *address;
						if( arr[index].main_link == NULL )
						{
							char *first = strtok(NULL, ";" );
							int	second =char_to_int( strtok(NULL, ";" ));
							char * third = strtok(NULL, ";" );
							int	fourth =char_to_int( strtok(NULL, ";" ));
							add = create_subnode(third);
							address = create_mainnode(first, add);
							arr[index].main_link = address;
							arr[index].main_link -> file_count = second;
							arr[index].main_link -> sub_link -> word_count = fourth;
							sub_t *temp = arr[index].main_link -> sub_link;
							for( i=0; i<second-1; i++)
							{
								char * token = strtok(NULL, ";" );
								int	tok = char_to_int(strtok(NULL, ";" ));
								temp -> sub_link = create_subnode(token);
								temp = temp -> sub_link;
								temp -> word_count = tok;
							}
						}
						else
						{
							main_t *temp =	arr[index].main_link, *prev;

							while( temp )
							{
								prev = temp;
								temp = temp -> main_link;
							}

							char *first = strtok(NULL, ";" );
							int	second = char_to_int(strtok(NULL, ";" ));
							char * third = strtok(NULL, ";" );
							int	fourth = char_to_int(strtok(NULL, ";" ));
							add = create_subnode(third);
							address = create_mainnode(first, add);
							prev -> main_link = address;
							prev -> main_link -> file_count = second;
							prev -> main_link -> sub_link -> word_count = fourth;
							sub_t *semp = prev -> main_link -> sub_link;

							for( i=0; i<second-1; i++)
							{
								char * token = strtok(NULL, ";" );
								int	tok = char_to_int(strtok(NULL, ";" ));
								semp -> sub_link = create_subnode(token);
								semp = semp -> sub_link;
								semp -> word_count = tok;
							}
						}
					}
				}
				else
				{
					printf("\n***  %s <- is EMPTY  ***\n\n", string);
					flag = 100;
				}
				if( flag != 100 )
			    	printf("\n----------------\nUPDATED DATABASE\n----------------\n\n");                          //print message
				break;

			case 6 :
				return success;

			default :
				printf("Enter proper choice!!\n\n");                                                       
		}

		while(1)
		{
			printf("Do you want to continue (y/n) : ");
			scanf(" %c", &ch);
			printf("\n");
			if( ch == 121 )
				break;
			else if ( ch == 110 )
				return success;
			else
				printf("Enter proper choice!!!\n\n");
		}
	}
}
