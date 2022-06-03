/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:02:12 by gcastro-          #+#    #+#             */
/*   Updated: 2022/06/03 13:02:15 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTFT_H
#define PRINTFT_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
typedef struct s_data
{
	int	len;
}	t_data;
int		ft_strlen(const char *c);
int		ft_printf(char const *str, ...);
void	ft_putchar(char c, t_data len);
void	ft_putstr(char *s, t_data len);
void	ft_putnbr(int nbr, t_data len);
void	ft_putnbr_unsig(unsigned int n, t_data len);
void	ft_putnbr_base(int nbr, const char *base, t_data len);
void	ft_putvoid(void *s, t_data len);

#endif

