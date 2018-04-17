/*
** EPITECH PROJECT, 2017
** anim.c
** File description:
** anim source file
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "anim.h"

anim_t *create_anim_path(const char *path, int cnt, float speed, int size)
{
	sfTexture *tex = sfTexture_createFromFile(path, NULL);
	anim_t *anim = create_anim(tex, cnt, speed, size);

	return (anim);
}

anim_t *create_anim(sfTexture *tex, int count , float speed, int size)
{
	anim_t *anim = malloc(sizeof(anim_t));
	sfIntRect rect = {.top = 0};

	anim->tex = tex;
	anim->count = count;
	anim->speed = speed;
	anim->sprite = malloc(sizeof(sfSprite*) * count);
	anim->size = size;
	anim->frame = 0;
	anim->time = 0.f;
	for (int i = 0 ; i < count; i++){
		rect.left = (i * size);
		rect.width = size;
		rect.height = size;
		(anim->sprite)[i] = sfSprite_create();
		sfSprite_setTexture((anim->sprite)[i], \
				anim->tex, sfTrue);
		sfSprite_setTextureRect((anim->sprite)[i], rect);
	}
	return (anim);
}

sfSprite 
*animate(sfRenderWindow *window, anim_t *anim, float delta_time)
{
	anim->time += (1 * delta_time);
	if (anim->time >= anim->speed) {
		anim->time = 0.f;
		if (anim->frame < anim->count - 1) {
			(anim->frame)++;
		} else
			(anim->frame) = 0;
	}
	sfRenderWindow_drawSprite(window, (anim->sprite)[anim->frame], NULL);
	return ((anim->sprite)[anim->frame]);
}
