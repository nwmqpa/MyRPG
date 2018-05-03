/*
** EPITECH PROJECT, 2017
** sources/utils/split_string.c
** File description:
** split strings in multiple parts
*/

#include "utils.h"

char **split_string(char const *str, char c)
{
	int ncount = 0;
	int of = 0;
	char **lines;

	if (!str)
		return (0x0);
	for (; find_next(str + of, c) != -1; ncount++)
		of = of + find_next(str + of, c) + 1;
	lines = my_calloc(sizeof(char *) * (ncount + 2));
	ncount = 0;
	for (of = 0; find_next(str + of, c) != -1; ncount++) {
		lines[ncount] = my_calloc(find_next(str + of, c) + 2);
		my_memcpy(lines[ncount], str + of, find_next(str + of, c));
		of = of + find_next(str + of, c) + 1;
	}
	if (*(str + of)) {
		lines[ncount] = my_calloc(my_strlen(str + of) + 2);
		my_memcpy(lines[ncount], str + of, my_strlen(str + of));
	}
	return (lines);
}