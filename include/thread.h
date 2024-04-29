/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** thread
*/

#pragma once

#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

/**
 * @struct villager_t
 * @brief Structure representing a villager.
 * @param thread The thread identifier.
 * @param id The villager ID.
 * @param fights Number of fights.
 */
typedef struct villager_s {
    pthread_t thread;        /* The thread identifier. */
    size_t id;               /* The villager ID. */
    size_t fights;           /* Number of fights. */
    bool is_druid;           /* True if the villager is the druid. */
} villager_t;

/**
 * @struct t_sync_data
 * @brief Structure representing synchronization data.
 * @param semaphore The semaphore for synchronization.
 * @param mutex The mutex for synchronization.
 */
typedef struct sync_data_s {
    sem_t semaphore;         /* Semaphore for synchronization. */
    pthread_mutex_t mutex;   /* Mutex for synchronization. */
} sync_data_t;
