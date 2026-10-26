/**
 * @file    scheduler.c
 * @brief   Ordonnanceur cooperatif simple.
 *
 * Chaque tache doit etre courte et non bloquante.
 */
#include "scheduler.h"
#include "tick.h"
#include <stddef.h>

typedef struct
{
    scheduler_task_t task;
    uint32_t period_ms;
    uint32_t last_run_ms;
} scheduler_entry_t;

static scheduler_entry_t tasks[SCHEDULER_MAX_TASKS];
static uint8_t task_count = 0;

int scheduler_add(scheduler_task_t task, uint32_t period_ms)
{
    if ((task == NULL) || (period_ms == 0U) || (task_count >= SCHEDULER_MAX_TASKS))
    {
        return -1;
    }

    tasks[task_count].task = task;
    tasks[task_count].period_ms = period_ms;
    tasks[task_count].last_run_ms = tick_get_ms();
    task_count++;

    return 0;
}

void scheduler_run(void)
{
    for (uint8_t i = 0; i < task_count; i++)
    {
        if (tick_elapsed(tasks[i].last_run_ms) >= tasks[i].period_ms)
        {
            tasks[i].last_run_ms = tick_get_ms();
            tasks[i].task();
        }
    }
}
