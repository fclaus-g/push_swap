/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:52:10 by usuario42         #+#    #+#             */
/*   Updated: 2023/03/05 13:36:10 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_box *box)
{
    int i;

   
    if (box->alen > 0)
    {
        i = box->alen;
        while (i > 0)
        {
            box->stack_a[i] = box->stack_a[i - 1];
            i--;
        }
        box->stack_a[i] = box->stack_b[0];
        while (i < box->blen)
        {
            box->stack_b[i] = box->stack_b[i + 1];
            i++; 
        }
        box->alen++;
        box->blen--;
        write (1, "pa\n", 3);
    }
    return;
}

void    push_b(t_box *box)
{
    int i;

  
    if (box->alen > 0)
    {
        i = box->blen;
        while (i > 0)
        {
            box->stack_b[i] = box->stack_b[i - 1];
            i--;
        }
        box->stack_b[i] = box->stack_a[0];
        while (i < box->alen)
        {
            box->stack_a[i] = box->stack_a[i + 1];
            i++;
        }
        box->blen++;
        box->alen--;
        write (1, "pb\n", 3);
    }
    return;
}