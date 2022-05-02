/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:40:37 by stales            #+#    #+#             */
/*   Updated: 2022/05/02 14:07:51 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_stack_push(t_stack **s, t_stack *new)
{
	if (!new)
		return ;
	(*s)->prev = new;
	new->next = *s;
	*s = new;
}

void	ft_stack_pop(t_stack **s)
{
	t_stack	*next;

	if (!*s)
		return ;
	next = (*s)->next;
	if (next)
		next->prev = NULL;
	free(*s);
	*s = next;
}
