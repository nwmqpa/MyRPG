/*
** EPITECH PROJECT, 2017
** sources/entity/stats_skills/skills.c
** File description:
** Skills file.
*/

#include "entities.h"
#include "utils.h"

void skills_init(struct player *player)
{
	player->nb_skills = LAST_SKILL;
	player->skills = my_calloc(sizeof(struct skill) * player->nb_skills);
	for (int i = 0; i < LAST_STAT; i++) {
		player->skills[i] = (struct skill) {i, 0};
	}
}