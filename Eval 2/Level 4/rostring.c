/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/
#include <unistd.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		flg;
	char	*str;

	i = 0;
	j = 0;
	flg = 0;
	if (argc >= 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		j = i;
		while (argv[1][i] > 32 && argv[1][i] < 127)
			i++;
		str = malloc(sizeof(char) * (i - j + 1));
		if (!str)
			return (1);
		ft_strncpy(str, &argv[1][j], i - j);
		while (argv[1][i])
		{
			if (flg == 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			{
				flg = 1;
				i++;
			}
			if (argv[1][i] > 32 && argv[1][i] < 127)
				write(1, &argv[1][i], 1);
			else
				write(1, " ", 1);
			if (argv[1][i + 1] == '\0')
				write(1, " ", 1);
			i++;
		}
		i = 0;
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		free(str);
	}
	write(1, "\n", 1);
	return (0);
}
