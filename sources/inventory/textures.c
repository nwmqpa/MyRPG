/*
** EPITECH PROJECT, 2017
** sources/inventory/shader.c
** File description:
** Shaders for items.
*/

#include <SFML/Graphics.h>
#include "cybend2200.h"
#include "objects.h"
#include "assets_manager.h"

sfSprite *get_spr_item(item_t object)
{
	if (object.type == GUN_I)
		return (get_assets(0x0)->sprites[GUN]);
	if (object.type == AMMO_I)
		return (get_assets(0x0)->sprites[AMMO_I]);
	if (object.type == FOOD_I)
		return (get_assets(0x0)->sprites[FOOD_I]);
	return (0x0);
}

int transform_shader(sfShader *shader, struct object item)
{
	sfShader_setColorParameter
	(shader, "dmg_repl", get_assets(0x0)->colors[item.dmg_lvl]);
	sfShader_setColorParameter
	(shader, "spd_repl", get_assets(0x0)->colors[item.spd_lvl]);
	sfShader_setColorParameter
	(shader, "split_repl", get_assets(0x0)->colors[item.split_proj]);
	return (0);
}