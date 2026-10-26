# Firmware

Projet STM32CubeIDE pour la NUCLEO-G031K8 (à générer ici : `firmware/serre/`).

Organisation prévue :

```
Core/        main.c, ordonnanceur (SysTick 1 ms), machine d'états AUTO / MANUEL / MENU
Drivers/     gpio, adc, uart, timer, flash (registres CMSIS / LL - pas d'abstraction Arduino)
Modules/     lcd_hd44780, button, motodriver, soil_sensor, tmp235, light_sensor
App/         regulation, ui_menu, config (consignes en flash), logger (UART)
```

Conventions (cours µC) : préfixe du module sur chaque symbole (`lcd_init()`, `tmp235_read()`),
`snake_case` pour fonctions/variables, `UPPER_CASE` pour constantes, include guards,
retour `0` = OK / `-1` = erreur, pas de globales hors `static`.
