

#ifndef PRINTFT_H

#define PRINTFT_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define count 0

int		ft_strlen(const char *c);
int		ft_printf(char const *str, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
void	ft_putnbr_unsig(unsigned int n);
void	ft_putnbr_base(int nbr, const char *base);
void	ft_putvoid(void *s);

#endif

