/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** config
*/

#pragma once

#include "thread.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

#define NB_ARGS 4              /* Number of arguments. */

/**
 * @struct t_config
 * @brief Structure representing the configuration parameters.
 * @param villagers_nb Number of villagers.
 * @param pot_size Size of the pot.
 * @param fight_nb Number of fights.
 * @param refill_nb Number of refills.
 */
typedef struct config_s {
    size_t villagers_nb;         /* Number of villagers. */
    size_t pot_size;             /* Size of the pot. */
    size_t fight_nb;             /* Number of fights. */
    size_t refill_nb;            /* Number of refills. */
} config_t;

/**
 * @struct t_simulation
 * @brief Structure representing the simulation.
 * @param config Pointer to the configuration parameters.
 * @param threads Array of pointers to the threads.
 */
typedef struct simulation_s {
    config_t *config;            /* Pointer to the configuration parameters. */
    villager_t **villagers;        /* Array of pointers to the villagers. */
    sync_data_t *sync_data;      /* Synchronization data. */
} simulation_t;

/**
 * @struct t_thread_data
 * @brief Structure representing the data associated with a thread.
 * @param villager Pointer to the villager object.
 * @param sync_data Pointer to the synchronization data object.
 */
typedef struct thread_data_s {
    villager_t *villager;        /* Pointer to the thread object. */
    sync_data_t *sync_data;  /* Pointer to the synchronization data object. */
    config_t *config;        /* Pointer to the configuration object. */
} thread_data_t;
