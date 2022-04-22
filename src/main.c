/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:50:25 by stales            #+#    #+#             */
/*   Updated: 2022/04/22 12:28:29 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
	t_pswap p;
	
	if (ac < 2)
		return (1);
	p.a = ft_parse_args(ac, av);
	if (ft_check_errors(&p))
		return (1);
	if (p.a)
		ft_stack_free(&p.a);
	return (0);
}
