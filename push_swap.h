/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:27:55 by usuario42         #+#    #+#             */
/*   Updated: 2023/03/06 12:24:55 by fclaus-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
# include <limits.h>

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

size_t	ft_mtrlen(char **matriz);
void	printa(int *array, int len);
//check_input_utils.c count-words y copywords
char	**ft_split(char const *s, char c);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);

//check_input.c
void	write_error(void);
int ft_checknumber(t_box *box);
int check_repeat(t_box *box);
int	*simplifier(t_box *box);
char	*ft_strcpy(char *dst, const char *src);

//arg_to_array.c
long int	ft_longatoi(const char *str);
void	arg_to_array(t_box *box);
int	*ft_arraycpy(int *dst, int *array, int len);

//save_args.c
int save_args(t_box *box, int ac, char **av);
//OPERACIONES

//push.c
void	push_a(t_box *box);
void	push_b(t_box *box);

//swap.c
void	swap_a(t_box *box);
void	swap_b(t_box *box);
void	swap_ab(t_box *box);

//rotate.c
void	rotate_a(t_box *box);
void	rotate_b(t_box *box);
void	rotate_ab(t_box *box);

//reverse.c

# endif