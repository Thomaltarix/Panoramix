/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** init_simulation
*/

#include "config.h"

static void init_config(config_t *config, int *values)
{
    config->villagers_nb = values[0];
    config->pot_size = values[1];
    config->current_pot_size = values[1];
    config->fight_nb = values[2];
    config->refill_nb = values[3];
    free(values);
}

static int init_threads(simulation_t *sim)
{
    for (size_t i = 0; i < sim->config->villagers_nb + 2; i++) {
        sim->villagers[i] = malloc(sizeof(villager_t));
        if (!sim->villagers[i])
            return 84;
        sim->villagers[i]->id = i;
        sim->villagers[i]->is_druid = false;
        sim->villagers[i]->fights = 0;
    }
    sim->villagers[sim->config->villagers_nb]->is_druid = true;
    sim->villagers[sim->config->villagers_nb + 1] = NULL;
    return 0;
}

static int init_sync_data(sync_data_t *sync_data)
{
    if (sem_init(&sync_data->semaphore, 0, 0) == -1)
        return 84;
    if (pthread_mutex_init(&sync_data->mutex, NULL) != 0)
        return 84;
    return 0;
}

int init_simulation(simulation_t *sim, int *values)
{
    sim->config = malloc(sizeof(config_t));
    if (!sim->config)
        return 84;
    init_config(sim->config, values);
    sim->villagers =
        malloc(sizeof(villager_t *) * (sim->config->villagers_nb + 2));
    if (!sim->villagers)
        return 84;
    if (init_threads(sim) == 84)
        return 84;
    sim->sync_data = malloc(sizeof(sync_data_t));
    if (!sim->sync_data)
        return 84;
    if (init_sync_data(sim->sync_data) == 84)
        return 84;
    return 0;
}
