/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:59:57 by stales            #+#    #+#             */
/*   Updated: 2022/05/04 14:41:27 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_stack	*ft_stack_new(int value, int index)
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->prev = NULL;
	ptr->next = NULL;
	ptr->index = index;
	ptr->value = value;
	return (ptr);
}

t_stack	*ft_stack_get_last(t_stack *s)
{
	while (s->next)
		s = s->next;
	return (s);
}

t_stack	*ft_get_stack_value(t_stack *s, int value)
{
	while (s)
	{
		if (s->value == value)
			return (s);
		s = s->next;
	}
	return (s);
}

void	ft_stack_index(t_stack *s)
{
	t_stack	*tmp;
	int		index;
	int		counter;
	int		i;

	index = 0;
	i = ft_get_min(s)->value;
	counter = ft_get_max(s)->value;
	tmp = NULL;
	while (i <= counter)
	{
		tmp = ft_get_stack_value(s, i);
		if (tmp)
			tmp->index = index++;
		i++;
	}
}

void	ft_stack_free(t_stack **s)
{
	t_stack	*next;
	t_stack	*tmp;

	tmp = *s;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	if (*s)
		*s = NULL;
}
