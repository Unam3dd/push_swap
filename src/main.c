/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:50:25 by stales            #+#    #+#             */
/*   Updated: 2022/04/21 16:08:05 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include "libft.h"
#include <string.h>

int main(int ac, char **av)
{
	//t_pswap p;

	if (ac < 2)
		return (1);
	printf("%lu\n", ft_strspn(av[1], " "));
	
	/*p.a = ft_parse_args(ac, av);
	printf("%d\n", p.a->next->next->value);
	if (p.a)
		ft_stack_free(&p.a);
	*/
	return (0);
}
