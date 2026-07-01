/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:33:28 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:34:58 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stock_instruction_in_list(char *instruction,
	t_list **list_instruction, t_list **l)
{
	char	*a;
	t_list	*node;

	a = ft_strdup(instruction);
	if (a == NULL)
	{
		clear_list(list_instruction);
		print_error_exit(l);
	}
	node = ft_lstnew(a);
	if (node == NULL)
	{
		free(a);
		clear_list(list_instruction);
		print_error_exit(l);
	}
	ft_lstadd_back(list_instruction, node);
}

void	execute_instruction(char *content, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(content, "sa\n", 3) == 0)
		ft_swap(stack_a);
	else if (ft_strncmp(content, "sb\n", 3) == 0)
		ft_swap(stack_b);
	else if (ft_strncmp(content, "ss\n", 3) == 0)
		ft_swap_2_stacks(stack_a, stack_b);
	else if (ft_strncmp(content, "pa\n", 3) == 0)
		ft_push_2_to_1(stack_a, stack_b);
	else if (ft_strncmp(content, "pb\n", 3) == 0)
		ft_push_2_to_1(stack_b, stack_a);
	else if (ft_strncmp(content, "ra\n", 3) == 0)
		ft_rotate(stack_a);
	else if (ft_strncmp(content, "rb\n", 3) == 0)
		ft_rotate(stack_b);
	else if (ft_strncmp(content, "rr\n", 3) == 0)
		ft_rotate_2_stacks(stack_a, stack_b);
	else if (ft_strncmp(content, "rra\n", 4) == 0)
		ft_rotate_reverse(stack_a);
	else if (ft_strncmp(content, "rrb\n", 4) == 0)
		ft_rotate_reverse(stack_b);
	else if (ft_strncmp(content, "rrr\n", 4) == 0)
		ft_rotate_reverse_2_stacks(stack_a, stack_b);
}

void	execute_instructions_on_stacks(t_list **list_instruction,
		t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	char	*content;

	current = *list_instruction;
	while (current != NULL)
	{
		content = (char *)current->content;
		execute_instruction(content, stack_a, stack_b);
		current = current->next;
	}
}

int	is_valid_instruction(char *instruction)
{
	if (ft_contains_space(instruction)
		|| (ft_strncmp(instruction, "sa\n", 3)
			&& ft_strncmp(instruction, "sb\n", 3)
			&& ft_strncmp(instruction, "ss\n", 3)
			&& ft_strncmp(instruction, "pa\n", 3)
			&& ft_strncmp(instruction, "pb\n", 3)
			&& ft_strncmp(instruction, "ra\n", 3)
			&& ft_strncmp(instruction, "rb\n", 3)
			&& ft_strncmp(instruction, "rr\n", 3)
			&& ft_strncmp(instruction, "rra\n", 4)
			&& ft_strncmp(instruction, "rrb\n", 4)
			&& ft_strncmp(instruction, "rrr\n", 4)))
	{
		return (0);
	}
	return (1);
}

void	read_instruction(int fd, t_list **list_instruction,
	t_list **l, t_list **l_b)
{
	char	*instruction;

	instruction = get_next_line(fd, 0);
	while (instruction != NULL)
	{
		if (is_valid_instruction(instruction) == 0)
		{
			free(instruction);
			clear_all_lists(l, l_b, list_instruction);
			print_error();
			get_next_line(fd, 1);
			exit(1);
		}
		stock_instruction_in_list(instruction, list_instruction, l);
		free(instruction);
		instruction = get_next_line(fd, 0);
	}
	if (instruction != NULL)
		free(instruction);
}
