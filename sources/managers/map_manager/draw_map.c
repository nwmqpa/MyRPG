/*
** EPITECH PROJECT, 2017
** draw map
** File description:
** Map parsing source.
*/

#include "map_parser.h"
#include "cybend2200.h"
#include "structs.h"
#include "assets_manager.h"

int draw_map(game_t *game)
{
	hash_elem_t *temp = game->actual_map->layers;
	struct layer *temp_layer = NULL;
	sfRenderStates st = 
	{sfBlendAlpha, sfTransform_Identity, NULL, get_shader(get_assets(NULL), LIGHT)};

	while(temp) {
		temp_layer = (struct layer *) temp->data;
		if (temp->next) {
			sfRenderWindow_drawSprite
			(game->win, temp_layer->sprite, NULL);
		} else {
			sfRenderWindow_drawSprite
			(game->win, temp_layer->sprite, &st);
		}
		temp = temp->next;
	}
	return (0);
}