/*
** EPITECH PROJECT, 2017
** draw map
** File description:
** Map parsing source.
*/

#include "map_parser.h"
#include "cybend2200.h"
#include "structs.h"

int draw_map(game_t *game)
{
	hash_elem_t *temp = game->actual_map->layers;
	struct layer *temp_layer = NULL;

	for (; temp; temp = temp->next) {
		temp_layer = (struct layer *) temp->data;
		sfRenderWindow_drawSprite(game->win, temp_layer->sprite, NULL);
	}
	return (0);
}