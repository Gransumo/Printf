/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libftprintf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:02:37 by gcastro-          #+#    #+#             */
/*   Updated: 2022/06/03 13:02:39 by gcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void print_type(va_list args, char c, t_data len)
{
	if (c == 'i' || c == 'd')
		ft_putnbr (va_arg(args, int), len);
	else if (c == 'c')
		ft_putchar (va_arg(args, int), len);
	else if (c == 's')
		ft_putstr (va_arg(args, char *), len);
	else if (c == 'u')
		ft_putnbr_unsig (va_arg(args, unsigned int), len);
	else if (c == 'p')
		ft_putvoid (va_arg(args, void *), len);
	else if (c == 'x')
		ft_putnbr_base (va_arg(args, int), "0123456789abcdef", len);
	else if (c == 'X')
		ft_putnbr_base (va_arg(args, int), "0123456789ABCDEF", len);
	else if (c == '%')
		len.len = write (1, &c, 1);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	t_data	len;

	len.len = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_type(args, str[i + 1], len);
			i++;
		}
		else
		{
			ft_putchar(str[i], len);
		}
		i++;
	}
	va_end(args);
	return (len.len);
}

int main()
{
	int x;

	x = ft_printf("mi nombre es %s, tengo %i(%d) años, mi letra favorita es la %c, mi edad en hexa en min es %x y en may es %X, tengo un 100%% de locura.\n", "GABRIEL CASTRO", 18, 18, 'G', 18, 18);
	printf("\n\n%i\n", x);
	return (0);
}
