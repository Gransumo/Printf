/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:41:48 by gcastro-          #+#    #+#             */
/*   Updated: 2022/04/08 18:41:49 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int nbr, t_data len)
{
	long int	n;

	n = nbr;
	if (n == -2147483648)
	{	
		ft_putchar ('-', len);
		ft_putchar ('2', len);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar ('-', len);
		n = -n;
	}
	if (n <= 9 && n >= 0)
		ft_putchar (n + '0', len);
	else
	{
		ft_putnbr (n / 10, len);
		ft_putnbr (n % 10, len);
	}
}

void	ft_putnbr_unsig(unsigned int n, t_data len)
{
	if (n <= 9 && n >= 0)
		ft_putchar (n + '0', len);
	else
	{
		ft_putnbr (n / 10, len);
		ft_putnbr (n % 10, len);
	}
}
