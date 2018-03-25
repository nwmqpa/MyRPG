/*
** EPITECH PROJECT, 2017
** animation_extern.c
** File description:
** Extern function from animation feature.
*/

#include <stdlib.h> 
#include <SFML/Graphics.h>
#include "animation.h"

void animation_set_position(animation_t *animation, sfVector2f offset)
{
         int i = 0;
 	
	 while (i < animation->count)
                 sfSprite_setPosition((animation->sprite)[i++], offset);
}

void animation_move(animation_t *animation, sfVector2f offset)
{
        int i = 0;
        
	while (i < animation->count)
                sfSprite_move((animation->sprite)[i++], offset);
}

void animation_scale(animation_t *animation, sfVector2f factor)
{
        int i = 0;
        
	while (i < animation->count)
                sfSprite_scale((animation->sprite)[i++], factor);
}


