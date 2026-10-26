/**
 * @file    app.h
 * @brief   Point d'entree de l'application serre.
 */
#ifndef APP_H
#define APP_H

/* Initialisation de l'application (apres les MX_xxx_Init) */
void app_init(void);

/* Boucle principale, a appeler dans le while(1) */
void app_loop(void);

#endif /* APP_H */
