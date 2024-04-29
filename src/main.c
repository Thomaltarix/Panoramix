/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** main
*/

#include "config.h"
#include <stdlib.h>
#include <unistd.h>

static void display_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./panoramix n1 n2 n3 n4\n", 26);
    write(1, "DESCRIPTION\n", 13);
    write(1, "\tn1\tnumber of villagers\n", 25);
    write(1, "\tn2\tsize of the pot\n", 21);
    write(1, "\tn3\tnumber of fights\n", 22);
    write(1, "\tn4\tnumber of refills\n", 23);
}

static int handle_args(int ac, char **av)
{
    int *args = NULL;

    if (ac != NB_ARGS + 1)
        return 84;
    args = malloc(sizeof(int) * NB_ARGS);
    if (args == NULL)
        return 84;
    for (int i = 1; i < ac; i++) {
        args[i] = atoi(av[i]);
        if (args[i] <= 0)
            return 84;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (handle_args(ac, av) == 84) {
        display_help();
        return 84;
    }
    return 0;
}
