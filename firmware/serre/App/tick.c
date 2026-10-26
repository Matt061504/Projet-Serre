/**
 * @file    tick.c
 * @brief   Base de temps milliseconde.
 */
#include "tick.h"

/* volatile : modifiee dans l'interruption SysTick */
static volatile uint32_t tick_ms = 0;

void tick_inc(void)
{
    tick_ms++;
}

uint32_t tick_get_ms(void)
{
    /* lecture 32 bits atomique sur Cortex-M0+ */
    return tick_ms;
}

uint32_t tick_elapsed(uint32_t since_ms)
{
    /* soustraction non signee : correcte meme apres debordement (~49 jours) */
    return tick_ms - since_ms;
}

void tick_delay_ms(uint32_t ms)
{
    uint32_t start = tick_get_ms();
    while (tick_elapsed(start) < ms)
    {
    }
}
