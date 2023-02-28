/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:50:22 by usuario42         #+#    #+#             */
/*   Updated: 2023/02/28 10:15:44 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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