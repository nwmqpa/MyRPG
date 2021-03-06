/*
** EPITECH PROJECT, 2017
** sources/entity/mem_management.c
** File description:
** Memory management for entities.
*/

#include <stdlib.h>
#include "cybend2200.h"
#include "entities.h"
#include "structs.h"
#include "objects.h"
#include "anim.h"
#include "utils.h"
#include "stats.h"

struct entity *ent_create(vec_t pos, uint32_t max_hp, uint32_t level)
{
	struct entity *ent = my_calloc(sizeof(struct entity));

	ent->weapon = my_calloc(sizeof(struct object));
	*(ent->weapon) = obj_create(level);
	ent->max_hp = max_hp;
	ent->hp = max_hp;
	ent->loots = create_random_loots(level);
	ent->pos = pos;
	ent->ammos = -1;
	return (ent);
}

void load_animation(struct player *player)
{
	player->normal[N_IDLE] = create_anim_path_rect(
	"assets/anim/n_player_idle.png", 5, 0.1, (sfIntRect){0, 0, 100, 200});
	player->normal[N_LEFT] = create_anim_path_rect(
	"assets/anim/n_player_left.png", 3, 0.03, (sfIntRect){0, 0, 100, 200});
	player->normal[N_RIGHT] = create_anim_path_rect(
	"assets/anim/n_player_right.png", 4, 0.03, (sfIntRect){0, 0, 100, 200});
	player->normal[N_JUMP] = create_anim_path_rect(
	"assets/anim/n_player_jump.png", 4, 0.015, (sfIntRect){0, 0, 100, 200});
	player->normal[N_JUMP]->once = 1;
	player->actual = player->normal[N_IDLE];
	player_scale(player, (sfVector2f){0.5, 0.5});
	player_set_position(player, (sfVector2f){
	100, 1080 - (200 + 200 * 0.5)});
}

void load_assets(struct player *player)
{
	player->texture[0] = sfTexture_createFromFile
	("./assets/textures/player/player_idle.png", NULL);
	player->texture[1] = sfTexture_createFromFile
	("assets/textures/player/player_top_view.png", NULL);
	player->n_idle = sfSprite_create();
	player->f_idle = sfSprite_create();
	sfSprite_setTexture(player->n_idle, player->texture[0], sfTrue);
	sfSprite_setTexture(player->f_idle, player->texture[1], sfTrue);
	load_animation(player);
}

struct player *create_player(vec_t pos, uint32_t max_hp, uint32_t level)
{
	struct player *player = my_calloc(sizeof(struct player));

	player->entity = ent_create(pos, max_hp, level);
	skills_init(player);
	stats_init(player);
	player->inv = inv_create(12);
	player->level = 1;
	player->xp = (struct vector) {0, 0};
	load_assets(player);
	player->vec = (sfVector2f){0, 0};
	player->hitbox = (sfFloatRect)
	{player->entity->pos.x, player->entity->pos.y, 100, 200};
	return (player);
}

void ent_free(struct entity **ent)
{
	free((*ent)->weapon);
	inv_free(&((*ent)->loots));
	free(*ent);
}
