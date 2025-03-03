/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:40:58 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/26 18:43:09 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
	{
		error_exit("Error en el numero de argumentos\n");
		return (0);
	}
	initialize_stacks(argc, argv, &stack_a, &stack_b);
	sort_stack(stack_a, stack_b);
	return (0);
}
