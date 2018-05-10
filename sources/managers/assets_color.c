/*
** EPITECH PROJECT, 2017
** sources/managers/assets_color.c
** File description:
** Assets color
*/

#include <SFML/Graphics.h>
#include "assets_manager.h"

void set_colors(struct assets *assets)
{
	assets->colors[0] = (sfColor) {0, 0, 0, 255};
	assets->colors[1] = (sfColor) {128, 0, 0, 255};
	assets->colors[2] = (sfColor) {0, 128, 0, 255};
	assets->colors[3] = (sfColor) {128, 128, 0, 255};
	assets->colors[4] = (sfColor) {0, 0, 128, 255};
	assets->colors[5] = (sfColor) {128, 0, 128, 255};
	assets->colors[6] = (sfColor) {0, 128, 128, 255};
	assets->colors[7] = (sfColor) {192, 192, 192, 255};
	assets->colors[8] = (sfColor) {128, 128, 128, 255};
	assets->colors[9] = (sfColor) {255, 0, 0, 255};
	assets->colors[10] = (sfColor) {0, 255, 0, 255};
	assets->colors[11] = (sfColor) {255, 255, 0, 255};
	assets->colors[12] = (sfColor) {0, 0, 255, 255};
	assets->colors[13] = (sfColor) {255, 0, 255, 255};
	assets->colors[14] = (sfColor) {0, 255, 255, 255};
	assets->colors[15] = (sfColor) {255, 255, 255, 255};
}