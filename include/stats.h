/*
** EPITECH PROJECT, 2017
** include/stats.h
** File description:
** Stats header
*/

#ifndef STATS_H_
#define STATS_H_

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

#endif /* STATS_H_ */