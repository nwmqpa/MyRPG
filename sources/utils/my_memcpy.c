/*
** EPITECH PROJECT, 2017
** sources/utils/my_memcpy.c
** File description:
** my_memcpy function
*/

void my_memcpy(char *str1, char const *str2, int len)
{
	for (int i = 0; i < len; i++) {
		*str1 = *str2;
		++str1;
		++str2;
	}
}