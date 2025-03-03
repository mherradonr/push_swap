/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:56:51 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/26 19:52:16 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str))
		error_exit("Error: no es un número entero.");
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str)
		error_exit("Error: no es un número entero.");
	return (result * sign);
}

long	validate_max_min(const char **str, long result, int sign)
{
	while (**str >= '0' && **str <= '9')
	{
		if (sign == 1 && result > (LONG_MAX - (**str - '0')) / 10)
			return (LONG_MAX);
		if (sign == -1 && result > (LONG_MAX - (**str - '0')) / 10)
			return (LONG_MIN);
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result);
}

int	duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*check;

	current = a->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || a->size <= 1)
		return (1);
	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	error_exit(const char *message)
{
	(void)message;
	write(2, "Error.\n", 7);
	exit(EXIT_FAILURE);
}
