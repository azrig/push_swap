/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:18:46 by azrig             #+#    #+#             */
/*   Updated: 2025/04/21 18:38:02 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	tmp1;
	int	tmp2;

	if (!a->top || !a->top->next)
		return ;
	tmp1 = pop(a);
	tmp2 = pop(a);
	push(a, tmp1);
	push(a, tmp2);
	write(1, "sa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->top)
		return ;
	push(b, pop(a));
	write(1, "pb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	if (!b->top)
		return ;
	push(a, pop(b));
	write(1, "pa\n", 3);
}

void	ra(t_stack *a)
{
	t_list	*tmp;
	t_list	*last;

	if (!a->top || !a->top->next)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	tmp->next = NULL;
	last = ft_lstlast(a->top);
	last->next = tmp;
	write(1, "ra\n", 3);
}

void	rra(t_stack *a)
{
	t_list	*last;
	t_list	*prev;

	if (!a->top || !a->top->next)
		return ;
	last = ft_lstlast(a->top);
	prev = a->top;
	while (prev->next != last)
		prev = prev->next;
	prev->next = NULL;
	last->next = a->top;
	a->top = last;
	write(1, "rra\n", 4);
}
