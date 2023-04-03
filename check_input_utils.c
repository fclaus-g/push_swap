/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:34:39 by fclaus-g          #+#    #+#             */
/*   Updated: 2023/04/03 12:38:58 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

void	write_error(void)
{
	ft_putstr_fd("Error", 2);
}

void	check_limits(long result, t_box *box)
{
	if (result > INT_MAX || result < INT_MIN)
	{
		write_error();
		free_stacks(box);
		exit(-1);
	}
}

void	free_stacks(t_box *box)
{
	free (box->stack_a);
	free (box->stack_b);
	return ;
}
