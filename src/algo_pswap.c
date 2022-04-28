/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:30:27 by sam               #+#    #+#             */
/*   Updated: 2022/04/28 23:43:32 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <unistd.h>

void	ft_pswap(t_pswap *p)
{
	t_stack	*ta;
	t_stack *tb;
	t_stack	*min;
	t_stack *max;
	int		i;

	if (!p)
		return ;
	ta = p->a;
	tb = p->b;
	i = p->s;
	min = ft_get_min(p->a);
	max = ft_get_max(p->a);
	while (ft_check_stack_order(p->a) && i > 3)
	{
		if (i == p->s && ta->value != max->value) {
			pb(p);
			ta = p->a;
			tb = p->b;
			i--;
		}
		if (ta->value == max->value || ta->value > ta->next->value)
		{
			ra(p);
			ta = p->a;
		}
		if (ta->value < ta->next->value)
		{
			pb(p);
			ta = p->a;
			tb = p->b;
			while (ta->next && ta->value < ta->next->value && i > 3)
			{
				pb(p);
				ta = p->a;
				tb = p->b;
				i--;
			}
			while (ft_check_stack_reverse_order(p->b) && p->b)
			{
				if (tb->value < tb->next->value)
				{
					sb(p);
					tb = p->b;
				} else
				{
					rrb(p);
					tb = p->b;
				}
			}
			ta = p->a;
			tb = p->b;
			i--;
		}
	}
	ft_last_algorithm(p);
	while (i < p->s)
	{
		pa(p);
		i++;
	}
}

void	ft_last_algorithm(t_pswap *p)
{
	if ((p->a->value > p->a->next->value) 
		&& (p->a->value < p->a->next->next->value) 
		&& (p->a->next->value < p->a->next->next->value))
		sa(p);
	if (p->a->next && p->a->next->next 
		&& (p->a->value > p->a->next->value) 
		&& (p->a->value > p->a->next->next->value) 
		&& (p->a->next->value > p->a->next->next->value))
	{
		sa(p);
		rra(p);
	}
	if (p->a->next && p->a->next->next 
		&& (p->a->value > p->a->next->next->value) 
		&& (p->a->next->next->value > p->a->next->value))
		ra(p);
	if (p->a->next && p->a->next->next 
		&& (p->a->value < p->a->next->value) 
		&& (p->a->value < p->a->next->next->value) 
		&& (p->a->next->value > p->a->next->next->value))
	{
		sa(p);
		ra(p);
	}
	if (p->a->next && p->a->next->next 
		&& (p->a->value < p->a->next->value) 
		&& (p->a->next->value > p->a->next->next->value) 
		&& (p->a->next->next->value < p->a->value))
		rra(p);
}