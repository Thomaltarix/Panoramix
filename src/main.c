/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** main
*/

#include "config.h"
#include "proto.h"

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

static int *handle_args(int ac, char **av)
{
    int *args = NULL;

    if (ac != NB_ARGS + 1)
        return NULL;
    args = malloc(sizeof(int) * NB_ARGS);
    if (args == NULL)
        return NULL;
    for (int i = 0; i < ac - 1; i++) {
        args[i] = atoi(av[i + 1]);
        if (args[i] <= 0) {
            free(args);
            return NULL;
        }
    }
    return args;
}

int main(int ac, char **av)
{
    simulation_t sim;
    int *values = handle_args(ac, av);

    if (values == NULL) {
        display_help();
        return 84;
    }
    if (init_simulation(&sim, values) == 84) {
        display_help();
        return 84;
    }
    destroy_simulation(&sim);
    return 0;
}
