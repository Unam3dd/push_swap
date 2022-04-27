/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:30:27 by sam               #+#    #+#             */
/*   Updated: 2022/04/27 19:47:04 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

t_stack		*ft_get_min(t_stack *s)
{
	t_stack	*min;
	int		value;
	
	if (!s)
		return (NULL);
	min = s;
	value = s->value;
	while (s)
	{
		if (s->next && s->value > s->next->value && value > s->next->value)
		{
			min = s->next;
			value = min->value;
		}
		s = s->next;
	}
	return (min);
}

// return non zero value is not correct order

int		ft_check_order(t_pswap *p)
{
	t_stack	*t;

	if (!p || !p->a)
		return (1);
	t = p->a;
	while (t)
	{
		if (t->next && t->value > t->next->value)
			return (1);
		t = t->next;
	}
	return (0);
}

void	ft_pswap(t_pswap *p)
{
	t_stack	*ta;
	t_stack	*min;
	int		pos;
	int		i;

	if (!p)
		return ;
	ta = p->a;
	i = p->s;
	min = ft_get_min(p->a);
	pos = ft_stack_get_pos(p->a, min);
	while (ft_check_order(p) && i > 3)
	{
		if (min->value == ta->value)
		{
			pb(p);
			min = ft_get_min(p->a);
			pos = ft_stack_get_pos(p->a, min);
			ta = p->a;
			i--;
		}
		if (ta->next && min->value == ta->next->value)
		{
			sa(p);
			ta = p->a;
		}
		if ((min->value != ta->value) && (ta->next && min->value != ta->next->value)) {
			if (pos > (p->s / 2))
				rra(p);
			else
				ra(p);
			ta = p->a;
		}
	}


	if ((ta->value > ta->next->value) && (ta->value < ta->next->next->value) && (ta->next->value < ta->next->next->value))
		sa(p);
	if (ta->next && ta->next->next && (ta->value > ta->next->value) && (ta->value > ta->next->next->value) && (ta->next->value > ta->next->next->value))
	{
		sa(p);
		rra(p);
	}
	if (ta->next && ta->next->next && (ta->value > ta->next->next->value) && (ta->next->next->value > ta->next->value))
		ra(p);
	if (ta->next && ta->next->next && (ta->value < ta->next->value) && (ta->value < ta->next->next->value) && (ta->next->value > ta->next->next->value))
	{
		sa(p);
		ra(p);
	}
	if (ta->next && ta->next->next && (ta->value < ta->next->value) && (ta->next->value > ta->next->next->value) && (ta->next->next->value < ta->value))
		rra(p);
	while (i < p->s)
	{
		pa(p);
		i++;
	}
	ft_show_stack(p->a, 0, 'A');
}
