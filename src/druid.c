/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** druid
*/

#include "config.h"

void *druid(void *data)
{
    thread_data_t *thread_data = (thread_data_t *)data;

    printf("Druid: I'm ready... but sleepy...\n");
    while (thread_data->config->refill_nb > 0 && thread_data->config->villagers_nb > 0) {
        sem_wait(&thread_data->sync_data->semaphore);
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it!"
        "Beware I can only make %ld more refills after this one.\n",
        (thread_data->config->refill_nb) - 1);
        thread_data->config->refill_nb--;
        thread_data->config->current_pot_size = thread_data->config->pot_size;
        pthread_mutex_unlock(&thread_data->sync_data->mutex);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}
