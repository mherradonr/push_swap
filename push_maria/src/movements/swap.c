/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:39:30 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/27 13:36:11 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack *stack, int print, const char *move)
{
	t_node	*one;
	t_node	*two;

	one = stack->top;
	two = one->next;
	one->next = two->next;
	two->next = one;
	stack->top = two;
	if (print)
		write(1, move, ft_strlen(move));
}

void	sa(t_stack *a)
{
	swap(a, 1, "sa\n");
}

void	sb(t_stack *b)
{
	swap(b, 1, "sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a, 0, NULL);
	swap(b, 0, NULL);
	write(1, "ss\n", 3);
}
