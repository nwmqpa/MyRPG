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
#include "npc.h"

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

int draw_npcs(game_t *game, hashmap_t *npcs)
{
	for (hash_elem_t *temp = npcs; temp; temp = temp->next) {
		draw_npc(game, temp->data);
	}
}

int draw_map(game_t *game)
{
	static float time = 0;
	hash_elem_t *temp = game->actual_map->layers;
	struct layer *temp_layer = NULL;
	sfShader *ls = game->actual_map->light_shader;
	sfRenderStates st = {
		sfBlendAlpha, sfTransform_Identity, NULL, ls};

	play_map_music(game->actual_map);
	if (ls)
		sfShader_setFloatParameter(ls, "u_time", time);
	while(temp) {
		temp_layer = (struct layer *) temp->data;
		sfSprite_setPosition
		(temp_layer->sprite, game->delta_pos);
		sfRenderWindow_drawSprite(
			game->win,
			temp_layer->sprite,
			(hash("light") == temp->hash) && ls ? &st : NULL);
		temp = temp->next;
	}
	draw_npcs(game, game->actual_map->npcs);
	time += get_dtime(-1);
	return (0);
}
