/*
** EPITECH PROJECT, 2017
** sources/utils/my_memcmp.c
** File description:
** my_memcmp funciton
*/

int my_memcmp(char const *str1, char const *str2)
{
	while (*str1 && *str2) {
		if (*str1 != *str2)
			return (0);
		++str1;
		++str2;
	}
	return (*str1 == *str2);
}