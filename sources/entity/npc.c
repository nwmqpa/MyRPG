/*
** EPITECH PROJECT, 2017
** npc.c
** File description:
** npc source file
*/

#include <stdio.h>
#include <stdlib.h>
#include "npc.h"
#include "assets_manager.h"
#include "utils.h"
#include "str_utils.h"
#include "cybend2200.h"

void draw_npc(game_t *game, struct npc *this)
{
	sfVector2f temp = this->pos;

	temp.x += game->delta_pos.x;
	temp.y += game->delta_pos.y;
	sfSprite_setPosition(this->sprite, temp);
	sfRenderWindow_drawSprite(game->win, this->sprite, NULL);
}

char **load_dialogs(FILE *fs)
{
	char *str = NULL;
	char **dialogs = my_calloc(sizeof(char *) * 10);
	size_t i = 0;
	size_t size = 0;
	size_t ret = 0;

	while (getline_w_n(&str, &size, fs) != -1) {
		dialogs[i++] = my_strdup(str);
		free(str);
		size = 0;
	}
	return (dialogs);
}

int npc_get_dialog(struct npc *this)
{
	return this->dialogs[this->phase];
}

int npc_next_dialog(struct npc *this)
{
	this->phase++;
}

struct npc *npc_load_from_file(char *path)
{
	struct npc *this = my_calloc(sizeof(struct npc));
	FILE *fs = fopen(path, "r");
	char *line = NULL;
	size_t size = 0;

	getline_w_n(&line, &size, fs);
	this->name = my_strdup(line);
	free(line);
	size = 0;
	getline_w_n(&line, &size, fs);
	this->sprite = sfSprite_create();
	this->texture = sfTexture_createFromFile(line, NULL);
	sfSprite_scale(this->sprite, (sfVector2f){0.5, 0.5});
	free(line);
	size = 0;
	sfSprite_setTexture(this->sprite, this->texture, sfTrue);
	this->dialogs = load_dialogs(fs);
	return (this);
}
