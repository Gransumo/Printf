/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:19:36 by gcastro-          #+#    #+#             */
/*   Updated: 2021/10/13 12:19:37 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"

static int	check_error(const char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0')
		return (0);
	if (ft_strlen(base) == 1)
		return (0);
	while (base[i] != '\0')
	{
		while (base[i] != base[j] && j < i - 1)
			j++;
		if (base[i] == base[j])
			return (0);
		j = 0;
		if (!(base[i] > 47 && base[i] < 58) && \
			!(base[i] > 64 && base[i] < 91) && !(base[i] > 96 && base[i] < 123))
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, const char *base, t_data len)
{
	long int	nbr2;

	nbr2 = nbr;
	if (check_error(base) == 1)
	{
		if (nbr2 < 0)
		{
			ft_putchar ('-', len);
			nbr2 = -nbr2;
		}
		if (nbr2 < ft_strlen (base))
			ft_putchar(base[nbr], len);
		else if (nbr2 >= ft_strlen (base))
		{
			ft_putnbr_base(nbr2 / ft_strlen(base), base, len);
			ft_putchar(base[nbr2 % ft_strlen(base)], len);
		}
	}
}
