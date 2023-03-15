/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:08:38 by fernandocla       #+#    #+#             */
/*   Updated: 2023/03/15 11:11:23 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	save_args(t_box *box, int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
		box->arg = ft_split(av[1], ' ');
	else
	{
		box->arg = malloc(sizeof(char *) * ac);
		if (!box->arg)
			return (0);
		while (av[i + 1] != NULL)
		{
			box->arg[i] = ft_strcpy(box->arg[i], av[i + 1]);
			i++;
		}
		box->arg[i] = NULL;
	}
	return (1);
}

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	copier;

	copier = 0;
	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[copier] != '\0')
	{
		dst[copier] = src[copier];
		copier++;
	}
	dst[copier] = '\0';
	return (dst);
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
//Luego creamos una funcion que copie las palabras en las strings

static char	*ft_copyword(const char *str, int start, int finish)
{
	char	*word;
	int		count;

	count = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
	{
		word[count] = str[start];
		count++;
		start++;
	}
	word[count] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	c1;
	size_t	c2;
	int		flag;
	char	**split;

	split = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (split == 0)
		return (0);
	c1 = 0;
	c2 = 0;
	flag = -1;
	while (c1 <= ft_strlen(s))
	{
		if (s[c1] != c && flag < 0)
			flag = c1;
		else if ((s[c1] == c || c1 == ft_strlen(s)) && flag >= 0)
		{
			split[c2] = ft_copyword(s, flag, c1);
			c2++;
			flag = -1;
		}
		c1++;
	}
	split[c2] = 0;
	return (split);
}
