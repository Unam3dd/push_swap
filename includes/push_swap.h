/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:32:35 by stales            #+#    #+#             */
/*   Updated: 2022/04/22 13:15:08 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

///////////////////////////////////////////
//
//              DEFINES
//
//////////////////////////////////////////

#define ACHAR "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

///////////////////////////////////////////
//
//              STACK
//
//////////////////////////////////////////

typedef struct s_stack
{
    struct s_stack	*next;
    struct s_stack	*prev;
    int				value;
} t_stack;

typedef struct s_pswap
{
	t_stack	*a;
	t_stack *b;
} t_pswap;

///////////////////////////////////////////
//
//         PUSH SWAP STACK
//
//////////////////////////////////////////

t_stack	*ft_stack_new(int value);
void	ft_stack_free(t_stack **s);
void	ft_stack_set(t_stack *s, int value);

///////////////////////////////////////////
//
//              PARSE
//
//////////////////////////////////////////

t_stack	*ft_parse_tokenize(char *av);
t_stack	*ft_parse_args(int ac, char **av);
int		ft_stack_check_duplicate(t_stack *a, t_stack *actual);
int     ft_check_errors(t_pswap *p);

///////////////////////////////////////////
//
//           SWAP ALGO
//
//////////////////////////////////////////

void	algo_swap(t_stack **s);
void	algo_push(t_stack **s, t_stack *new);


///////////////////////////////////////////
//
//              UTILS
//
//////////////////////////////////////////

int ft_check_charset(char *str, char *set);

#endif