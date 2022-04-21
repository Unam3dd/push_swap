/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:59:57 by stales            #+#    #+#             */
/*   Updated: 2022/04/21 14:50:11 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

t_stack	*ft_stack_new(int value)
{
	t_stack *ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->prev = NULL;
	ptr->next = NULL;
	ptr->value = value;
	return (ptr);
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

void	ft_stack_set(t_stack *s, int value)
{
	if (s)
		s->value = value;
}
