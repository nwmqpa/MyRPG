/*
** EPITECH PROJECT, 2017
** sources/utils/str_append.c
** File description:
**
*/

#include <stdlib.h>
#include "utils.h"

char *str_append(char *str, char c)
{
	int counter = 0;
	char *to_return;

	while (str && str[counter])
		counter++;
	to_return = my_calloc(sizeof(char) * (counter + 2));
	counter = 0;
	while (str && str[counter]) {
		to_return[counter] = str[counter];
		counter++;
	}
	to_return[counter] = c;
	to_return[counter + 1] = 0;
	if (str)
		free(str);
	return (to_return[0] == 0 ? NULL : to_return);
}
