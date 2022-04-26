/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:50:25 by stales            #+#    #+#             */
/*   Updated: 2022/04/26 13:39:07 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	t_pswap p;

	if (ac < 2)
		return (1);
	p.b = NULL;
	p.a = ft_parse_args(ac, av);
	if (ft_check_errors(&p))
		return (1);
	ft_show_stack(p.a, 0, 'A');
	sa(&p);
	ft_show_stack(p.a, 0, 'A');
	rra(&p);
	ft_show_stack(p.a, 0, 'A');
	if (p.a)
		ft_stack_free(&p.a);
	if (p.b)
		ft_stack_free(&p.b);
	return (0);
}
