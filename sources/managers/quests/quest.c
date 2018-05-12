/*
** EPITECH PROJECT, 2017
** sources/managers/assets_color.c
** File description:
** Assets color
*/

#include "quests.h"
#include "utils.h"
#include "str_utils.h"

int alloc_str(struct quest *this, char *str)
{
	int i = -1;
	size_t size = 0;
	size_t j = 0;

	while (str[++i] != ':' && str[i] != 0)
		this->name[j++] = str[i];
	j = 0;
	while (str[++i] != ':' && str[i] != 0)
		this->desc[j++] = str[i];
}

char *cut_string(struct quest *this, char *str)
{
	int i = -1;
	size_t size = 0;

	while (str[++i] != ':' && str[i] != 0)
		size++;
	this->name = my_calloc(size + 1);
	size = 0;
	while (str[++i] != ':' && str[i] != 0)
		size++;
	this->desc = my_calloc(size + 1);
	this->xp = my_atoi(str + i + 1);
	alloc_str(this, str);
}

struct quest *add_quest(struct quest **head, char *string)
{
	static int salam = 0;
	struct quest *elem = my_calloc(sizeof(struct quest));

	if (head == NULL) {
		elem->next = NULL;
	} else {
		elem->next = *head;
	}
	cut_string(elem, string);
	if (head != NULL)
		*head = elem;
	return (elem);
}

void valid_quest(struct quest *head, int id)
{

}

