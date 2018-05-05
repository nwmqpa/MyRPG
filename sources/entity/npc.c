/*
** EPITECH PROJECT, 2017
** npc.c
** File description:
** npc source file
*/

#include "npc.h"
#include "assets_manager.h"

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
	this->dialogs = load_dialogs(name);
	return (this);
}

void draw_dialog(game_t *game)
{
	sfRenderWindow_drawSprite(game->win,
		get_sprite(get_assets(NULL), DIALOG_BOX), NULL);
	//sfRenderWindow_drawText(win, );
}

int
npc_launch_dialog(game_t *game, struct npc *npc, int id)
{
	game->gamemode = DIALOG;
}
