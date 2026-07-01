/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:39:35 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 15:39:05 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

/* structure for calcul_cost.c 1er algo */
typedef struct s_position
{
	int		size_a;
	int		size_b;
	int		medium_a;
	int		medium_b;
	int		position_node_in_a;
	int		position_cible_in_b;
	t_list	*cible_of_a_in_b;
}	t_position;

/* structure for 400-500 chiffres 2ème algo */
typedef struct s_b_position
{
	int		size_a;
	int		size_b;
	int		medium_a;
	int		medium_b;
	int		position_node_in_b;
	int		position_cible_in_a;
	t_list	*cible_of_b_in_a;
}	t_b_position;

/* swap.c */
void	ft_swap(t_list **stack_a);
void	ft_swap_2_stacks(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

/* push.c */
void	ft_push_2_to_1(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

/* rotate.c */
void	ft_rotate(t_list **stack_a);
void	ft_rotate_2_stacks(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

/* rotate_reverse.c */
void	ft_rotate_reverse(t_list **stack_a);
void	ft_rotate_reverse_2_stacks(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

/* utils.c */
t_list	*ft_lst_penultimate(t_list *lst);
int		ft_position(t_list *node, t_list *lst);
t_list	*largest_element(t_list *stack);
t_list	*smallest_element(t_list *stack);
void	ft_sort_int_tab(int *tab, int size);

/* find_cible.c */
t_list	*find_cible_of_a(t_list *node_a, t_list *stack_b);
t_list	*find_cible_of_b(t_list *node_b, t_list *stack_a);

/* calcul_cost.c */
int		calcul_cost_total(t_position positions, int cost_a, int cost_b);
int		push_cost_a_to_b(t_list *node_a, t_list *stack_a, t_list *stack_b);

/* move_2_stacks.c */
void	move_both_upwards(t_position	positions,
			t_list *cheapest_a, t_list **stack_a, t_list **stack_b);
void	move_both_downwards(t_position	positions,
			t_list *cheapest_a, t_list **stack_a, t_list **stack_b);
void	move_a_up_b_down(t_position	positions,
			t_list *cheapest_a, t_list **stack_a, t_list **stack_b);
void	move_a_down_b_up(t_position	positions,
			t_list *cheapest_a, t_list **stack_a, t_list **stack_b);

/* push_element.c */
void	ft_2_pb(t_list **stack_a, t_list **stack_b);
void	push_cheapest_a_to_b(t_list *cheapest_a,
			t_list **stack_a, t_list **stack_b);
void	push_element_b_to_a(t_list *node_b, t_list **stack_a, t_list **stack_b);

/* sort.c */
void	sort_2_element(t_list **stack);
void	sort_3_element(t_list **stack);
void	sort_5_element(t_list **stack);
void	sort_stack_after_push(t_list **stack);
void	ft_sort_all(t_list	**l);

/* print_error.c */
void	print_error(void);
void	print_error_exit(t_list **l);

/* validation_args.c */
int		ft_isspace(int c);
int		ft_test_arg(char *str);
int		ft_contains_space(char *str);
int		ft_test_double(t_list *lst, int new_content);
int		test_stack_a(t_list *stack_a);

/* stacks.c */
void	ft_push_a_to_b(t_list **l, t_list **l_b);
void	ft_push_b_to_a(t_list **l, t_list **l_b);

/* chunk_move_stacks.c */
void	move2_both_upwards(t_b_position positions, t_list *cheapest_b,
			t_list **stack_a, t_list **stack_b);
void	move2_both_downwards(t_b_position	positions, t_list *cheapest_b,
			t_list **stack_a, t_list **stack_b);
void	move2_a_up_b_down(t_b_position	positions, t_list *cheapest_b,
			t_list **stack_a, t_list **stack_b);
void	move2_a_down_b_up(t_b_position	positions, t_list *cheapest_b,
			t_list **stack_a, t_list **stack_b);

/* chunk_a_to_b.c */
void	one_chunk_a_to_b(int indice, t_list **l, t_list **l_b);
void	four_chunks_a_to_b(int *tableau, int size_a, t_list **l, t_list **l_b);
void	ft_chunk_a_to_b(t_list **l, t_list **l_b);

/* chunk_b_to_a.c */
int		calcul_cost_total_b(t_b_position positions, int cost_a, int cost_b);
int		push_cost_b_to_a(t_list *node_b, t_list *stack_a, t_list *stack_b);
void	push_cheapest_b_to_a(t_list *cheapest_b,
			t_list **stack_a, t_list **stack_b);
void	ft2_push_b_to_a(t_list **l, t_list **l_b);
void	ft_sort_grand_nb(t_list **l);

/* parsing.c */
void	add_argument_to_list(int *a, char **tab, int k, t_list **l);
void	process_spaced_argument(char *arg, t_list	**l);
void	process_single_argument(char *arg, t_list **l);
int		is_vide(char *argument);
void	ft_arguments(int argc, char **argv, t_list	**l);

/* clear.c */
void	free_tab(char **tab);
void	clear_list(t_list **lst);

#endif
