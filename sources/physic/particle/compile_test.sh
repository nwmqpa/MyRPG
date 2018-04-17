#!/usr/bin/env bash

[[ -n $1 ]] && name=$1 || name="a.out"
printf "compiling $name\n"
gcc graphical_test.c particle_create.c particle_draw.c \
	../../utils/vector2f.c  -I ../../../include/ -l c_graph_prog -o $name
printf "Done !\n"

