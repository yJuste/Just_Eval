/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:14:18 by jlongin           #+#    #+#             */
/*   Updated: 2024/11/27 12:29:42 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
*/
#include <unistd.h>

int	ft_atoi(char *s)
{
	int		res;

	res = 0;
	while (*s)
		res = res * 10 + *s++ - '0';
	return (res);
}

void	ft_putnbr(int n)
{
	char		nb;

	if (n >= 10)
		ft_putnbr(n / 10);
	nb = n % 10 + '0';
	write(1, &nb, 1);
}

int	ft_isprime(int n)
{
	int		i;

	i = 2;
	if (n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		nb;
	int		count;

	i = 0;
	count = 0;
	nb = ft_atoi(argv[1]);
	if (argc == 2)
	{
		while (i <= nb)
		{
			if (ft_isprime(i))
				count += i;
			i++;
		}
		ft_putnbr(count);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}
