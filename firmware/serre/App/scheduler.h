/**
 * @file    scheduler.h
 * @brief   Ordonnanceur cooperatif simple : appelle chaque tache a sa periode.
 */
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

#define SCHEDULER_MAX_TASKS  10U

typedef void (*scheduler_task_t)(void);

/* Ajoute une tache periodique. Retourne 0 si OK, -1 si table pleine ou parametre invalide */
int scheduler_add(scheduler_task_t task, uint32_t period_ms);

/* A appeler en permanence dans la boucle principale */
void scheduler_run(void);

#endif /* SCHEDULER_H */
