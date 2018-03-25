/*
** EPITECH PROJECT, 2017
** vector2f.c
** File description:
** utils vector functions
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <stdio.h>

sfVector2f random_vector2f()
{
	sfVector2f vec = {0, 0};

	while (!vec.y || !vec.x) {
		vec.y = (random() % 100 + 1) - 50;
		vec.x = (random() % 100 + 1) - 50;
	}
	return (vec);
}
