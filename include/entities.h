/*
** EPITECH PROJECT, 2017
** include/entities.h
** File description:
** entities header.
*/

#ifndef ENTITIES_H_
#define ENTITIES_H_

#include "structs.h"
#include "objects.h"
#include "stats.h"

struct entity {
	struct vector pos;
	struct elem *loots;
	struct object *weapon;
	int hp;
	int max_hp;
	int ammos;
};

struct player {
	struct entity *entity;
	struct inventory *inv;
	struct stat stats[2];
	struct skill skills[2];
	struct vector xp;
	unsigned int level;
};

#endif /* ENTITIES_H_ */