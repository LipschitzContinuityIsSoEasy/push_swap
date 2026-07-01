/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:34:19 by mtian             #+#    #+#             */
/*   Updated: 2024/08/16 16:34:20 by mtian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_list	*l;
	t_list	*l_b;
	int		fd;
	t_list	*list_instruction;

	fd = 0;
	l = NULL;
	list_instruction = NULL;
	l_b = NULL;
	if (argc == 1)
		return (0);
	ft_arguments(argc, argv, &l);
	read_instruction(fd, &list_instruction, &l, &l_b);
	execute_instructions_on_stacks(&list_instruction, &l, &l_b);
	if (test_stacks(l, l_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_all_lists(&l, &l_b, &list_instruction);
	return (0);
}
