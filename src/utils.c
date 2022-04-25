/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:15:24 by stales            #+#    #+#             */
/*   Updated: 2022/04/25 12:50:02 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void ft_show_stack(t_stack *s, int i, char n)
{
	ft_printf("%c :\n", n);
	while (s) {
		ft_printf("%d : %d\n", i, s->value);
		s = s->next;
	}
}

int ft_check_charset(char *str, char *set)
{
    while (*str)
    {
        if (ft_strchr(set, *str))
            return (1);
        str++;
    }
    return (0);
}
