/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:31:37 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 15:24:35 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_element(t_list **stack)
{
	if (*stack != NULL && (*stack)->next != NULL)
	{
		if (*(int *)(*stack)->content > *(int *)((*stack)->next)->content)
		{
			sa(stack);
		}
	}
}

void	sort_3_element(t_list **stack)
{
	int	var1;
	int	var2;
	int	var3;

	if (ft_lstsize(*stack) != 3)
		return ;
	var1 = *(int *)((*stack)->content);
	var2 = *(int *)(((*stack)->next)->content);
	var3 = *(int *)((((*stack)->next)->next)->content);
	if (var1 > var2 && var2 > var3)
	{
		ra(stack);
		sa(stack);
	}
	else if (var1 > var2 && var2 < var3 && var1 > var3)
		ra(stack);
	else if (var1 < var2 && var2 > var3 && var1 < var3)
	{
		rra(stack);
		sa(stack);
	}
	else if (var1 > var2 && var2 < var3 && var1 < var3)
		sa(stack);
	else if (var1 < var2 && var2 > var3 && var1 > var3)
		rra(stack);
}

void	sort_5_element(t_list **stack)
{
	t_list	*l_b;

	l_b = NULL;
	pb(stack, &l_b);
	pb(stack, &l_b);
	sort_3_element(stack);
	ft2_push_b_to_a(stack, &l_b);
	sort_stack_after_push(stack);
	clear_list(&l_b);
}

void	sort_stack_after_push(t_list **stack)
{
	t_list	*smallest;
	int		position_of_smallest;
	int		medium;

	if (stack == NULL)
	{
		return ;
	}
	smallest = smallest_element(*stack);
	position_of_smallest = ft_position(smallest, *stack);
	medium = ft_lstsize(*stack) / 2;
	if (position_of_smallest < medium)
	{
		while (ft_position(smallest, *stack) > 0)
		{
			ra(stack);
		}
	}
	else if (position_of_smallest >= medium)
	{
		while (ft_position(smallest, *stack) > 0)
		{
			rra(stack);
		}
	}
}

void	ft_sort_all(t_list	**l)
{
	t_list	*l_b;

	l_b = NULL;
	ft_push_a_to_b(l, &l_b);
	ft_push_b_to_a(l, &l_b);
	clear_list(&l_b);
}
