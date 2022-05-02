/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:30:27 by sam               #+#    #+#             */
/*   Updated: 2022/05/02 15:18:28 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ft_pswap_small(t_pswap *p)
{
	t_stack	*min;
	t_stack *max;
	int		i;
	int		pos;

	if (!p || p->s > 6)
		return ;
	i = p->s;
	min = ft_get_min(p->a);
	pos = ft_stack_get_pos(p->a, min);
	max = ft_get_max(p->a);
	while (ft_check_stack_order(p->a) && i > 3)
	{
		if (min->value == p->a->value) {
			pb(p);
			min = ft_get_min(p->a);
			pos = ft_stack_get_pos(p->a, min);
			i--;
		}
		if (p->a->next 
			&& p->a->next->next 
			&& p->a->next->value < p->a->next->next->value 
			&& p->a->value > p->a->next->value)
			sa(p);
		if (min->value != p->a->value && pos > p->s / 2)
		{
			rra(p);
			pos = ft_stack_get_pos(p->a, min);
		} else if (min->value != p->a->value) {
			ra(p);
			pos = ft_stack_get_pos(p->a, min);
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
	if (p->a->next && p->a->next->next 
		&& (p->a->value > p->a->next->value) 
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