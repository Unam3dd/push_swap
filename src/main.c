/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:50:25 by stales            #+#    #+#             */
/*   Updated: 2022/05/02 15:12:41 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_pswap	p;
	t_stack *ptr;

	if (ac < 2)
		return (1);
	p.s = 0;
	p.op = 0;
	p.b = NULL;
	p.a = ft_parse_args(ac, av, &p);
	
	if (ft_check_errors(&p))
		return (1);
	
	// ALGO MAIN
	ft_stack_index(p.a);
	ptr = p.a;
	while (ptr)
	{
		printf("%d | %d\n", ptr->index, ptr->value);
		ptr = ptr->next;
	}

	ft_pswap_small(&p);

	ft_show_stack(p.a, 0, 'A');
	if (p.a)
		ft_stack_free(&p.a);
	if (p.b)
		ft_stack_free(&p.b);
	return (0);
}
