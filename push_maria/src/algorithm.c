/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:58:02 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/27 15:13:51 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix(t_stack *a, t_stack *b)
{
	int	upper_limit;
	int	num_cycles;
	int	i;

	assign_indices(a);
	upper_limit = find_max_index(a);
	num_cycles = calculate_max_bits(upper_limit);
	i = 0;
	while (i < num_cycles)
	{
		bits(a, b, i);
		i++;
	}
}


void	process_bits(t_stack *a, t_stack *b, int i)
{
	int	size;
	int	j;

	size = a->size;
	j = 0;
	while (j < size)
	{
		if (((a->top->value >> i) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
	while (b->size > 0)
		pa(a, b);
}

void	bits(t_stack *a, t_stack *b, int bit)
{
	int	stack_length;
	int	j;

	stack_length = a->size;
	j = 0;
	while (j < stack_length)
	{
		if (((a->top->index >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
	while (b->size > 0)
		pa(a, b);
}

int	calculate_max_bits(int max_num)
{
	int	top_bits;

	top_bits = 0;
	while ((max_num >> top_bits) != 0)
		top_bits++;
	return (top_bits);
}

void	sort_large_stack(t_stack *a, t_stack *b)
{
	radix(a, b);
	if (!is_sorted(a))
		error_exit("Error: no se ha ordenado correctamente.\n");
}