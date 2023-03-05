/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:05:30 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/05 13:21:47 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_box *box)
{
    int i;

    i = 0;
    if (box->alen > 0)
    {
        i = box->stack_a[0];
        box->stack_a[0] = box->stack_a[1];
        box->stack_a[1] = i;
        write (1,"sa\n", 3);
    }
}

void    swap_b(t_box *box)
{
    int i;

    i = 0;
    if (box->blen > 0)
    {
        i = box->stack_b[0];
        box->stack_b[0] = box->stack_b[1];
        box->stack_b[1] = i;
        write (1,"sb\n", 3);
    }
}

void    swap_ab(t_box *box)
{
    swap_a(&box);
    swap_b(&box);
    write (1,"ss\n", 3);
}