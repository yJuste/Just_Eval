/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:19:05 by jlongin           #+#    #+#             */
/*   Updated: 2024/11/27 12:26:03 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);
*/

int	ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char		x;

	x = *a;
	*a = *b;
	*b = x;
}

char	*ft_strrev(char *str)
{
	int		i;

	i = 0;
	while (i < ft_strlen(str) / 2)
	{
		ft_swap(&str[i], &str[ft_strlen(str) - i - 1]);
		i++;
	}
	return (str);
}
