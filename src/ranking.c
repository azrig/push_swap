/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:18:57 by azrig             #+#    #+#             */
/*   Updated: 2025/04/21 20:08:35 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_arr(t_stack *stack, int size)
{
	t_list	*lst;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	lst = stack->top;
	i = 0;
	while (lst)
	{
		arr[i] = *(int *)(lst->content);
		i++;
		lst = lst->next;
	}
	return (arr);
}

static void	insertion_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

static int	get_position(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_rank(t_stack *stack)
{
	t_list	*lst;
	int		*arr;
	int		size;
	int		pos;

	size = ft_lstsize(stack->top);
	arr = stack_to_arr(stack, size);
	if (!arr)
		return ;
	insertion_sort(arr, size);
	lst = stack->top;
	while (lst)
	{
		pos = get_position(arr, size, *(int *)(lst->content));
		*(int *)(lst->content) = pos;
		lst = lst->next;
	}
	free(arr);
}
