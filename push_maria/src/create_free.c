/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:58:52 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/27 15:20:31 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_stack(t_stack *stack, int value)
{
	t_node	*fresh_node;
	t_node	*end_node;

	fresh_node = create_node(value);
	if (!fresh_node)
	{
		error_exit("Error: no se pudo asignar memoria para el nodo");
		exit(EXIT_FAILURE);
	}
	fresh_node->next = NULL;
	end_node = stack->top;
	if (end_node == NULL)
		stack->top = fresh_node;
	else
	{
		while (end_node->next)
			end_node = end_node->next;
		end_node->next = fresh_node;
	}
	stack->size++;
} 


int	pop(t_stack *stack)
{
	t_node	*aux;
	int		value;

	if (stack->top == NULL)
	{
		error_exit("Error. empty stack");
		exit(EXIT_FAILURE);
	}
	aux = stack->top;
	value = aux->value;
	stack->top = stack->top->next;
	free(aux);
	stack->size--;
	return (value);
}

void	free_list(t_stack *stack)
{
	t_node	*actual;
	t_node	*next;

	if (!stack)
		return ;
	actual = stack->top;
	while (actual)
	{
		next = actual->next;
		free(actual);
		actual = next;
	}
	free(stack);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_listsize(t_node *stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}
