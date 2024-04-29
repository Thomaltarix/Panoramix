/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** config
*/

#pragma once

#include <stddef.h>
#include "thread.h"

/**
 * @struct t_config
 * @brief Structure representing the configuration parameters.
 * @param villagers_nb Number of villagers.
 * @param pot_size Size of the pot.
 * @param fight_nb Number of fights.
 * @param refill_nb Number of refills.
 */
typedef struct s_config {
    size_t villagers_nb;                    /* Number of villagers. */
    size_t pot_size;                        /* Size of the pot. */
    size_t fight_nb;                        /* Number of fights. */
    size_t refill_nb;                       /* Number of refills. */
} t_config;

/**
 * @struct t_game
 * @brief Structure representing the game.
 * @param config Pointer to the configuration parameters.
 * @param threads Array of pointers to the threads.
 */
typedef struct s_game {
    t_config *config;                      /* Pointer to the configuration parameters. */
    t_thread **threads;                   /* Array of pointers to the threads. */
} t_game;
