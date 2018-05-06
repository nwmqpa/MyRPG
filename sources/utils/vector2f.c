/*
** EPITECH PROJECT, 2017
** vector2f.c
** File description:
** utils vector functions
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include "utils.h"

sfVector2f random_vector2f(UNUSED float speed, int disp)
{
	sfVector2f vec = {.x = 0, .y = 0};

	while (vec.y == 0 || vec.x == 0) {
		vec.y = ((rand() % disp + 1) - (disp / 2));
		vec.x = ((rand() % disp + 1) - (disp / 2));
	}
	return (vec);
}

void compute_dtime(void)
{
	return;
}