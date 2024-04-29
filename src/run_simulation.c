/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** run_simulation
*/

#include "config.h"
#include "proto.h"

static int run_druid(villager_t *v)
{
    if (pthread_create(&v->thread, NULL, &druid, v) != 0)
        return 84;
    return 0;
}

static int run_villager(villager_t *v)
{
    if (pthread_create(&v->thread, NULL, &villager, v) != 0)
        return 84;
    return 0;
}

int run_simulation(simulation_t *sim)
{
    int ret = 0;

    for (size_t i = 0; i < sim->config->villagers_nb; i++) {
        if (sim->villagers[i]->is_druid)
            ret = run_druid(sim->villagers[i]);
        else
            ret = run_villager(sim->villagers[i]);
        if (ret == 84)
            return 84;
    }
    for (size_t i = 0; i < sim->config->villagers_nb; i++) {
        if (pthread_join(sim->villagers[i]->thread, NULL) != 0)
            return 84;
    }
    return 0;
}
