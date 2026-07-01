/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:33:56 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 16:30:27 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
