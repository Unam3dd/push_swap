/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:32:35 by stales            #+#    #+#             */
/*   Updated: 2022/04/21 13:26:26 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 0x20
#endif

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

#endif