/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:30:27 by sam               #+#    #+#             */
/*   Updated: 2022/04/27 02:24:24 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*ft_get_min(t_stack *s)
{
	t_stack	*min;
	
	if (!s)
		return (NULL);
	min = s;
	while (s)
	{
		if (s->next && s->next->value < s->value)
			min = s->next;
		s = s->next;
	}
	return (min);
}

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

// TODO

void	ft_pswap(t_pswap *p)
{
	t_stack	*ta;
	t_stack	*min;
	size_t	i;

	if (!p)
		return ;
	i = p->s;
	min = ft_get_min(p->a);
	while (ft_check_order(p) && i > 3)
	{
		ta = p->a;
		if (min->value != ta->value)
			rra(p);
		if (min->value == ta->value)
		{
			pb(p);
			min = ft_get_min(ta);
			i--;
		}
	}
}