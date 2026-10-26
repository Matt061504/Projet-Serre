# Serre intelligente - STM32

Projet CESI FISA S3E A4 - module Microcontrôleur (2025-2026).
Mini serre autonome : mesure de l'humidité du sol et de la température, arrosage et ventilation
automatiques selon des consignes réglables, affichage LCD et interface à boutons.

## Fonctionnalités

- Mesure de l'humidité du sol, de la température et de la luminosité
- Arrosage automatique (pompe), ventilation et chauffage régulés autour d'une température cible
- Éclairage d'appoint par 4 LED WS2812B : intensité réglable, spectre bleu / blanc / rouge, lever et coucher progressifs (RTC)
- LED d'état WS2812B : vert OK, bleu arrosage, orange chauffage, rouge défaut
- Mode **AUTO** / **MANUEL** / **MENU**, consignes sauvegardées en flash (aucune reprogrammation)
- 6 boutons (appui court / long) et 3 potentiomètres de réglage direct
- Affichage LCD 16x2 multi-pages + trace sur liaison série (USB ST-LINK)

## Matériel

| Élément | Référence |
|---|---|
| Microcontrôleur | NUCLEO-G031K8 (STM32G031K8, 64 MHz) |
| Humidité du sol | Seeed Grove 101020614 (capacitif, analogique) |
| Température | TI TMP235 (analogique, 10 mV/°C, 500 mV à 0 °C) |
| Luminosité | KY-018 (photorésistance) ou KY-054 (phototransistor) |
| Écran | LCD 16x2 HD44780 (mode 4 bits) |
| Driver moteurs | Joy-IT MotoDriver2 (L298N), IN2 et IN4 reliés au GND |
| Pompe | DFRobot FIT0910 |
| Ventilateur | Sunon MF50100V1 (5 V) |
| Chauffage | Élément chauffant céramique PTC + module MOSFET logique (D4184 / AO3400) |
| Éclairage | 4 LED WS2812B (5 V, 330 Ω sur DIN, 1000 µF sur le 5 V) |
| Boutons | 6 boutons poussoirs (pull-up interne, actifs à l'état bas) |
| Potentiomètres | 3 x 10 kΩ linéaires |
| Alimentation | CUI SWI5-5-E, 5 V / 1 A (source unique) |

## Brochage

| Fonction | Pin Nucleo | GPIO |
|---|---|---|
| Humidité sol | A0 | PA0 (ADC_IN0) |
| TMP235 | A1 | PA1 (ADC_IN1) |
| Luminosité | A2 | PA4 (ADC_IN4) |
| Pot. P1 intensité LED | A6 | PA6 (ADC_IN6) |
| Pot. P2 spectre LED | D6 | PB0 (ADC_IN8) |
| Pot. P3 température cible | D1 | PB7 (ADC_IN11) |
| UART PC | VCP USB | PA2 / PA3 |
| LCD RS / E | D7 / D8 | PB2 / PB8 |
| LCD D4..D7 | D9 / D10 / D11 / D12 | PA8 / PB9 / PB5 / PB4 |
| Bouton AUTO/MANU | D2 | PA15 |
| Bouton MENU/OK | D4 | PA10 |
| Bouton + / − | D3 / A5 | PB1 / PA11 |
| Bouton ARROSAGE | D0 | PB6 |
| Bouton ÉCRAN | D13 | PB3 |
| Pompe (MotoDriver2 IN1) | A3 | PA5 |
| Ventilateur (MotoDriver2 IN3) | A7 | PA7 |
| Chauffage (MOSFET) | A4 | PA12 |
| LED WS2812B (DIN) | D5 | PA9 (TIM1_CH2 + DMA) |
| LED utilisateur Nucleo | - | PC6 |

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
- Liam Barbosa
- David Rafinesque
