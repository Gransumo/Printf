
#include "libftprintf.h"

void	ft_putvoid(void *s)
{
	int x;

	x = (int) s;
	ft_putnbr_base(x,"0123456789ABCDEF");
}

void print_type(va_list args, char c)
{
	if(c == 'i' || c == 'd')
		ft_putnbr(va_arg(args, int));
	else if(c == 'c')
		ft_putchar(va_arg(args, int));
	else if(c == 's')
		ft_putstr(va_arg(args, char *));
	else if(c == 'u')
		ft_putnbr_unsig(va_arg(args, unsigned int));
	else if(c == 'p')
		ft_putvoid(va_arg(args, void *));
	else if(c == 'x')
		ft_putnbr_base(va_arg(args, int),"0123456789abcdef");
	else if(c == 'X')
		ft_putnbr_base(va_arg(args, int),"0123456789ABCDEF");
	else if(c == '%')
		write(1, &c, 1);
}

int ft_printf(char const *str, ...)
{
	va_list  args;
	int i;
	COUNT_p  count;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_type(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}

/* int main()
{
	int x;
	char *nombre = "Gabriel Castro"
	int edad = 18;
	char c = 'G';
	unsigned int mayor = 2147483649;
	x = ft_printf("hola mi nombre es %s, tengo %i años, mi letra favorita es la %c, mi edad en hexadecimal es %x y %X, me gusta el simbolo %%\n %u es mayor que el primitivo de int\n\n", nombre, edad, c, edad, edad, mayor);
	printf("%i\n", x);

	return (0);
} */
