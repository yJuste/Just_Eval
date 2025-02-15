/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -----------------------PROTOTYPAGE----------------------
int			ft_printf(const char *format, ...);
void		ft_putchar(int c, int *count);
void		ft_putstr(char *str, int *count);
void		ft_putnbr(int n, int *count);
void		ft_puthexa(unsigned int n, int *count);
// --------------------------------------------------------

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			if (*format == 's')
				ft_putstr(va_arg(ap, char *), &count);
			else if (*format == 'd')
				ft_putnbr(va_arg(ap, int), &count);
			else if (*format == 'x')
				ft_puthexa(va_arg(ap, unsigned int), &count);
			else
				ft_putchar(*format, &count);
		}
		else
			ft_putchar(*format, &count);
		format++;
	}
	va_end(ap);
	return (count);
}

void	ft_putchar(int c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str++, 1);
		(*count)++;
	}
}

void	ft_putnbr(int n, int *count)
{
	static char	str[10] = "0123456789";

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*count += 11;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		*count += 1;
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10, count);
	write(1, &str[n % 10], 1);
	(*count)++;
}

void	ft_puthexa(unsigned int n, int *count)
{
	static char	str[16] = "0123456789abcdef";

	if (n >= 16)
		ft_puthexa(n / 16, count);
	write(1, &str[n % 16], 1);
	(*count)++;
}
