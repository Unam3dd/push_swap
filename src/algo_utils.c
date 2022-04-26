/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:41:32 by stales            #+#    #+#             */
/*   Updated: 2022/04/26 13:39:41 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b) Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
*/

// 3 2 1

void	algo_swap(t_stack **s)
{
	t_stack *first;

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
	t_stack *end;
	t_stack	*first;

	if (!*s)
		return ;
	first = *s;
	end = ft_stack_get_last(first);
	end->next = first;
	end->prev->next = NULL;
	*s = end;
}
