/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** villager
*/

#include "config.h"

static void call_druid(thread_data_t *thread_data)
{
    printf("Villager %ld: Hey Pano wake up! We need more potion.\n",
        thread_data->villager->id);
    sem_post(&thread_data->sync_data->semaphore);
    sleep(1);
}

static void drink(thread_data_t *thread_data)
{
    printf("Villager %ld: I need a drink... I see %ld servings left.\n",
        thread_data->villager->id, thread_data->config->current_pot_size);
    if (thread_data->config->current_pot_size == 0)
        call_druid(thread_data);
    thread_data->config->current_pot_size--;
}

static void fight(thread_data_t *thread_data)
{
    thread_data->villager->fights++;
    printf("Villager %ld: Take that roman scum! Only %ld left.\n",
        thread_data->villager->id,
        thread_data->config->fight_nb - thread_data->villager->fights);
}

void *villager(void *data)
{
    thread_data_t *thread_data = (thread_data_t *)data;

    printf("Villager %ld: Going into battle!\n", thread_data->villager->id);
    while (thread_data->villager->fights < thread_data->config->fight_nb &&
        (thread_data->config->refill_nb > 0 ||
        thread_data->config->current_pot_size > 0)) {
        sleep(1);
        pthread_mutex_lock(&thread_data->sync_data->mutex);
        sleep(1);
        drink(thread_data);
        sleep(1);
        pthread_mutex_unlock(&thread_data->sync_data->mutex);
        sleep(1);
        fight(thread_data);
    }
    printf("Villager %ld: I'm going to sleep now.\n",
        thread_data->villager->id);
    thread_data->config->villagers_nb--;
    return NULL;
}
