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

char **load_dialogs(FILE *fs)
{
	char *str = NULL;
	char **dialogs = my_calloc(sizeof(char *) * 10);
	size_t i = 0;
	size_t size = 0;
	size_t ret = 0;

	while (getline_w_n(&str, &size, fs) != -1) {
		dialogs[i++] = str;
		size = 0;
	}
	return (dialogs);
}

struct npc *npc_load_from_file(char *path)
{
	struct npc *this = my_calloc(sizeof(struct npc));
	FILE *fs = fopen(path, "r");
	char *line = NULL;
	size_t size = 0;

	getline_w_n(&line, &size, fs);
	this->name = line;
	getline_w_n(&line, &size, fs);
	this->sprite = sfSprite_create();
	this->texture = sfTexture_createFromFile(line, NULL);
	sfSprite_setTexture(this->sprite, this->texture, sfTrue);
	this->dialogs = load_dialogs(fs);
	return (this);
}
