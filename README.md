# Serre intelligente — STM32

Projet CESI FISA S3E A4 — module Microcontrôleur (2025-2026).
Mini serre autonome : mesure de l'humidité du sol et de la température, arrosage et ventilation
automatiques selon des consignes réglables, affichage LCD et interface à boutons.

## Fonctionnalités

- Mesure humidité du sol (capteur capacitif) et température (TMP235)
- Affichage local LCD 16x2 + trace sur liaison série (USB ST-LINK)
- Pilotage pompe d'arrosage et ventilateur via MotoDriver2 (L298N)
- Mode **AUTO** (régulation à hystérésis) / **MANUEL** (boutons) / **MENU** (réglage des consignes)
- Consignes sauvegardées en flash : aucune reprogrammation nécessaire
- Option : mesure de luminosité + éclairage LED

## Matériel

| Élément | Référence |
|---|---|
| Microcontrôleur | NUCLEO-G031K8 (STM32G031K8) |
| Humidité du sol | Seeed Grove 101020614 (capacitif, analogique) |
| Température | TI TMP235 (analogique, 10 mV/°C, 500 mV à 0 °C) |
| Écran | LCD 16x2 HD44780 (mode 4 bits) |
| Driver moteurs | Joy-IT MotoDriver2 (L298N) |
| Ventilateur | Sunon MF50100V1 (5 V) |
| Pompe | DFRobot FIT0910 |
| Alimentation | CUI SWI5-E (source unique) |

## Brochage

| Fonction | Pin Nucleo | GPIO |
|---|---|---|
| Humidité sol | A0 | PA0 (ADC_IN0) |
| TMP235 | A1 | PA1 (ADC_IN1) |
| Luminosité (option) | A2 | PA4 (ADC_IN4) |
| UART PC | VCP USB | PA2 / PA3 |
| LCD RS / E | D7 / D8 | PB2 / PB8 |
| LCD D4..D7 | D9 / D10 / D11 / D12 | PA8 / PB9 / PB5 / PB4 |
| Boutons MODE / OK / + / − | D2 / D4 / D3 / D6 | PA15 / PA10 / PB1 / PB0 |
| Pompe IN1 / IN2 | A3 / A6 | PA5 / PA6 |
| Ventilateur IN3 / IN4 | A7 / D13 | PA7 / PB3 |
| LED éclairage (option) | D5 | PA9 (TIM1_CH2) |

## Arborescence

```
firmware/          code embarqué (projet STM32CubeIDE)
docs/rapport/      rapport technique, notice d'utilisation
docs/schemas/      schéma global, algorigrammes
hardware/cablage/  schéma de câblage
hardware/meca/     fichiers de conception mécanique
tools/             outils PC (ex. dashboard Node-RED)
```

## Compiler / flasher

1. Ouvrir `firmware/serre` dans STM32CubeIDE
2. Build (`Ctrl+B`), puis Run sur la NUCLEO-G031K8 branchée en USB

## Workflow Git

- `main` : version stable, démontrable
- `dev` : intégration
- `feature/<nom>` : une branche par module (ex. `feature/lcd`), merge vers `dev` par pull request

## Équipe

- Mattéo Sourdes
