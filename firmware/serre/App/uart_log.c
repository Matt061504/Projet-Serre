/**
 * @file    uart_log.c
 * @brief   Redirection de printf vers l'USART2 (115200 8N1, configure par CubeMX).
 *
 * syscalls.c (genere par CubeIDE) appelle __io_putchar() pour chaque caractere
 * envoye par printf.
 */
#include "uart_log.h"
#include "main.h"
#include <stdio.h>

#define UART_LOG_USART  USART2

void uart_log_init(void)
{
    setvbuf(stdout, NULL, _IONBF, 0);
}

void uart_log_putc(char c)
{
    /* attente registre de transmission libre */
    while (!LL_USART_IsActiveFlag_TXE_TXFNF(UART_LOG_USART))
    {
    }
    LL_USART_TransmitData8(UART_LOG_USART, (uint8_t)c);
}

int __io_putchar(int ch)
{
    /* \n -> \r\n pour les terminaux serie */
    if (ch == '\n')
    {
        uart_log_putc('\r');
    }
    uart_log_putc((char)ch);
    return ch;
}
