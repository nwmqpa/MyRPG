/*
** EPITECH PROJECT, 2017
** include/objecth.h
** File description:
** Objects for game.
*/

#ifndef OBJECTS_H_
#define OBJECTS_H_

typedef struct object item_t;
typedef struct object weapon_t;
typedef struct object ammo_t;
typedef struct object cons_t;
typedef struct inventory inv_t;
typedef union to_data object_union;

#include "cybend2200.h"

#define INSTANCEOF(object) (object & 0xf03fffff)

enum OBJECTS {
	GUN_I,
	AMMO_I,
	FOOD_I
};

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
int inv_sort(struct inventory **inv);
struct vector inv_get_sizes(struct inventory *inv);
struct inventory *inv_create(int nb_slots);
void inv_free(struct inventory **inv);
struct object obj_create(unsigned int level);
struct inventory *create_random_loots(unsigned int level);
int draw_inventory(game_t *game);
void draw_containers(game_t *game);
int transform_shader(sfShader *shader, struct object item);
sfSprite *get_spr_item(item_t object);
void interact_with_cont(game_t *game, sfVector2u m_pos, sfVector2u ws);
void interact_with_inv(game_t *game, sfVector2u m_pos, sfVector2u ws);

#endif /* OBJECTS_H_ */
