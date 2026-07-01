/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:31:09 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 15:13:28 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_penultimate(t_list *lst)
{
	if (lst == NULL || lst->next == NULL)
	{
		return (NULL);
	}
	while ((lst->next)->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_position(t_list *node, t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
	{
		return (-1);
	}
	while (lst != NULL)
	{
		if (*(int *)lst->content == *(int *)node->content)
		{
			return (i);
		}
		lst = lst->next;
		i++;
	}
	return (-1);
}

t_list	*largest_element(t_list *stack)
{
	t_list	*current;
	t_list	*largest;

	current = stack;
	if (current == NULL)
	{
		return (NULL);
	}
	largest = stack;
	while (current != NULL)
	{
		if (*(int *)current->content > *(int *)largest->content)
		{
			largest = current;
		}
		current = current->next;
	}
	return (largest);
}

t_list	*smallest_element(t_list *stack)
{
	t_list	*current;
	t_list	*smallest;

	current = stack;
	if (current == NULL)
	{
		return (NULL);
	}
	smallest = stack;
	while (current != NULL)
	{
		if (*(int *)current->content < *(int *)smallest->content)
		{
			smallest = current;
		}
		current = current->next;
	}
	return (smallest);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	stock;

	j = size - 1;
	stock = 0;
	while (j > 0)
	{
		i = size - j;
		while (i > 0)
		{
			if (*(tab + i) < *(tab + i - 1))
			{
				stock = *(tab + i);
				*(tab + i) = *(tab + i - 1);
				*(tab + i - 1) = stock;
			}
			i--;
		}
		j--;
	}
}
