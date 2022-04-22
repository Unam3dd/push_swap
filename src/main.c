/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:50:25 by stales            #+#    #+#             */
/*   Updated: 2022/04/22 17:23:06 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void show_stack(t_stack *s, int i, char n)
{
	printf("%c :\n", n);
	while (s) {
		printf("%d : %d\n", i, s->value);
		s = s->next;
	}
}

int main(int ac, char **av)
{
	t_pswap p;
	
	if (ac < 2)
		return (1);
	p.a = ft_parse_args(ac, av);
	if (ft_check_errors(&p))
		return (1);
	p.b = ft_stack_new(5);
	t_stack *test = ft_stack_new(10);
	ft_stack_push(&p.b, test);
	show_stack(p.a, 0, 'A');
	ft_putchar(10);
	show_stack(p.b, 0, 'B');
	ft_putchar(10);
	pb(&p);
	show_stack(p.a, 1, 'A');
	ft_putchar(10);
	show_stack(p.b, 1, 'B');
	ft_putchar(10);
	pa(&p);
	show_stack(p.a, 1, 'A');
	ft_putchar(10);
	show_stack(p.b, 1, 'B');
	ft_putchar(10);
	pa(&p);
	pa(&p);
	pa(&p);
	pa(&p);
	pa(&p);
	pa(&p);
	pa(&p);
	pa(&p);
	pa(&p);
	show_stack(p.a, 1, 'A');
	ft_putchar(10);
	show_stack(p.b, 1, 'B');
	ft_putchar(10);
	if (p.a)
		ft_stack_free(&p.a);
	if (p.b)
		ft_stack_free(&p.b);
	return (0);
}
