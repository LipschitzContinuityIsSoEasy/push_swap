/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cible.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meiling <meiling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:30:36 by mtian             #+#    #+#             */
/*   Updated: 2024/08/17 17:57:27 by meiling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_cible_of_a(t_list *node_a, t_list *stack_b)
{
	t_list	*current;
	int		diff;
	int		diff_temp;
	t_list	*mark;

	current = stack_b;
	diff = INT_MAX;
	mark = NULL;
	while (current != NULL)
	{
		diff_temp = *(int *)node_a->content - *(int *)current->content;
		if (diff_temp > 0 && diff_temp < diff)
		{
			diff = diff_temp;
			mark = current;
		}
		current = current->next;
	}
	if (mark == NULL)
	{
		return (largest_element(stack_b));
	}
	return (mark);
}

t_list	*find_cible_of_b(t_list *node_b, t_list *stack_a)
{
	t_list	*current;
	int		diff;
	int		diff_temp;
	t_list	*mark;

	current = stack_a;
	diff = INT_MAX;
	mark = NULL;
	while (current != NULL)
	{
		diff_temp = *(int *)current->content - *(int *)node_b->content;
		if (diff_temp > 0 && diff_temp < diff)
		{
			diff = diff_temp;
			mark = current;
		}
		current = current->next;
	}
	if (mark == NULL)
	{
		return (smallest_element(stack_a));
	}
	return (mark);
}
