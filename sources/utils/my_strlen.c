/*
** EPITECH PROJECT, 2017
** sources/utils/my_strlen.c
** File description:
** my_strlen function
*/

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}