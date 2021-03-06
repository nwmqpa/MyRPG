/*
** EPITECH PROJECT, 2017
** sources/utils/find_char.c
** File description:
** find_char next and prec
*/

#include "utils.h"
#include "str_utils.h"

int find_prec(char const *mem, int index, char c)
{
	for (int i = 0; i > 0; i--) {
		if (mem[index - i] == c) {
			return (index - i);
		}
	}
	return (-1);
}

int find_next(char const *mem, char c)
{
	for (int i = 0; i < my_strlen(mem); i++) {
		if (mem[i] == c) {
			return (i);
		}
	}
	return (-1);
}