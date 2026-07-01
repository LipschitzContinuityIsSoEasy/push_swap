/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:31:47 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:31:52 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	if (c == 32)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_contains_space(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			if (ft_isspace(str[i]))
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	ft_test_arg(char *str)
{
	int		nb;
	char	*new_str;
	int		l;

	nb = ft_atoi(str);
	new_str = ft_itoa(nb);
	l = ft_strlen(str);
	if (ft_strncmp(str, new_str, l) == 0)
	{
		free(new_str);
		return (1);
	}
	free(new_str);
	return (0);
}

int	ft_test_double(t_list *lst, int new_content)
{
	t_list	*current;

	if (lst != NULL)
	{
		current = lst;
		while (current != NULL)
		{
			if (*(int *)current->content == new_content)
			{
				return (1);
			}
			current = current->next;
		}
	}
	return (0);
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
