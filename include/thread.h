/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** thread
*/

#pragma once

#include <pthread.h>
#include <semaphore.h>

/**
 * @struct t_thread
 * @brief Structure representing a thread.
 * @param thread The thread identifier.
 * @param id The villager ID.
 * @param is_druid Boolean indicating if the villager is the druid.
 */
typedef struct s_thread {
    pthread_t thread;                       /* The thread identifier. */
    size_t id;                              /* The villager ID. */
    bool is_druid;                          /* Boolean indicating if the villager is the druid. */
} t_thread;

/**
 * @struct t_sync_data
 * @brief Structure representing synchronization data.
 * @param semaphore The semaphore for synchronization.
 * @param mutex The mutex for synchronization.
 */
typedef struct s_sync_data {
    sem_t semaphore;                        /* Semaphore for synchronization. */
    pthread_mutex_t mutex;                  /* Mutex for synchronization. */
} t_sync_data;

/**
 * @struct t_thread_data
 * @brief Structure representing the data associated with a thread.
 * @param thread Pointer to the thread object.
 * @param sync_data Pointer to the synchronization data object.
 */
typedef struct s_thread_data {
    t_thread *thread;                       /* Pointer to the thread object. */
    t_sync_data *sync_data;                 /* Pointer to the synchronization data object. */
} t_thread_data;
