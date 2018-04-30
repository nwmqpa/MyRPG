/*
** EPITECH PROJECT, 2017
** include/objecth.h
** File description:
** Objects for game.
*/

#ifndef OBJECTS_H_
#define OBJECTS_H_

typedef struct object weapon_t;
typedef struct object ammo_t;
typedef struct object cons_t;
typedef struct inventory inv_t;

struct object {
	unsigned int type: 4;
	unsigned int qty: 6;
	unsigned int dmg_lvl: 4;
	unsigned int spd_lvl: 4;
	unsigned int split_proj: 4;
	unsigned int left_data: 10;
};

struct inventory {
	struct object *objects;
	unsigned int size;
};

#endif /* OBJECTS_H_ */