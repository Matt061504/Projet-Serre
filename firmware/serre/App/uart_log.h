/**
 * @file    uart_log.h
 * @brief   Redirection de printf vers l'USART2 (port COM virtuel du ST-LINK).
 */
#ifndef UART_LOG_H
#define UART_LOG_H

/* Desactive le buffer de stdout pour un affichage immediat */
void uart_log_init(void);

/* Envoi d'un caractere (bloquant) */
void uart_log_putc(char c);

#endif /* UART_LOG_H */
