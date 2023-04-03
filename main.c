/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:35:51 by usuario42         #+#    #+#             */
/*   Updated: 2023/04/03 12:29:39 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_leaks(void)
{
	system("leaks push_swap");
}*/

int	main(int ac, char **av)
{
	t_box	box;

	if (ac < 2)
		return (write_error(), 0);
	save_args(&box, ac, av);
	if (!ft_checknumber(&box))
		return (write_error(), 0);
	box.stack_a = malloc(sizeof(int) * ft_mtrlen(box.arg));
	box.stack_b = malloc(sizeof(int) * ft_mtrlen(box.arg));
	arg_to_array(&box);
	if (check_repeat(&box) == 0)
		return (free_stacks(&box), write_error(), 0);
	if (in_order(&box) == 1)
		return (free_stacks(&box), 0);
	box.stack_a = simplifier(&box);
	ft_sorting(&box);
	free_stacks(&box);
	return (0);
}
