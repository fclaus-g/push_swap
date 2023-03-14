/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:37:34 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/10 10:27:38 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*ra (rotar A): desplaza todos los elementos de la pila A 1 hacia arriba.
 El primer elemento se convierte en el último. Por ejemplo:
 A: 9 2 5 8
 ra
 A: 2 5 8 9*/
void	rotate_a(t_box *box)
{
	int c;
	int aux;

	if(box->alen > 0)
	{
		c = 0;
		aux = box->stack_a[0];
		while (c < box->alen - 1)
		{
			box->stack_a[c] = box->stack_a[c + 1];
			c++;
		}
		box->stack_a[c] = aux;
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_box *box)
{
	int c;
	int aux;

	if(box->blen > 0)
	{
		c = 0;
		aux = box->stack_b[0];
		while (c < box->blen - 1)
		{
			box->stack_b[c] = box->stack_b[c + 1];
			c++;
		}
		box->stack_b[c] = aux;
		write(1, "rb\n", 3);
	}
}

void	rotate_ab(t_box *box)
{
	rotate_a(box);
	rotate_b(box);
	write(1, "rr\n", 3);
}