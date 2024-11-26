/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlongin <jlongin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:59:33 by jlongin           #+#    #+#             */
/*   Updated: 2024/11/25 12:59:41 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
*/
#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list		*temp;
	t_list		*prev;
	t_list		*cur;

	if (!begin_list || !(*begin_list))
		return ;
	cur = *begin_list;
	prev = NULL;
	while (cur)
	{
		if (cmp(cur->data, data_ref) == 0)
		{
			temp = cur;
			if (prev)
				prev->next = cur->next;
			else
				*begin_list = cur->next;
			cur = cur->next;
			free(temp->data);
			free(temp);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
