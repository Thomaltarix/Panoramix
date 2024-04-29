/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** destroy_simulation
*/

#include "config.h"

void destroy_simulation(simulation_t *sim)
{
    free(sim->config);
    for (size_t i = 0; sim->threads[i]; i++) {
        free(sim->threads[i]);
    }
    free(sim->threads);
    sem_destroy(&sim->sync_data->semaphore);
    pthread_mutex_destroy(&sim->sync_data->mutex);
    free(sim->sync_data);
}
