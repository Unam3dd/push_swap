/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:41:32 by stales            #+#    #+#             */
/*   Updated: 2022/04/27 17:35:58 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_swap(t_stack **s)
{
	t_stack	*first;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	*s = (*s)->next;
	first->prev = *s;
	first->next = (*s)->next;
	if (first->next)
		first->next->prev = first;
	(*s)->next = first;
	(*s)->prev = NULL;
}

void	algo_push(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (!*b)
		return ;
	if (!*a && *b)
	{
		*a = ft_stack_new((*b)->value);
		ft_stack_pop(b);
		return ;
	}
	ptr = ft_stack_new((*b)->value);
	ft_stack_push(a, ptr);
	ft_stack_pop(b);
}

void	algo_rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*end;

	if (!*s)
		return ;
	first = *s;
	end = ft_stack_get_last(first);
	*s = first->next;
	first->prev = end;
	first->next->prev = NULL;
	first->next = NULL;
	end->next = first;
}

void	algo_reverse_rotate(t_stack **s)
{
	t_stack	*end;
	t_stack	*first;

	if (!*s)
		return ;
	first = *s;
	end = ft_stack_get_last(first);
	end->next = first;
	end->next->prev = end;
	if (end->prev)
		end->prev->next = NULL; // MAY SEGFALT "3 1 5 6 2 8 7 9 4"
	*s = end;
}
