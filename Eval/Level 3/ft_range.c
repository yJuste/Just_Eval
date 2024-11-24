/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:17:39 by jlongin           #+#    #+#             */
/*   Updated: 2024/11/24 19:38:16 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/

#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int		i;
	int		len;
	int		*str;

	if (start > end)
		len = start - end;
	else
		len = end - start;
	str = malloc(sizeof(int) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = start;
		if (start > end)
			start--;
		else
			start++;
		i++;
	}
	return (str);
}
