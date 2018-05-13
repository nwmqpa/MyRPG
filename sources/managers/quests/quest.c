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
	size_t j = 0;

	while (str[++i] != ':' && str[i] != 0)
		this->name[j++] = str[i];
	j = 0;
	while (str[++i] != ':' && str[i] != 0)
		this->desc[j++] = str[i];
	return (0);
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
	return (0x0);
}

struct quest *add_quest(struct quest **head, char *string)
{
	struct quest *elem = my_calloc(sizeof(struct quest));

	if (head == NULL) {
		elem->id = 0;
		elem->next = NULL;
	} else {
		elem->id = (*head)->id + 1;
		elem->next = *head;
	}
	cut_string(elem, string);
	if (head != NULL)
		*head = elem;
	return (elem);
}

void valid_quest(struct quest *head, struct player *player, int id)
{
	struct quest *tmp = head;

	while (tmp != NULL) {
		if (tmp->id == id) {
			tmp->trigger = 1;
			player->xp.x += tmp->xp;
		}
		tmp = tmp->next;
	}
}

void valid_quest_name(struct quest *head, struct player *player, char *name)
{
	struct quest *tmp = head;

	while (tmp != NULL) {
		if (my_strcmp(name, tmp->name) == 0) {
			tmp->trigger = 1;
			player->xp.x += tmp->xp;
		}
		tmp = tmp->next;
	}
}