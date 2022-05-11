/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:21:35 by stales            #+#    #+#             */
/*   Updated: 2022/05/11 18:55:56 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int check_index(t_stack *s, int min, int max)
{
	while (s)
	{
		if (s->index >= min && s->index <= max)
			return (1);
		s = s->next;
	}
	return (0);
}

static int count_cycle(t_stack *s, int min, int max, int r)
{
	int count;

	count = 0;
	if (r)
		s = ft_stack_get_last(s);
	while (s)
	{
		if (s->index >= min && s->index <= max)
			break ;
		if (r)
			s = s->prev;
		else
			s = s->next;
	}
	return (count);
}

void	pswap_100_n(t_pswap *p)
{
	t_stack *smax;
	t_stack *end;
	int max;
	int min;
	int pos;

	min = 66;
	max = 99;
	pos = 0;
	while (ft_check_stack_order(p->a) || p->b)
	{
		while (check_index(p->a, min, max))
		{
			if (p->a->index >= min && p->a->index <= max)
				pb(p);
			else if (count_cycle(p->a, min, max, 1) < count_cycle(p->a, min, max, 0))
				rra(p);
			else
				ra(p);
		}
		while (check_index(p->b, min, max))
		{
			smax = ft_get_max(p->b);
			pos = ft_stack_get_pos(p->b, smax);
			end = ft_stack_get_last(p->a);
			if (p->b->index == smax->index && p->a->index != smax->index - 1)
			{
				pa(p);
				if (end && p->a->index == end->index + 1)
					rra(p);
				if (end && end->prev && p->a->index == end->prev->index + 1)
				{
					rra(p);
					rra(p);
					sa(p);
				}
			}
			else if (p->b->index == smax->index && p->a->index == smax->index - 1)
			{
				pa(p);
				sa(p);
				if (p->a->index == end->index + 1)
					rra(p);
				if (p->a->index == end->prev->index + 1)
				{
					rra(p);
					rra(p);
					sa(p);
				}
			}
			else if (p->b->index == smax->index - 1)
				pa(p);
			else if (p->b->index == smax->index - 2)
			{
				pa(p);
				ra(p);
			}
			else if (pos >= 11)
				rrb(p);
			else
				rb(p);
		}
		min -= 33;
		max -= 33;
	}
}
