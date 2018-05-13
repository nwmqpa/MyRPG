/*
** EPITECH PROJECT, 2017
** sources/entity/mem_management.c
** File description:
** Memory management for entities.
*/

#include "entities.h"
#include "particle.h"
#include "assets_manager.h"
#include "map_parser.h"
#include "utils.h"

static void collision(struct player *player, int touched)
{
	if (touched & DOWN_R) {
		if (touched & TOP_R && player->vec.x > 0) {
			player->vec.x = -player->vec.x;
		} if (touched & DOWN_L && player->vec.y > 0) {
			player->vec.y = 0;
		}
	} if (touched & TOP_L) {
		if (touched & DOWN_L && player->vec.x < 0) {
			player->vec.x = -player->vec.x;
		} if (touched & TOP_R && player->vec.y < 0) {
			player->vec.y = -player->vec.y;
		}
	}
}

static void do_player_movement(struct player *player, game_t *game)
{
	for (int i = 0; i < 4; ++i)
		if (player->action[i])
			player_move(game, player, movement[i]);
}

static void player_change_anim(struct player *player)
{
	if (player->vec.y != 0) {
		player->actual = player->normal[N_JUMP];
	} else if (player->vec.x > 0) {
		player->actual = player->normal[N_RIGHT];
		player->normal[N_JUMP]->frame = 0;
		if (sfSound_getStatus(get_assets(NULL)->sounds[FOOTSTEP])
		== sfStopped)
			sfSound_play(get_assets(NULL)->sounds[FOOTSTEP]);
	} else if (player->vec.x < 0) {
		player->actual = player->normal[N_LEFT];
		player->normal[N_JUMP]->frame = 0;
		if (sfSound_getStatus(get_assets(NULL)->sounds[FOOTSTEP])
		== sfStopped)
			sfSound_play(get_assets(NULL)->sounds[FOOTSTEP]);
	} else {
		player->actual = player->normal[N_IDLE];
		player->normal[N_JUMP]->frame = 0;
	}
}

static void player_move_pos(struct player *player)
{
	double dtime = get_dtime(-1);

	if (player->vec.x < 10 && player->vec.x > -10)
		player->vec.x = 0;
	if (player->vec.x > 0)
		player->vec.x -= 50 * dtime;
	if (player->vec.x < 0)
		player->vec.x += 50 * dtime;
}

void draw_player(game_t *game, sfRenderWindow *win, struct player *player)
{
	double dtime = get_dtime(-1);

	do_player_movement(player, game);
	player_move_assets(game, player, player->vec);
	player_change_anim(player);
	if (player->actual) {
		animate(win, player->actual, get_dtime(-1));
	} if (player->entity->pos.y < 1080 - (200 + 200 * 0.5)) {
		player->vec.y += GRAVITY * dtime * 10;
	} else if (player->entity->pos.y > 1080 - (200 * 200 * 0.5)){
		player_set_position(player, (sfVector2f){
		player->entity->pos.x, 1080 - (200 + 200 * 0.5)});
		player->vec.y = 0;
	}
	player_move_pos(player);
}
