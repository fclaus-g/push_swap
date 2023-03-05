/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:08:38 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/04 12:40:24 by fernandocla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int save_args(t_box *box, int ac, char **av)
{
    int i;

    i = 0;
    if (ac == 2)
    	box->arg = ft_split(av[1], ' ');		
	else 
	{
		box->arg = malloc(sizeof(char*) * ac);
		if (!box->arg)
			return(0);
		while (av[i + 1] != NULL)
		{
			box->arg[i] = ft_strcpy(box->arg[i], av[i + 1]);
			i++;
		}
		box->arg[i] = NULL;
	}
    return (1);
}