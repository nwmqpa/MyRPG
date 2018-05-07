/*
** EPITECH PROJECT, 2017
** include/entities.h
** File description:
** entities header.
*/

#include "stats.h"

#ifndef ENTITIES_H_
#define ENTITIES_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "anim.h"
#include "structs.h"
#include "cybend2200.h"
#include "objects.h"

#define NB_ANIM_N 4
#define NB_ANIM_F 2

#define LEFT	0b00000001
#define TOP	0b00000010
#define RIGHT	0b00000100
#define DOWN	0b00001000

#define SPEED	500

static const int movement[4] = {TOP, LEFT, RIGHT, DOWN};

// Normal game animations
enum ANIM_NORMAL {
	N_IDLE,
	N_LEFT,
	N_RIGHT,
	N_JUMP
};

// Fight top view animation
enum ANIM_FIGHT {
	F_IDLE,
	F_SHOOT
};

struct entity {
	struct vector pos;
	struct inventory *loots;
	struct object *weapon;
	int hp;
	int max_hp;
	int ammos;
};

struct player {
	struct entity *entity;
	struct inventory *inv;
	struct stat *stats;
	struct skill *skills;
	struct vector xp;
	unsigned int level;
	unsigned int nb_stats;
	unsigned int nb_skills;
	bool action[4];
	sfVector2f vec;
	anim_t *actual;
	sfTexture *texture[2];
	sfSprite *n_idle;
	sfSprite *f_idle;
	anim_t *normal[5];
	anim_t *fight[2];
};

// Entity
struct entity *ent_create(vec_t pos, uint32_t max_hp, uint32_t level);
void ent_free(struct entity **ent);

// Player
struct player *create_player(vec_t pos, uint32_t max_hp, uint32_t level);

// Player attributes
uint32_t compute_player_power(struct player *player);
uint32_t compute_entity_power(struct entity *entity);
int compute_xp(uint32_t player_power, uint32_t entity_power);
int player_move(game_t *game, struct player *player, int dir);
void draw_player(game_t *game, sfRenderWindow *win, struct player *player);
int move_fight(struct player *player, int dir);
int move_game(struct player *player, int dir);
void player_move_assets(struct player *player, sfVector2f pos);
int player_set_position(struct player *player, sfVector2f pos);
int player_scale(struct player *player, sfVector2f scale);
int player_jump(struct player *player);

#endif /* ENTITIES_H_ */