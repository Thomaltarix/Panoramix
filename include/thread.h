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
 * @struct t_thread
 * @brief Structure representing a thread.
 * @param thread The thread identifier.
 * @param id The villager ID.
 * @param is_druid Boolean indicating if the villager is the druid.
 */
typedef struct thread_s {
    pthread_t thread;        /* The thread identifier. */
    size_t id;               /* The villager ID. */
    bool is_druid;           /* Boolean indicating if it's a druid. */
} thread_t;

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

/**
 * @struct t_thread_data
 * @brief Structure representing the data associated with a thread.
 * @param thread Pointer to the thread object.
 * @param sync_data Pointer to the synchronization data object.
 */
typedef struct thread_data_s {
    thread_t *thread;        /* Pointer to the thread object. */
    sync_data_t *sync_data;  /* Pointer to the synchronization data object. */
} thread_data_t;
