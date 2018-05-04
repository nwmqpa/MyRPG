/*
** EPITECH PROJECT, 2017
** sources/entity/stats_skills/stats.c
** File description:
** Stats file.
*/

#include "entities.h"
#include "utils.h"

void stats_init(struct player *player)
{
	player->nb_stats = LAST_STAT;
	player->stats = my_calloc(sizeof(struct stat) * player->nb_stats);
	for (int i = 0; i < LAST_STAT; i++) {
		player->stats[i] = (struct stat) {i, 0};
	}
}