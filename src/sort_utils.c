/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:19:05 by azrig             #+#    #+#             */
/*   Updated: 2025/04/21 20:55:05 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_stack *a)
{
	int	min_pos;
	int	size;

	min_pos = ft_min_pos(a);
	size = ft_lstsize(a->top);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		while (min_pos++ < size)
			rra(a);
	}
}

void	sort_two(t_stack *a)
{
	if (*(int *)(a->top->content) > *(int *)(a->top->next->content))
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(a->top->content);
	second = *(int *)(a->top->next->content);
	third = *(int *)(ft_lstlast(a->top)->content);
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third)
		rra(a);
}

void	sort_five(t_stack *a, t_stack *b)
{
	int	pushed;

	pushed = 0;
	while (ft_lstsize(a->top) > 3)
	{
		move_min_to_top(a);
		pb(a, b);
		pushed++;
	}
	sort_three(a);
	while (pushed--)
		pa(a, b);
}
