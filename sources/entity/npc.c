/*
** EPITECH PROJECT, 2017
** npc.c
** File description:
** npc source file
*/

#include "npc.h"

char **load_dialogs(path)
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

struct npc *npc_create(char *name, sfSprite *sprite, sfVector2f pos)
{
	struct npc *this = my_calloc(sizeof(struct npc));

	this->name = strdup(name);
	this->pos  = pos;
	this->anim = NULL;
	this->dialogs = load_dialogs();
	return (this);
}

int
npc_launch_dialog(game_t *game, struct npc *npc, int id)
{
	game->gamemode = DIALOG;
}
