/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabmd-za <nabmd-za@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:34:03 by nabmd-za          #+#    #+#             */
/*   Updated: 2022/04/13 00:34:04 by nabmd-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n, int *print_length)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		ft_putchar('-');
		*print_length += 1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10, print_length);
	ft_putchar(nb % 10 + '0');
	*print_length += 1;
}

void	ft_putptr(unsigned long long n, int *print_length)
{
	if (n == 0)
	{
		ft_putchar('0');
		*print_length += 1;
		return ;
	}
	if (n >= 16)
		ft_putptr(n / 16, print_length);
	if (n % 16 < 10)
		ft_putchar(n % 16 + 48);
	else
		ft_putchar(n % 16 + 'a' - 10);
	*print_length += 1;
}

void	ft_putu(unsigned int n, int *print_length)
{
	long long int	nb2;

	nb2 = n;
	if (nb2 >= 10)
		ft_putu(nb2 / 10, print_length);
	ft_putchar(nb2 % 10 + 48);
	*print_length += 1;
}

void	ft_puthex(unsigned int n, int *print_length, const char format)
{
	long long	nb;

	nb = n;
	if (nb >= 16)
		ft_puthex(nb / 16, print_length, format);
	if (nb % 16 < 10)
		ft_putchar(nb % 16 + 48);
	else
	{
		if (format == 'x')
			ft_putchar(nb % 16 + 'a' - 10);
		else
			ft_putchar(nb % 16 + 'A' - 10);
	}
	*print_length += 1;
}
