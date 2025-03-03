/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaherradon <mariaherradon@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:54:59 by mariaherrad       #+#    #+#             */
/*   Updated: 2025/02/27 15:31:39 by mariaherrad      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				index;
}		t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;


void	swap(t_stack *stack, int print, const char *move);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	push(t_stack *from, t_stack *to, int print, const char *move);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	rotate(t_stack *stack, int print, const char *move);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

void	reverse_rotate(t_stack *stack, int print, const char *move);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);


void	push_stack(t_stack *stack, int value);
int		pop(t_stack *stack);
void	free_list(t_stack *stack);
void	free_split(char **split);
int		ft_listsize(t_node *stack);


int		print_stack(t_stack *stack);
int		find_max(t_stack *a);
int		lst_getmin(t_stack *stack);
int		lst_getmax(t_stack *stack);
int		lst_maxindex(t_node *stack);


void	sort_two(t_stack *a);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_small_stack(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);

void	radix(t_stack *a, t_stack *b);
void	process_bits(t_stack *a, t_stack *b, int i);
void	bits(t_stack *a, t_stack *b, int bit);
int		calculate_max_bits(int max_num);
void	sort_large_stack(t_stack *a, t_stack *b);

long	ft_atol(const char *str);
long	validate_max_min(const char **str, long result, int sign);
int		duplicates(t_stack *a);
int		is_sorted(t_stack *a);
void	error_exit(const char *message);

t_node	*create_node(int value);
t_stack	*init_stack(void);
void	initialize_stacks(int argc, char **argv, t_stack **a, t_stack **b);
void	parsing(int argc, char **argv, t_stack **a);
void	process_split_arguments(char **split, t_stack **a);

int		find_max_index(t_stack *stack);
int		lst_getindex(long num, t_node *stack);
void	assign_indices(t_stack *stack);
int		min_element(t_stack *stack);

int		main(int argc, char **argv);

#endif