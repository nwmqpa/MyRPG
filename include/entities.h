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
#include "anim.h"
#include "structs.h"
#include "objects.h"

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
	F_LEFT,
	F_RIGHT,
	F_DOWN,
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
	sfTexture *texture[2];
	sfSprite *n_idle;
	sfSprite *f_idle;
	anim_t *normal[5];
	anim_t *fight[5];
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

#endif /* ENTITIES_H_ */