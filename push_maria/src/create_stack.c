/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:44:11 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/27 13:13:46 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exit("Entrada no válida: no es un número entero.");
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	initialize_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	*a = start_stack();
	*b = start_stack();
	parsing(argc, argv, a);
	if (!(*a) || !(*b))
		error_exit("Error al iniciar stack.");
}

void	parsing(int argc, char **argv, t_stack **a)
{
	char	**split;
	int		i;

	if (!(*a))
		error_exit("Error al iniciar stack.");
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit("Error al partir argumentos.");
		process_split_arguments(split, a);
		free_split(split);
		i++;
	}
}

void	process_split_arguments(char **split, t_stack **a)
{
	int		j;
	long	num;

	j = 0;
	if (!split[j])
		error_exit("Error al partir argumentos.");
	while (split[j])
	{
		num = ft_atol(split[j]);
		if (num < INT_MIN || num > INT_MAX)
		{
			free_split(split);
			error_exit("Error. Número fuera de rango.");
		}
		if (lst_getindex(num, (*a)->top) != -1)
		{
			free_split(split);
			error_exit("Error. existen numeros duplicados.");
		}
		push_stack(*a, num);
		j++;
	}
}
