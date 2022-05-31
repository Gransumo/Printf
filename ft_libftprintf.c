
#include "libftprintf.h"

static int count_param(char const* str)
{
	int	i;
	int	count;

	count  = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			count++;
		i++;;
	}
	return (i);
}

/* 
• %c Imprime un solo carácter.
• %s Imprime una string (como se define por defecto en C).
• %p El puntero void * dado como argumento se imprime en formato hexadecimal.
• %d Imprime un número decimal (base 10).
• %i Imprime un entero en base 10.
• %u Imprime un número decimal (base 10) sin signo.
• %x Imprime un número hexadecimal (base 16) en minúsculas.
• %X Imprime un número hexadecimal (base 16) en mayúsculas.
• % % para imprimir el símbolo del porcentaje.
*/

void print_type(va_list *args, char c)
{
	if(c == 'i' || c == 'd')
		ft_putnbr(va_arg(*args, int));
	else if(c == 'c')
		ft_putchar(va_arg(*args, char));
	else if(c == 's')
		ft_putstr(va_arg(*args, char *));
	else if(c == 'u')
		ft_putnbr_unsig(va_arg(*args, unsigned char));
	/* else if(c == 'p')
		ft_putvoid(va_arg(args, void));
	else if(c == 'x')

	else if(c == 'X') */

	else if(c == '%')
		write(1, &c, 1);
}

/* void	ft_putvoid(const void *s)
{
	unsigned char *p;

	p = (unsigned char *)
} */

int ft_printf(char const *str, ...)
{
	va_list  args;

	int num;
	int i;

	i = 0;
	num = count_param(str);
	va_start(args, num);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_type(&args, str[i + 1]);
			i++;;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
}

int main()
{
	ft_printf("Hola que tal tio, tengo %i años y mi lema favorito es %s\n finalmente decirte que mi letra de la suerte es la %c", 24, "NUNCA TE RINDAS", 'c');
	return (0);
}