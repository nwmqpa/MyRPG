/*
** EPITECH PROJECT, 2017
** assets_mng.c
** File description:
** assets functions
*/

#include "assets_mng.h"

assets_mng_t *create_assets_mng(char *path)
{
	assets_mng_t *assets = my_calloc(sizeof(assets_mng_t));

	return (assets);
}
