/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 08:01:45 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/21 19:05:37 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_max_bits(t_stack *a)
{
	t_list	*lst;
	int		max;
	int		bits;

	lst = a->top;
	max = 0;
	bits = 0;
	while (lst)
	{
		if (*(int *)(lst->content) > max)
			max = *(int *)(lst->content);
		lst = lst->next;
	}
	while (max)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	radix(t_stack *a, t_stack *b)
{
	int		max_bits;
	int		i;
	int		size;

	ft_rank(a);
	max_bits = ft_max_bits(a);
	i = 0;
	while (i < max_bits)
	{
		size = ft_lstsize(a->top);
		while (size)
		{
			if ((((*(int *)(a->top->content)) >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			size--;
		}
		while (b->top)
			pa(a, b);
		i++;
	}
}
