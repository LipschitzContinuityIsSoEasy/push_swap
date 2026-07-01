/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:34:11 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:35:12 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	test_stacks(t_list *stack_a, t_list *stack_b)
{
	if (stack_b != NULL || test_stack_a(stack_a) == 0)
	{
		return (0);
	}
	return (1);
}

int	test_stack_a(t_list *stack_a)
{
	t_list	*current;
	int		nb1;
	int		nb2;

	if (stack_a == NULL || stack_a->next == NULL)
		return (1);
	current = stack_a;
	nb1 = 0;
	nb2 = 0;
	while (current != NULL && current->next != NULL)
	{
		nb1 = *(int *)current->content;
		nb2 = *(int *)(current->next)->content;
		if (nb2 <= nb1)
			return (0);
		current = current->next;
	}
	return (1);
}
