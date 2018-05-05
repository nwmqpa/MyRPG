/*
** EPITECH PROJECT, 2017
** sources/utils/my_itoa.c
** File description:
** My_itoa function.
*/

#include <math.h>
#include "utils.h"
#include "str_utils.h"

char *my_itoa(int nb)
{
	int size = log(nb);
	char *str = my_calloc(sizeof(char) * (size + 1));

	for (int i = 0; i < size; i++, nb /= 10)
		str[i] = (nb % 10) + 48;
	my_revstr(str);
	return (str);
}