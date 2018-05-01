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

#define INSTANCEOF(object) object & 0xf03fffff

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

union to_data {
	unsigned int data;
	struct object object;
};

int inv_is_full(struct inventory *inv);
unsigned int inv_nb_of(struct inventory *inv, struct object object);
int inv_insert(struct inventory *inv, struct object object);
int inv_remove(struct inventory *inv, struct object object);
struct vector inv_get_sizes(struct inventory *inv);
struct inventory *create_inv(int nb_slots);


#endif /* OBJECTS_H_ */