/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <mtian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:31:20 by mtian             #+#    #+#             */
/*   Updated: 2024/08/19 15:25:14 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*l;

	l = NULL;
	ft_arguments(argc, argv, &l);
	if (ft_lstsize(l) == 1 || test_stack_a(l))
	{
		clear_list(&l);
		return (0);
	}
	else if (ft_lstsize(l) == 2)
		sort_2_element(&l);
	else if (ft_lstsize(l) == 3)
		sort_3_element(&l);
	else if (ft_lstsize(l) == 5)
		sort_5_element(&l);
	else if (ft_lstsize(l) >= 400 && ft_lstsize(l) <= 500)
		ft_sort_grand_nb(&l);
	else
		ft_sort_all(&l);
	clear_list(&l);
	return (0);
}
