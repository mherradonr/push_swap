/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:59:24 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/27 15:21:59 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max_index;

	if (!stack || !stack->top)
		error_exit("Error. empty stack");
	current = stack->top;
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

int	lst_getindex(long num, t_node *stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		if (aux->value == num)
			return (i);
		aux = aux->next;
		i++;
	}
	return (-1);
}

void	assign_indices(t_stack *stack)
{
	t_node	*node_ptr;
	t_node	*comparator;
	int		position;

	if (!stack || !stack->top)
		return ;
	node_ptr = stack->top;
	while (node_ptr)
	{
		position = 0;
		comparator = stack->top;
		while (comparator)
		{
			if (comparator->value < node_ptr->value)
				position++;
			comparator = comparator->next;
		}
		node_ptr->index = position;
		node_ptr = node_ptr->next;
	}
}

int	min_element(t_stack *stack)
{
	t_node	*head;
	int		min;

	head = stack->top;
	min = head->value;
	while (head)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
	}
	return (min);
}
