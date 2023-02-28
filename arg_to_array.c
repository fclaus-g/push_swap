/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:15:12 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/02/28 11:02:47 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	size_t	count;
	size_t	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while ((str[count] >= 9 && str[count] <= 13) || str[count] == 32)
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (ft_isdigit(str[count]))
	{
		result = result * 10 + str[count] - 48;
		count++;
	}
	return (sign * result);
}

void	arg_to_array(t_box *box)
{
	int	i;

	i = 0;
	while (box->arg[i] != NULL)
	{
		box->stack_a[i] = ft_atoi(box->arg[i]);
		printf("%d\n", box->stack_a[i]);
		i++;
	}
	box->len = i;
	box->alen = i;
	box->blen = 0;
}
