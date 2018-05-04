/*
** EPITECH PROJECT, 2017
** include/entities.h
** File description:
** entities header.
*/

#include "stats.h"

#ifndef ENTITIES_H_
#define ENTITIES_H_

#include "structs.h"
#include "objects.h"

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
};

uint32_t compute_player_power(struct player *player);
uint32_t compute_entity_power(struct entity *entity);
int compute_xp(uint32_t player_power, uint32_t entity_power);
struct entity *ent_create(vec_t pos, uint32_t max_hp, uint32_t level);
void ent_free(struct entity **ent);
struct player *create_player(vec_t pos, uint32_t max_hp, uint32_t level);

#endif /* ENTITIES_H_ */