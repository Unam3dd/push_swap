/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:50:25 by stales            #+#    #+#             */
/*   Updated: 2022/05/06 17:27:08 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pswap	p;

	if (ac < 2)
		return (1);
	p.s = 0;
	p.op = 0;
	p.b = NULL;
	p.a = ft_parse_args(ac, av, &p);
	if (ft_check_errors(&p))
		return (1);
	if (p.s <= 5)
		ft_pswap_small(&p);
	else
	{
		ft_stack_index(p.a);
		if (p.s == 100)
			ft_pswap_100(&p);
		else
			ft_radix_sort(&p);
	}
	if (p.a)
		ft_stack_free(&p.a);
	if (p.b)
		ft_stack_free(&p.b);
	return (0);
}
