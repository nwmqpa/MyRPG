/*
** EPITECH PROJECT, 2017
** ress_manager.c
** File description:
** ressource manager source code
*/

#include "assets_manager.h"
#include "ress_manager.h"
#include "cin_mng.h"
#include "entities.h"
#include "utils.h"

void create_quests(UNUSED struct ressources *ress)
{
	//TODO
}

void create_npcs(UNUSED struct ressources *ress)
{
	//TODO
}

void create_cin(struct ressources *ress)
{
	FILE *file = fopen("ressources/cinematique/intro.txt", "r");
	char *str = NULL;
	long unsigned int bytes = 0;

	getline(&str, &bytes, file);
	for (int i = 0; str[i]; ++i) {
		if (str[i] == '~') {
			str[i] = '\n';
		}
	}
	ress->cinematiques[0] = cin_create(
					30,
					str,
					get_font(get_assets(NULL), THORN),
					(sfColor){255, 255, 255, 255}
					);
}

struct ressources *create_ressources(void)
{
	struct ressources *ress = my_calloc(sizeof(struct ressources));

	create_quests(ress);
	ress->player = create_player((vec_t){100, 1080 - (200 + 200 * 0.5)}, 100, 1);
	create_npcs(ress);
	create_cin(ress);
	return (ress);
}

struct ressources *get_ressources(struct ressources *ress)
{
	static struct ressources *ressources = NULL;

	if (ress != NULL)
		ressources = ress;
	return (ressources);
}