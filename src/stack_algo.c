/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 12:40:37 by stales            #+#    #+#             */
/*   Updated: 2022/04/27 02:24:04 by sam              ###   ########.fr       */
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
