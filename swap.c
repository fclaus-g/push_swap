/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:05:30 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/15 11:04:09 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*sa (intercambio A): Intercambie los primeros 2 elementos
en la parte superior de la pila A. No haga nada si solo hay uno
o ningún elemento. Por ejemplo:
A: 8 3 9
sa
A: 3 8 9*/
void	swap_a(t_box *box)
{
	int	i;

	i = 0;
	if (box->alen > 1)
	{
		i = box->stack_a[0];
		box->stack_a[0] = box->stack_a[1];
		box->stack_a[1] = i;
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_box *box)
{
	int	i;

	i = 0;
	if (box->blen > 0)
	{
		i = box->stack_b[0];
		box->stack_b[0] = box->stack_b[1];
		box->stack_b[1] = i;
		write(1, "sb\n", 3);
	}
}
/*Antes de hacer ss hay que mutear los write de pa y pb*/

void	swap_ab(t_box *box)
{
	swap_a(box);
	swap_b(box);
	write(1, "ss\n", 3);
}
