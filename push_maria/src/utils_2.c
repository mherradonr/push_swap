/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:00:02 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/26 19:51:21 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

int	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	return (1);
}

int	find_max(t_stack *a)
{
	t_node	*current;
	int		max;

	if (!a || !a->top)
		error_exit("Error. empty stack");
	current = a->top;
	max = INT_MIN;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	lst_getmin(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		error_exit("Error. empty stack");
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	lst_getmax(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		error_exit("Error, empty stack");
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	lst_maxindex(t_node *stack)
{
	t_node	*aux;
	t_node	*max;

	aux = stack->next;
	max = stack;
	while (aux)
	{
		if (aux->index > max->index)
			max = aux;
		aux = aux->next;
	}
	return (max->index);
}
