/**
 * @file    tick.h
 * @brief   Base de temps milliseconde (incrementee par SysTick).
 */
#ifndef TICK_H
#define TICK_H

#include <stdint.h>

/* A appeler dans SysTick_Handler (toutes les 1 ms) */
void tick_inc(void);

/* Temps ecoule depuis le demarrage, en ms */
uint32_t tick_get_ms(void);

/* Temps ecoule depuis un instant donne, en ms (gere le debordement) */
uint32_t tick_elapsed(uint32_t since_ms);

/* Attente bloquante en ms (a eviter dans la boucle principale) */
void tick_delay_ms(uint32_t ms);

#endif /* TICK_H */
