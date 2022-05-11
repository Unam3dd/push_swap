/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 21:27:41 by sam               #+#    #+#             */
/*   Updated: 2022/05/11 17:26:50 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int		psw_search_block_index(t_stack *s, int min, int max, int r, int index)
{
	int count;

	count = 0;
	if (r)
		s = ft_stack_get_last(s);
	while (s)
	{
		if (index == s->index && s->index >= min && s->index <= max)
			break ;
		if (r)
			s = s->prev;
		else
			s = s->next;
		count++;
	}
	return (count);
}

static int		psw_search_set(t_stack *s, int min, int max, int r)
{
	int count;

	count = 0;
	if (r)
		s = ft_stack_get_last(s);
	while (s)
	{
		if (s->index >= min && s->index < max)
			break ;
		if (r)
			s = s->prev;
		else
			s = s->next;
		count++;
	}
	return (count);
}

int	ft_check_index(t_stack *s, int m, int median)
{
	while (s)
	{
		if (!m && s->index <= median)
			return (1);
		else if (m == 1 && s->index > median && s->index <= median * 2)
			return (1);
		else if (m == 2 && s->index > median * 2 && s->index <= median * 3)
			return (1);
		else if (m == 3 && s->index > median * 3 && s->index <= median * 4)
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
	ft_pswap_sort_algo_b(p, 25, 50);
	ft_pswap_median(p, 0);
	ft_pswap_sort_algo_b(p, 0, 25);
}

void	ft_pswap_sort_algo_b(t_pswap *p, int i, int max)
{
	t_stack	*s;
	int		pos;

	while (p->b && max >= i)
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
		else if (pos >= 10)
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
