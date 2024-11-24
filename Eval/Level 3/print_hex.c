/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:15:17 by jlongin           #+#    #+#             */
/*   Updated: 2024/11/24 19:38:54 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
*/
#include <unistd.h>

int	ft_atoi(char *s)
{
	int	n;

	n = 0;
	while (*s)
		n = n * 10 + *s++ - '0';
	return (n);
}

void	ft_puthexa(int n)
{
	char	str[16];

	str = "0123456789abcdef";
	if (n >= 16)
		ft_puthexa(n / 16);
	write(1, &str[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_puthexa(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
