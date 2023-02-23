/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario42 <usuario42@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:35:51 by usuario42         #+#    #+#             */
/*   Updated: 2023/02/23 19:14:04 by usuario42        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(void)
{
	write (1, "Error\n", 6);
}

int ft_checknumber(int ac, char **av)
{
	int	c;
	int i;

	i = 1;
	while (ac > 1)
	{
		c = 0;
		if (av[i][c] == '-')
			c++;
		while (av[i][c] != '\0')
		{
			if (!ft_isdigit(av[i][c]))
			{
				return(0);
			}	
			c++;	
		}
		i++;
		ac--;
	}
	return (1);
}
int	ft_checkinput(int ac, char **av)
{
	if (!ft_checknumber(ac, av))
		return(0);
	
	return(1);
}

static int	ft_countwords(const char *str, char c)
{
	int	nword;
	int	flag;
	int	count;

	nword = 0;
	flag = -1;
	count = 0;
	while (str[count])
	{
		if (str[count] != c && flag < 0)
		{
			flag = 0;
			nword++;
		}
		else if (str[count] == c)
			flag = -1;
		count++;
	}
	return (nword);
}


int	main(int ac, char **av)
{

	if (ac < 2)
		return(write_error(),0);
	if (ac == 2)
	{
		ac = ft_countwords(av[1], ' ');
		av = ft_split(av[1], ' ');
	}
	if (!ft_checkinput(ac, av))
	{
		printf("%d\n",ft_checkinput(ac, av));
		write_error();
	}	
	return (0);
		
}