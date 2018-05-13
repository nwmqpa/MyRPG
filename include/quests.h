/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** main file for all things
*/

#ifndef EVENT_H_
#define EVENT_H_

#include <stdbool.h>
#include "entities.h"

struct quest {
	int id;
	char *desc;
	char *name;
	int xp;
	bool trigger;
	struct quest *next;
};

typedef struct quest quest_t;

struct quest *add_quest(struct quest **head, char *string);
void valid_quest(struct quest *head, struct player *player, int id);
struct quest *get_quest(struct quest *head, int id);
void valid_quest_name(struct quest *head, struct player *player, char *name);

#endif /* EVENT_H_ */
