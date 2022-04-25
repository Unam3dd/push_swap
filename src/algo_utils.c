/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 14:41:32 by stales            #+#    #+#             */
/*   Updated: 2022/04/25 12:44:54 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b) Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
*/

void	algo_swap(t_stack **s)
{
    t_stack *tmp;

	if (!*s || !(*s)->next)
		return ;
	tmp = (*s)->next;
	(*s)->next = tmp->next;
	tmp->next = *s;
	*s = tmp;
}

void	algo_push(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (!*b)
		return ;
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
	end = ft_stack_get_last(*s);
	*s = first->next;
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
	end = ft_stack_get_last(*s);
	end->prev->next = NULL;
	end->prev = NULL;
	end->next = first;
	*s = end;
}
