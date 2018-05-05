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
	sfSprite *sprite;
	sfVector2f pos;
	anim_t *anim;
	char *name;
	char **dialogs;
};

typedef struct npc npc_t;

//Create a npc in ressources manager
struct npc *npc_create(char *name, sfSprite *sprite, sfVector2f pos);

//launch a dialog with the npc
int npc_launch_dialog(game_t *game, struct npc *npc, int id);

//free npc
int npc_destroy(struct npc);

#endif /* NPC_H_ */
