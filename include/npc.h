/*
** EPITECH PROJECT, 2017
** npc.h
** File description:
** npc header.
*/

#ifndef NPC_H_
#define NPC_H_

#include <SFML/Graphics.h>
#include <stdio.h>
#include "anim.h"
#include "entities.h"
#include "cybend2200.h"

struct npc {
	sfTexture *texture;
	sfSprite *sprite;
	sfVector2f pos;
	anim_t *anim;
	char *name;
	char **dialogs;
	unsigned int phase;
};

typedef struct npc npc_t;

void draw_npc(game_t *game, struct npc *this);
struct npc *npc_load_from_file(char *path);
int npc_destroy(struct npc);
char *npc_get_dialog(struct npc *this);
int next_phase(game_t *game, struct npc *this);

#endif /* NPC_H_ */

