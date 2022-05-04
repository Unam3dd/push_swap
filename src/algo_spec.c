/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:27:41 by sam               #+#    #+#             */
/*   Updated: 2022/05/05 00:47:17 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

int		ft_check_index(t_stack *s, int m, int median)
{
	while (s)
	{
		if (!m && s->index <= median)
			return (1);
		else if (m == 1 && s->index > median && s->index <= median * 2)
			return (1);
		else if (m == 2 && s->index > median*2 && s->index <= median * 3)
			return (1);
		else if (m == 3 && s->index > median*3 && s->index <= median * 4)
			return (1);
		s = s->next;
	}
	return (0);
}

void	ft_pswap_100(t_pswap *p)
{
	ft_pswap_median(p, 3);
	ft_pswap_sort_algo_b(p, 75, 99);
	ft_pswap_median(p, 2);
	ft_pswap_sort_algo_b(p, 50, 75);
	ft_pswap_median(p, 1);
	ft_pswap_sort_algo_b(p, 26, 49);
	ft_pswap_median(p, 0);
	ft_pswap_sort_algo_b(p, 0, 25);
}

void	ft_pswap_sort_algo_b(t_pswap *p, int i, int max)
{
	t_stack	*s;
	int		pos;

	while (p->b && max > i)
	{
		s = ft_get_by_index(p->b, max);
		pos = ft_stack_get_pos(p->b, s);
		if (p->b->index == max)
		{
			pa(p);
			max--;
		}
		else if (p->b->next && p->b->next->index == max)
			sb(p);
		else if (pos >= 11)
			rrb(p);
		else
			rb(p);
	}
}

void	ft_pswap_median(t_pswap *p, int m)
{
	while (ft_check_index(p->a, m, p->s / 4))
	{
		if (!m && p->a->index <= 25)
			pb(p);
		else if (m == 1 && p->a->index > 25 && p->a->index <= 50)
			pb(p);
		else if (m == 2 && p->a->index > 50 && p->a->index <= 75)
			pb(p);
		else if (m == 3 && p->a->index > 75 && p->a->index <= 100)
			pb(p);
		else
			ra(p);
	}
}
