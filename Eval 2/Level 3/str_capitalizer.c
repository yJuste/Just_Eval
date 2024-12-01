/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX"
"   But... This iS not THAT COMPLEX"
"     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		ac;
	int		count;

	ac = 1;
	if (argc == 1)
		return (write(1, "\n", 1));
	while (ac < argc)
	{
		i = 0;
		count = 1;
		while (argv[ac][i])
		{
			if (argv[ac][i] == ' ' || argv[ac][i] == '\t')
				count = 1;
			if ((argv[ac][i] >= 'a' && argv[ac][i] <= 'z')
				|| (argv[ac][i] >= 'A' && argv[ac][i] <= 'Z'))
			{
				if (count)
				{
					if (argv[ac][i] >= 'a' && argv[ac][i] <= 'z')
						argv[ac][i] -= 32;
					count = 0;
				}
				else if (argv[ac][i] >= 'A' && argv[ac][i] <= 'Z')
					argv[ac][i] += 32;
			}
			write(1, &argv[ac][i], 1);
			i++;
		}
		write(1, "\n", 1);
		ac++;
	}
	return (0);
}
