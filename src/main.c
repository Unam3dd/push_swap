/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:50:25 by stales            #+#    #+#             */
/*   Updated: 2022/04/21 14:50:39 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	t_stack	*a;

	if (ac < 2)
		return (1);
	a = ft_parse_args(ac, av);
	printf("%d\n%d\n%d\n", a->value, a->next->value, a->next->next->value);
	algo_sa(&a);
	printf("%d\n%d\n%d\n", a->value, a->next->value, a->next->next->value);
	if (a)
		ft_stack_free(&a);
	return (0);
}
