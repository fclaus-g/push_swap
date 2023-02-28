/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:27:55 by usuario42         #+#    #+#             */
/*   Updated: 2023/02/28 10:20:33 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

//definimos una estructura donde alojaremos los int 
typedef	struct s_box
{
	char **arg;
	int	*stack_a;
	int	*stack_b;
	int	len;
	int	alen;
	int	blen;

}t_box;

typedef struct s_pila
{
	int	content;
	int	indice;
	int	posicion;
	int	target;
	int	cost_a;
	int cost_b;
	
}t_pila;
char	*ft_strcpy(char *dst, const char *src);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int ft_checknumber(t_box *box);
void	write_error(void);
void	arg_to_array(t_box *box);
# endif