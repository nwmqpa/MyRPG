/*
** EPITECH PROJECT, 2017
** ress_manager.c
** File description:
** ressource manager source code
*/

#include "ress_manager.h"
#include "utils.h"

void create_quests(struct ressources *ress)
{
	//TODO
}

void create_npcs(struct ressources *ress)
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
					get_font(get_assets(), "Thorne"),
					(sfColor){255, 255, 255, 255}
					);
}

struct ressources *create_ressources(void)
{
	struct ressources *ress = my_calloc(sizeof(struct ressources));

	create_quests(ress);
	ress->player = create_player();
	create_npcs(ress);
	create_cin(ress);
	return (ress);
}
