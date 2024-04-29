/*
** EPITECH PROJECT, 2024
** Panoramix
** File description:
** proto
*/

#pragma once

#include "config.h"

// init_simulation.c
int init_simulation(simulation_t *sim, int *values);

// destroy_simulation.c
void destroy_simulation(simulation_t *sim);

// run_simulation.c
int run_simulation(simulation_t *sim);

// druid.c
void *druid(void *data);

// villager.c
void *villager(void *data);
