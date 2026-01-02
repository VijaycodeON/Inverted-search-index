#ifndef TYPES_H
#define TYPES_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


typedef enum
{
	success,
	failure
}status;


typedef struct linked_list
{
	char data[50];
	struct linked_list *link;
}slist;

typedef struct sub_node
{
	int word_count;
	char filename[50];
	struct sub_node *sub_link;
}sub_t;

typedef struct main_node
{
	int file_count;
	char word[50];
	struct sub_node *sub_link;
	struct main_node *main_link;
}main_t;


typedef struct array
{
	main_t *main_link;
}hast_t;

status single_ll( slist **head, char *data );

status remove_duplicates( slist **head );

void print_list( slist *head );

sub_t * create_subnode( char *data);

main_t * create_mainnode( char *buf, sub_t *add );

status compare_sll( slist *head, char *data);

char * int_to_char(int, char*);

int char_to_int(char*);

#endif
