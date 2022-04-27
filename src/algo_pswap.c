/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:30:27 by sam               #+#    #+#             */
/*   Updated: 2022/04/27 13:17:01 by stales           ###   ########.fr       */
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
	size_t	i;

	if (!p)
		return ;
	ta = p->a;
	i = p->s;
	min = ft_get_min(p->a);
	while (ft_check_order(p) && i > 3)
	{
		if (min->value == ta->value)
		{
			pb(p);
			min = ft_get_min(p->a);
			ta = p->a;
			i--;
		}
		if (ta->next && min->value == ta->next->value)
		{
			sa(p);
			ta = p->a;
		}
		if ((min->value != ta->value) && (ta->next && min->value != ta->next->value)) {
			rra(p);
			ta = p->a;
		}
		sleep(1);
	}
	printf("\n");
	ft_show_stack(p->a, 0, 'A');
	printf("\n");
	ft_show_stack(p->b, 1, 'B');
	while (i < p->s)
	{
		pa(p);
		i++;
	}
	printf("\n");
	ft_show_stack(p->a, 0, 'A');
	printf("\n");
	ft_show_stack(p->b, 1, 'B');
}
