/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:35:51 by usuario42         #+#    #+#             */
/*   Updated: 2023/03/05 13:50:57 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printa(int *array, int len)
{
	int c;

	c = 0;
	while (c < len)
	{
		printf ("%d\n", array[c]);
		c++;
	}
}

int	main(int ac, char **av)
{
	t_box	box;

	if (ac < 2)
		return(write_error(),0);
	save_args(&box, ac, av);
	if (!ft_checknumber(&box))
		return (write_error() ,0);
	box.stack_a = malloc(sizeof(int) * ac);
	box.stack_b = malloc(sizeof(int) * ac);
	box.stack_b = 0;
	arg_to_array(&box);
	if(check_repeat(&box) == 0)
		return(write_error(), 0);
	box.stack_a = simplifier(&box);
	printa (box.stack_a, box.len);
	return (0);
}
