/*
** EPITECH PROJECT, 2017
** include/stats.h
** File description:
** Stats header
*/

#ifndef STATS_H_
#define STATS_H_

#include "entities.h"

enum STATS {
	POWER,
	ENDURANCE,
	LAST_STAT
};

enum SKILLS {
	FIGHTER,
	RUNNER,
	LAST_SKILL
};

struct skill {
	unsigned int type;
	unsigned int level;
};

struct stat {
	unsigned int type;
	unsigned int level;
};

typedef struct skill skill_t;
typedef struct stat stat_t;

void skills_init(struct player *player);
void stats_init(struct player *player);

#endif /* STATS_H_ */