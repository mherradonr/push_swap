/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:29:50 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/27 13:31:42 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack *from, t_stack *to, int print, const char *move)
{
	t_node	*aux;

	if (from->size == 0)
		return ;
	aux = from->top;
	from->top = from->top->next;
	aux->next = to->top;
	to->top = aux;
	from->size--;
	to->size++;
	if (print)
		write(1, move, ft_strlen(move));
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a, 1, "pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b, 1, "pb\n");
}
