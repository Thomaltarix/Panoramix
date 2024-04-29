/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** run_simulation
*/

#include "config.h"
#include "proto.h"

static int run_druid(thread_data_t *data)
{
    if (pthread_create(&data->villager->thread, NULL, &druid, data) != 0)
        return 84;
    return 0;
}

static int run_villager(thread_data_t *data)
{
    if (pthread_create(&data->villager->thread, NULL, &villager, data) != 0)
        return 84;
    return 0;
}

static void init_thread_data(simulation_t *sim, thread_data_t ***data)
{
    for (size_t i = 0; sim->villagers[i] != NULL; i++) {
        (*data)[i] = malloc(sizeof(thread_data_t));
        (*data)[i]->config = sim->config;
        (*data)[i]->sync_data = sim->sync_data;
        (*data)[i]->villager = sim->villagers[i];
    }
    (*data)[sim->config->villagers_nb + 1] = NULL;
}

static int destroy_thread_data(thread_data_t **data)
{
    for (size_t i = 0; data[i] != NULL; i++)
        free(data[i]);
    free(data);
    return 0;
}

int run_simulation(simulation_t *sim)
{
    int ret = 0;
    thread_data_t **data =
        malloc(sizeof(thread_data_t *) * sim->config->villagers_nb + 2);

    if (data == NULL)
        return 84;
    init_thread_data(sim, &data);
    for (size_t i = 0; data[i] != NULL; i++) {
        if (data[i]->villager->is_druid)
            ret = run_druid(data[i]);
        else
            ret = run_villager(data[i]);
        if (ret == 84)
            return 84;
    }
    for (size_t i = 0; data[i] != NULL; i++) {
        if (pthread_join(data[i]->villager->thread, NULL) != 0)
            return 84;
    }
    return destroy_thread_data(data);
}
