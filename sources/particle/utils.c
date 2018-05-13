/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** utils.c
*/

#include "particle.h"

sfVector2f rand_vector(int disp)
{
	sfVector2f vec;

	vec.x = rand() % disp + 1 - rand() % disp;
	vec.y = rand() % disp + 1 - rand() % disp;
	return (vec);
}

sfVector2f rand_angle(int disp)
{
	sfVector2f vec;

	vec.x = cos(disp * (M_PI / 180)) * 100;
	vec.y = sin(disp * (M_PI / 180)) * 100;
	return (vec);
}
