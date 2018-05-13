/*
** EPITECH PROJECT, 2018
** str_utils.c
** File description:
** str functions
*/

#include "str_utils.h"
#include "utils.h"

int my_strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
		i++;
	}
	if (str1[i] == str2[i])
		return (1);
	else
		return (0);
}

char *my_strcpy(char *dest, char *str)
{
	int i = 0;

	while (str[i]) {
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
