/*
** EPITECH PROJECT, 2017
** sources/utils/getline_without_n.c
** File description:
** getline without the \n after
*/

#include <stdio.h>
#include <stdlib.h>
#include "str_utils.h"
#include "utils.h"

char *string_from_file(char *path)
{
	char *ret = NULL;
	size_t size = 0;
	int i = -1;
	FILE *fs = fopen(path, "r");

	if (fs == NULL)
		return (my_strdup("Error"));
	getline(&ret, &size, fs);
	while (ret[++i]) {
		if (ret[i] == '~')
			ret[i] = '\n';
		if (ret[i] == '^')
			ret[i] = '\t';
	}
	fclose(fs);
	return (ret);
}

int getline_w_n(char **line, long unsigned int *size, FILE *file)
{
	char *ret_line = 0x0;
	int ret = 0;

	ret = getline(line, size, file);
	if (ret == -1)
		return (-1);
	if ((*line)[my_strlen(*line) - 1] == '\n') {
		ret_line = my_calloc(my_strlen(*line));
		my_memcpy(ret_line, *line, my_strlen(*line) - 1);
		free(*line);
		*line = ret_line;
		ret -= 1;
	}
	return (ret);
}
