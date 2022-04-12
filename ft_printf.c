/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabmd-za <nabmd-za@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:33:53 by nabmd-za          #+#    #+#             */
/*   Updated: 2022/04/13 00:55:51 by nabmd-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_format(int *i, char c, va_list args, int *print_length)
{
	if (c == 'c')
		*print_length += ft_putchar(va_arg(args, int));
	if (c == 's')
		*print_length += ft_putstr(va_arg(args, char *));
	if (c == 'p')
	{
		ft_putstr("0x");
		*print_length += 2;
		ft_putptr(va_arg(args, unsigned long long), print_length);
	}
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), print_length);
	if (c == 'u')
		ft_putu(va_arg(args, unsigned int), print_length);
	if (c == 'x' || c == 'X')
		ft_puthex(va_arg(args, unsigned int), print_length, c);
	if (c == '%')
		*print_length += ft_putchar('%');
	i++;
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	static int	print_length;

	i = 0;
	print_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_parse_format(&i, format[i + 1], args, &print_length);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			print_length++;
		}
		i++;
	}
	va_end(args);
	return (print_length);
}

/** int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		retval;

	retval = 0;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*(fmt - 1) == '%')
		{
			if (*fmt == 'c')
			{
				ft_putchar(va_arg(args, int));
				retval++;
			}
			if (*fmt == 's')
			{
				s = va_arg(args, char *);
				ft_putstr(s);
				retval += ft_strlen(s);
			}
			if (*fmt == 'd' || *fmt == 'i' || *fmt == 'u')
			{
				ft_putnbr(va_arg(args, int));
			}
			if (*fmt == '%')
			{
				write(1, "%", 1);
				retval++;
			}
		}
		if (*fmt != '%' && *(fmt - 1) != '%')
			write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (retval);
} **/