/*
** EPITECH PROJECT, 2017
** ressources_manager.h
** File description:
** ressource manager file
*/

typedef struct ressources ressources_t;

#ifndef RESS_MANAGER_H_
#define RESS_MANAGER_H_

#define NB_NPCS 2
#define NB_CIN	2

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "cin_mng.h"
#include "quests.h"
#include "particle.h"

enum NPC {
	ENEMIE,
	FEMAL
};

/*
** Ressource Manager:
**	Represent one instance of all the ressources
**	of the game currently load.
*/
struct ressources {
	struct quest *quest;
	struct player *player;
	struct npc *npcs[NB_NPCS];
	cin_t *cinematiques[NB_CIN];
	particles *particles;
};

struct ressources *get_ressources(struct ressources *ress);
struct ressources *create_ressources(void);

#endif /* RESSOURCES_MANAGER_H */
