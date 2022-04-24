/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:32:35 by stales            #+#    #+#             */
/*   Updated: 2022/04/24 16:27:37 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>

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
t_stack	*ft_stack_get_last(t_stack *s);
void	ft_stack_free(t_stack **s);
void	ft_stack_push(t_stack **s, t_stack *new);
void	ft_stack_pop(t_stack **s);


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
//              ALGO SCHEME
//
//////////////////////////////////////////

void	algo_swap(t_stack **s);
void	algo_push(t_stack **a, t_stack **b);
void	algo_rotate(t_stack **s);
void	algo_reverse_rotate(t_stack **s);


///////////////////////////////////////////
//
//              COMMANDS
//
//////////////////////////////////////////

void	sa(t_pswap *p);
void	sb(t_pswap *p);
void	ss(t_pswap *p);
void	pa(t_pswap *p);
void	pb(t_pswap *p);
void	ra(t_pswap *p);
void	rb(t_pswap *p);
void	rr(t_pswap *p);
void	rra(t_pswap *p);
void	rrb(t_pswap *p);
void	rrr(t_pswap *p);


///////////////////////////////////////////
//
//              UTILS
//
//////////////////////////////////////////

int ft_check_charset(char *str, char *set);

#endif