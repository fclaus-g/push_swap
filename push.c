/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:52:10 by usuario42         #+#    #+#             */
/*   Updated: 2023/03/07 11:31:30 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*pa (empuje A): tome el primer elemento en la parte superior
de la pila B y colóquelo en la parte superior de la pila A. 
No haga nada si B está vacío. Por ejemplo:
A: 1 3 4
B: 5 9
pa
A: 5 1 3 4
B: 9*/
void    push_a(t_box *box)
{
    int i;

   
    if (box->blen > 0)
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