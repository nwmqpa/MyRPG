/*
** EPITECH PROJECT, 2017
** npc.c
** File description:
** npc source file
*/

#include "npc.h"
#include "assets_manager.h"
#include "utils.h"
#include "str_utils.h"

char **load_dialogs(char *path)
{
	FILE *file = fopen(path, "r");
	char *str = NULL;
	char **dialogs = my_calloc(sizeof(char *) * 10);
	int i = 0;

	do {
		str = NULL;
		getline(&str, 0, file);
		dialogs[i++] = str;
	} while (str != NULL);
	return (dialogs);
}

struct npc *npc_create(char *name, char *path, sfVector2f pos)
{
	struct npc *this = my_calloc(sizeof(struct npc));

	this->texture = sfTexture_createFromFile(
		path, NULL);
	this->name = my_strdup(name);
	this->pos  = pos;
	this->anim = NULL;
	this->dialogs = load_dialogs(name);
	return (this);
}