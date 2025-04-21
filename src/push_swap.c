/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 07:58:47 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/04/21 21:39:14 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_args(int argc, char **argv)
{
	char	*arr;
	char	*temp;
	int		i;

	arr = ft_strdup(argv[1]);
	if (!arr)
		return (NULL);
	i = 2;
	while (i < argc)
	{
		temp = arr;
		arr = ft_strjoin(temp, " ");
		free(temp);
		if (!arr)
			return (NULL);
		temp = arr;
		arr = ft_strjoin(temp, argv[i]);
		free(temp);
		if (!arr)
			return (NULL);
		i++;
	}
	return (arr);
}

static void	sort_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = ft_lstsize(a->top);
	if (is_sorted(a))
		return ;
	if (size <= 2)
		sort_two(a);
	else if (size <= 3)
		sort_three(a);
	else if (size <= 5)
		sort_five(a, b);
	else
		radix(a, b);
}

static int	process_args(t_stack *a, char **args)
{
	int	status;

	status = parse_args(a, args);
	free_split(args);
	return (status);
}

static int	handle_input(t_stack *a, int argc, char **argv)
{
	char	*arr;
	char	**args;

	if (argc < 2)
		return (0);
	arr = join_args(argc, argv);
	if (!arr)
		return (-1);
	args = ft_split(arr, ' ');
	free(arr);
	if (!args || !args[0])
	{
		free_split(args);
		return (-1);
	}
	return (process_args(a, args));
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	if (handle_input(&a, argc, argv) < 0)
	{
		ft_lstclear(&a.top, free);
		ft_lstclear(&b.top, free);
		print_error();
		return (1);
	}
	sort_stack(&a, &b);
	ft_lstclear(&a.top, free);
	ft_lstclear(&b.top, free);
	return (0);
}
