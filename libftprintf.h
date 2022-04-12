/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabmd-za <nabmd-za@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:43:26 by nabmd-za          #+#    #+#             */
/*   Updated: 2022/04/13 00:43:28 by nabmd-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *fmt, ...);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_putchar(char c);
void	ft_putnbr(int n, int *print_length);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
void	ft_putptr(unsigned long long n, int *print_length);
void	ft_putu(unsigned int n, int *print_length);
void	ft_puthex(unsigned int n, int *print_length, const char format);

#endif