/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:50:06 by stales            #+#    #+#             */
/*   Updated: 2022/04/28 19:57:59 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack		*ft_get_max(t_stack *s)
{
	t_stack	*max;
	int		value;
	
	if (!s)
		return (NULL);
	max = s;
	value = s->value;
	while (s)
	{
		if (s->next && s->value < s->next->value && value < s->next->value)
		{
			max = s->next;
			value = max->value;
		}
		s = s->next;
	}
	return (max);
}

int	ft_check_stack_order(t_stack *s)
{
	if (!s)
		return (1);
	while (s)
	{
		if (s->next && s->value > s->next->value)
			return (1);
		s = s->next;
	}
	return (0);
}

int ft_check_stack_reverse_order(t_stack *s)
{
    if (!s)
		return (1);
	while (s)
	{
		if (s->next && s->next->value > s->value)
			return (1);
		s = s->next;
	}
	return (0);
}
