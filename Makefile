##
## EPITECH PROJECT, 2024
## Panoramix
## File description:
## Makefile
##

# Sources
SRC		=	src/main.c					\
			src/init_simulation.c		\
			src/destroy_simulation.c	\

OBJ		=	$(SRC:.c=.o)

# Tests
SRC_TESTS	=	tests/test.c
OBJ_TESTS	=	$(SRC_TESTS:.c=.o)

# Name
NAME	=	panoramix

# Compiler
CC	=	gcc


# Flags
CFLAGS	=	-W -Wall -Wextra -I./include
EXTRAFLAGS	=	-lpthread -g3
TESTFLAGS	=	-lcriterion --coverage

.PHONY:	all clean fclean re tests_run

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(EXTRAFLAGS)

clean:
	@rm -f $(OBJ)

fclean:	clean clean_tests
	@rm -f $(NAME)

re:	fclean all

tests_run:
	@$(CC) -o unit_tests $(SRC) $(SRC_TESTS) $(CFLAGS) $(TESTFLAGS)
	@./unit_tests
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branches

clean_tests:
	@rm -f unit_tests
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f *.gcov
