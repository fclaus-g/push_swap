/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:11:14 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/13 09:45:31 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rra (rotación inversa A): desplaza todos los elementos de 
la pila A 1 hacia abajo. El último elemento se convierte 
en el primero. Por ejemplo:
A: 1 2 4 9 0
rra
A: 0 1 2 4 9*/
void    reverse_a(t_box *box)
{
	int c;
	int aux;

	if (box->alen > 1)
	{
		aux = box->stack_a[box->alen - 1];
		c = box->alen -1;
		while (c > 0)
		{
			box->stack_a[c] = box->stack_a[c - 1];
			c--;
		}
		box->stack_a[c] = aux;
		write (1, "rra\n", 4);
	}
}

void    reverse_b(t_box *box)
{
	int c;
	int aux;

	if (box->blen > 1)
	{
		aux = box->stack_b[box->blen - 1];
		c = box->blen - 1;
		while (c > 0)
		{
			box->stack_b[c] = box->stack_b[c - 1];
			c --;
		}
		box->stack_a[c] = aux;
		write (1, "rrb\n", 4);
	}
}

void    reverse_ab(t_box *box)
{
	reverse_a(box);
	reverse_b(box),
	write (1, "rrr\n", 4);
}
