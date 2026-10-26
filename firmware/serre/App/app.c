/**
 * @file    app.c
 * @brief   Application serre : initialisation et taches periodiques.
 *
 * Phase 1 : clignotement LED + message de vie sur la liaison serie.
 */
#include "app.h"
#include "main.h"
#include "stm32g0xx_ll_cortex.h"
#include "tick.h"
#include "scheduler.h"
#include "uart_log.h"
#include <stdio.h>

#define LED_PERIOD_MS        500U
#define HEARTBEAT_PERIOD_MS  1000U

/* Clignotement de la LED utilisateur de la Nucleo */
static void task_led(void)
{
    LL_GPIO_TogglePin(LED_USER_GPIO_Port, LED_USER_Pin);
}

/* Message de vie toutes les secondes */
static void task_heartbeat(void)
{
    printf("Serre OK - uptime %lu s\n", (unsigned long)(tick_get_ms() / 1000U));
}

void app_init(void)
{
    /* Active l'interruption SysTick (1 ms) pour la base de temps */
    LL_SYSTICK_EnableIT();

    uart_log_init();
    printf("\n=== Serre intelligente - demarrage ===\n");

    scheduler_add(task_led, LED_PERIOD_MS);
    scheduler_add(task_heartbeat, HEARTBEAT_PERIOD_MS);
}

void app_loop(void)
{
    scheduler_run();
}
