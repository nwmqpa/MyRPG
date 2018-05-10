/*
** EPITECH PROJECT, 2017
** sources/inventory/shader.c
** File description:
** Shaders for items.
*/

#include <SFML/Graphics.h>
#include "objects.h"
#include "assets_manager.h"

int transform_shader(sfShader *shader, struct object item)
{
	sfShader_setColorParameter
	(shader, "dmg_repl", get_assets(0x0)->colors[item.dmg_lvl]);
	sfShader_setColorParameter
	(shader, "spd_repl", get_assets(0x0)->colors[item.spd_lvl]);
	sfShader_setColorParameter
	(shader, "split_repl", get_assets(0x0)->colors[item.split_proj]);
}