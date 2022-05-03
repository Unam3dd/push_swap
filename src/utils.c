/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:15:24 by stales            #+#    #+#             */
/*   Updated: 2022/05/03 11:18:40 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	ft_stack_get_pos(t_stack *s, t_stack *pos)
{
	int	i;

	i = 1;
	while (s)
	{
		if (s == pos)
			return (i);
		s = s->next;
		i++;
	}
	return (-1);
}

void	ft_show_stack(t_stack *s, int i, char n)
{
	ft_printf("%c :\n", n);
	while (s)
	{
		ft_printf("%d : %d | %d\n", i, s->index, s->value);
		s = s->next;
	}
}

int	ft_check_charset(char *str, char *set)
{
	while (*str)
	{
		if (ft_strchr(set, *str))
			return (1);
		str++;
	}
	return (0);
}
