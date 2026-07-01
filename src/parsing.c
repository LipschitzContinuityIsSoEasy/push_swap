/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:29:30 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 16:55:06 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_argument_to_list(int *a, char **tab, int k, t_list **l)
{
	t_list	*node;

	if (ft_test_arg(tab[k]) != 1)
	{
		free(a);
		free_tab(tab);
		print_error_exit(l);
	}
	*a = ft_atoi(tab[k]);
	node = ft_lstnew(a);
	if (node == NULL)
	{
		free(a);
		free_tab(tab);
		print_error_exit(l);
	}
	if (ft_test_double(*l, *a))
	{
		free(node);
		free(a);
		free_tab(tab);
		print_error_exit(l);
	}
	ft_lstadd_back(l, node);
}

void	process_spaced_argument(char *arg, t_list **l)
{
	int		*a;
	char	**tab;
	int		k;

	tab = ft_split(arg, ' ');
	if (tab == NULL)
	{
		print_error_exit(l);
	}
	k = 0;
	while (tab[k] != NULL)
	{
		a = (int *)malloc(sizeof(int) * 1);
		if (a == NULL)
		{
			free_tab(tab);
			print_error_exit(l);
		}
		add_argument_to_list(a, tab, k, l);
		k++;
	}
	free_tab(tab);
}

void	process_single_argument(char *arg, t_list **l)
{
	int		*a;
	t_list	*node;

	a = (int *)malloc(sizeof(int) * 1);
	if (a == NULL)
		print_error_exit(l);
	if (ft_test_arg(arg) != 1)
	{
		free(a);
		print_error_exit(l);
	}
	*a = ft_atoi(arg);
	if (ft_test_double(*l, *a))
	{
		free(a);
		print_error_exit(l);
	}
	node = ft_lstnew(a);
	if (node == NULL)
	{
		free(a);
		print_error_exit(l);
	}
	ft_lstadd_back(l, node);
}

int	is_vide(char *argument)
{
	if (ft_strncmp(argument, "", 1) == 0)
	{
		return (1);
	}
	return (0);
}

void	ft_arguments(int argc, char **argv, t_list	**l)
{
	int	i;

	if (argc <= 1)
	{
		clear_list(l);
		exit(1);
	}
	i = 1;
	while (i < argc)
	{
		if (is_vide(argv[i]))
		{
			print_error_exit(l);
		}
		else if (ft_contains_space(argv[i]))
		{
			process_spaced_argument(argv[i], l);
		}
		else
		{
			process_single_argument(argv[i], l);
		}
		i++;
	}
}
