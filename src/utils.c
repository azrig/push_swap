/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 18:19:19 by azrig             #+#    #+#             */
/*   Updated: 2025/04/21 20:19:25 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_stack *a)
{
	t_list	*current;

	if (!a->top || !a->top->next)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (*(int *)(current->content) > *(int *)(current->next->content))
			return (0);
		current = current->next;
	}
	return (1);
}

static int	check_double(t_stack *a, int value)
{
	t_list	*current;

	current = a->top;
	while (current)
	{
		if (*(int *)(current->content) == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(t_stack *a, char **args)
{
	int		i;
	long	num;
	t_list	*node;
	int		*content;

	i = 0;
	while (args[i])
	{
		if (!is_valid_number(args[i]))
			return (-1);
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX || check_double(a, (int)num))
			return (-1);
		content = malloc(sizeof(int));
		if (!content)
			return (-1);
		*content = (int)num;
		node = ft_lstnew(content);
		if (!node)
			return (free(content), -1);
		ft_lstadd_back(&a->top, node);
		i++;
	}
	return (0);
}
