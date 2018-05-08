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
#include "utils.h"

int play_map_music(struct map *map)
{
	if (hash(map->name) == hash("main_city") &&
	sfMusic_getStatus(get_assets(NULL)->musics[CITY]) != sfPlaying) {
		sfMusic_stop(get_assets(NULL)->musics[CAVE]);
		sfMusic_play(get_assets(NULL)->musics[CITY]);
	} else if (hash(map->name) == hash("tutorial") &&
	sfMusic_getStatus(get_assets(NULL)->musics[CAVE]) != sfPlaying) {
		sfMusic_stop(get_assets(NULL)->musics[CITY]);
		sfMusic_play(get_assets(NULL)->musics[CAVE]);
	}
	return (0);
}

int draw_map(game_t *game)
{
	static float time = 0;
	hash_elem_t *temp = game->actual_map->layers;
	struct layer *temp_layer = NULL;
	sfShader *light_shader = get_shader(get_assets(NULL), LIGHT);
	sfRenderStates st = {
		sfBlendAlpha, sfTransform_Identity, NULL, light_shader};

	play_map_music(game->actual_map);
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
