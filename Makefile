##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## root makefile
##

DEB 	?=	0

NAME	=	my_rpg

all:	$(NAME)

$(NAME):
	@make --no-print-directory -C sources/ all

re:
	@make --no-print-directory -C sources/ re

debug:
	@make --no-print-directory -C sources/ re DEB=1

clean:
	@make --no-print-directory -C sources/ clean

fclean:
	@make --no-print-directory -C sources/ fclean
	@rm -rf vgcore*
	@rm -rf release

test_run:
	@make --no-print-directory -C bonus/unitest re

test_clear:
	@make --no-print-directory -C bonus/unitest fclean

.PHONY:	re	clean	fclean	test_run test_clear
