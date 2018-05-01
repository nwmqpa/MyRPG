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

sfVector2f rand_angle(int ang)
{
	sfVector2f vec;

	vec.x = cos(RAD(ang)) * 10 / (rand() % 10);
	vec.y = sin(RAD(ang)) * 10 / (rand() % 10);
	return (vec);
}

