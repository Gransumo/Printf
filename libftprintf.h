

#ifndef PRINTFT_H

#define PRINTFT_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int		ft_printf(char const *str, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
//numericos
void	ft_putnbr(int n);
void	ft_putnbr_unsig(unsigned int n);

#endif

