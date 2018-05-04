/*
** EPITECH PROJECT, 2017
** sources/utils/my_revstr.c
** File description:
** my_revstr function.
*/

#include "str_utils.h"

char *my_revstr(char *str)
{
	int i = 0;
	int size = my_strlen(str);

	while (i < size / 2) {
		str[i] = str[size - i];
	}
	return (str);
}
