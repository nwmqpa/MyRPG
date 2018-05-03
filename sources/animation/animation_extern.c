/*
** EPITECH PROJECT, 2017
** anim_extern.c
** File description:
** Extern function from anim feature.
*/

#include <stdlib.h> 
#include <SFML/Graphics.h>
#include "anim.h"

void anim_set_position(anim_t *anim, sfVector2f offset)
{
         int i = 0;
 	
	 while (i < anim->count)
                 sfSprite_setPosition((anim->sprite)[i++], offset);
}

void anim_move(anim_t *anim, sfVector2f offset)
{
        int i = 0;
        
	while (i < anim->count)
                sfSprite_move((anim->sprite)[i++], offset);
}

void anim_scale(anim_t *anim, sfVector2f factor)
{
        int i = 0;
        
	while (i < anim->count)
                sfSprite_scale((anim->sprite)[i++], factor);
}


