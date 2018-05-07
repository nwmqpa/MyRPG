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
	static float time = 0;
	hash_elem_t *temp = game->actual_map->layers;
	struct layer *temp_layer = NULL;
	sfShader *light_shader = get_shader(get_assets(NULL), LIGHT);
	sfRenderStates st = {
		sfBlendAlpha, sfTransform_Identity, NULL, light_shader};

	sfShader_setFloatParameter(light_shader, "u_time", time);
	while(temp) {
		temp_layer = (struct layer *) temp->data;
		sfRenderWindow_drawSprite(
			game->win,
			temp_layer->sprite,
			(hash("light") == temp->hash) ? &st : NULL);
		temp = temp->next;
	}
	time += 0.016;
	return (0);
}
