/*
** EPITECH PROJECT, 2017
** sources/managers/assets_color.c
** File description:
** Assets color
*/

#include "quests.h"
#include "utils.h"

int alloc_str(struct quest *this, char *str)
{
	int i = -1;
	size_t size = 0;
	size_t j = 0;

	while (str[++i] != ':' && str[i] != 0)
		this->name[j++] = str[size++]
	j = 0;
	i++;
	while (str[++i] != ':' && str[i] != 0)
		this->name[j++] = str[size++];
}

char *cut_string(struct quest *this, char *path)
{
	char *str = get_string_from_file(path);
	int i = -1;
	size_t size = 0;
	
	while (str[++i] != ':' && str[i] != 0)
		size++;
	this->name = my_calloc(size);
	size = 0;
	while (str[++i] != ':' && str[i] != 0)
		size++;
	this->desc = my_calloc(size);
	this->xp = atoi(str + i + 1);
	alloc_str(this, str);
}

struct quest *add_quest(struct quest **head, char *string)
{
	static int salam = 0;
	struct quest *elem = my_calloc(sizeof(struct quest));

	elem->next = *head;
	cut_string("ressources/quests/quests");
	head = elem;
}

struct valid_quest(struct quest *head, int id)
{

}

