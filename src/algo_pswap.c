/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_pswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:30:27 by sam               #+#    #+#             */
/*   Updated: 2022/05/03 15:03:30 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_pswap_small(t_pswap *p)
{
	t_stack	*min;
	int		i[2];

	if (!p)
		return ;
	i[0] = p->s;
	min = ft_get_min(p->a);
	i[1] = ft_stack_get_pos(p->a, min);
	while (ft_check_stack_order(p->a) && i[0] > 3)
	{
		if (min->value == p->a->value)
		{
			pb(p);
			min = ft_get_min(p->a);
			i[0]--;
		}
		i[1] = ft_stack_get_pos(p->a, min);
		if (min->value != p->a->value && i[1] > p->s / 2)
			rra(p);
		else if (min->value != p->a->value)
			ra(p);
	}
	ft_last_algo_ext1(p);
	while (i[0]++ < p->s)
		pa(p);
}

void	ft_last_algo_ext1(t_pswap *p)
{
	if (p->a->next && p->a->next->next && (p->a->value > p->a->next->value)
		&& (p->a->value < p->a->next->next->value)
		&& (p->a->next->value < p->a->next->next->value))
		sa(p);
	if (p->a->next && p->a->next->next && (p->a->value > p->a->next->value)
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
	if (p->a->next && p->a->next->next && (p->a->value < p->a->next->value)
		&& (p->a->value < p->a->next->next->value)
		&& (p->a->next->value > p->a->next->next->value))
	{
		sa(p);
		ra(p);
	}
	ft_last_algo_ext2(p);
}

void	ft_last_algo_ext2(t_pswap *p)
{
	if (p->a->next && p->a->next->next
		&& (p->a->value < p->a->next->value)
		&& (p->a->next->value > p->a->next->next->value)
		&& (p->a->next->next->value < p->a->value))
		rra(p);
	if (p->s == 2 && (p->a->value > p->a->next->value))
		sa(p);
}

void	ft_radix_sort(t_pswap *p)
{
	t_stack	*tmp;
	int		i[3];

	ft_bzero(i, 3);
	tmp = ft_get_max(p->a);
	if (tmp)
		i[2] = tmp->index;
	while (ft_check_stack_order(p->a))
	{
		i[1] = 0;
		while (i[1] <= i[2])
		{
			if (!(p->a->index >> i[0] & 0x1))
				pb(p);
			else
				ra(p);
			i[1]++;
		}
		while (p->b)
			pa(p);
		i[0]++;
	}
}
