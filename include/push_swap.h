/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrig <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:59:40 by azrig             #+#    #+#             */
/*   Updated: 2025/04/21 20:55:36 by azrig            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "libft.h"
# include "stdlib.h"
# include "limits.h"

typedef struct s_stack
{
	t_list	*top;
}			t_stack;

void		init_stack(t_stack *stack);
int			push(t_stack *stack, int value);
int			pop(t_stack *stack);
void		sa(t_stack *a);
void		pb(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rra(t_stack *a);
void		sort_two(t_stack *a);
void		sort_three(t_stack *a);
void		sort_five(t_stack *a, t_stack *b);
void		radix(t_stack *a, t_stack *b);
int			is_sorted(t_stack *a);
int			ft_max_bits(t_stack *a);
int			ft_min_pos(t_stack *a);
void		move_min_to_top(t_stack *a);
void		ft_rank(t_stack *stack);
int			is_valid_number(const char *str);
int			parse_args(t_stack *a, char **args);
long		ft_atol(char *nptr);
void		free_split(char **split);
void		print_error(void);

#endif
