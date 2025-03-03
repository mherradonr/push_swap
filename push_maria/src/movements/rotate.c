/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:39:05 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/27 13:34:20 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack *stack, int print, const char *move)
{
	t_node	*head;
	t_node	*bottom;

	if (stack->size < 2)
		return ;
	head = stack->top;
	bottom = stack->top;
	stack->top = head->next;
	while (bottom->next)
		head = bottom->next;
	bottom->next = head;
	head->next = NULL;
	if (print)
		write(1, move, ft_strlen(move));
}

void	ra(t_stack *a)
{
	rotate(a, 1, "ra\n");
}

void	rb(t_stack *b)
{
	rotate(b, 1, "rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, 0, NULL);
	rotate(b, 0, NULL);
	write(1, "rr\n", 3);
}
