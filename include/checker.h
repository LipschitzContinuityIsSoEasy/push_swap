/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:37:10 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 15:27:41 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

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

/* print_error.c */
void	print_error(void);
void	print_error_exit(t_list **l);

/* validation_stacks.c */
int		test_stack_a(t_list *stack_a);
int		test_stacks(t_list *stack_a, t_list *stack_b);

/* validation_args.c */
int		ft_isspace(int c);
int		ft_test_arg(char *str);
int		ft_contains_space(char *str);
int		ft_test_double(t_list *lst, int new_content);

/* parsing.c */
void	add_argument_to_list(int *a, char **tab, int k, t_list **l);
void	process_spaced_argument(char *arg, t_list	**l);
void	process_single_argument(char *arg, t_list **l);
int		is_vide(char *argument);
void	ft_arguments(int argc, char **argv, t_list	**l);

/* instruction.c */
void	stock_instruction_in_list(char *instruction,
			t_list **list_instruction, t_list **l);
void	execute_instruction(char *content,
			t_list **stack_a, t_list **stack_b);
void	execute_instructions_on_stacks(t_list **list_instruction,
			t_list **stack_a, t_list **stack_b);
int		is_valid_instruction(char *instruction);
void	read_instruction(int fd, t_list **list_instruction,
			t_list **l, t_list **l_b);

/* clear.c */
void	free_tab(char **tab);
void	clear_list(t_list **lst);
void	clear_all_lists(t_list **l, t_list **l_b, t_list **list_instruction);

#endif
