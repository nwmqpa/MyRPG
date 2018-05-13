/*
** EPITECH PROJECT, 2017
** sources/entity/interaction.c
** File description:
** Make interaction between world and entity.
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "ress_manager.h"
#include "cybend2200.h"
#include "entities.h"
#include "structs.h"
#include "assets_manager.h"
#include "ress_manager.h"
#include "map_parser.h"
#include "str_utils.h"
#include "utils.h"
#include "npc.h"
#include "ui.h"

static int do_jill_interaction(game_t *game, struct npc *npc)
{
	struct quest **q = &get_ressources(0x0)->quest;
	struct player *p = get_ressources(0x0)->player;
	union to_data i = {.data = 2 << 30};

	if ((*q)->id == 2) {
		dialog_launch(game, game->dialog, npc_get_dialog(npc));
		valid_quest(game, q, p);
		npc->phase++;
	} else if ((*q)->id == 1 && inv_nb_of(p->inv, i.object) != 0) {
		valid_quest(game, q, p);
		npc->phase++;
	}
	return 0;
}

int do_npc_interact(game_t *game, struct npc *npc)
{
	if (my_strcmp(npc->name, "Jill")) {
		do_jill_interaction(game, npc);
	} else {
		popup_launch(game, "You need to find an authorized ID card");
		dialog_launch(game, game->dialog, npc_get_dialog(npc));
	}
	return 0;
}