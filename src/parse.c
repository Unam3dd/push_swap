/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:44:44 by stales            #+#    #+#             */
/*   Updated: 2022/04/21 13:21:25 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*ft_parse_tokenize(char *av)
{
	t_stack	*a;
	t_stack *s;
	char	*token;

	token = ft_strtok(av, " ");
	if (!token)
		return (NULL);
	a = ft_stack_new(ft_atoi(token));
	s = a;
	while (token)
	{
		token = ft_strtok(NULL, " ");
		if (!token)
			break ;
		a->next = ft_stack_new(ft_atoi(token));
		a = a->next;
	}
	return (s);
}

t_stack	*ft_parse_args(int ac, char **av)
{
	t_stack *a;
	t_stack *s;
	int		i;

	if (ac < 3)
		return (ft_parse_tokenize(av[1]));
	i = 1;
	a = ft_stack_new(ft_atoi(av[i++]));
	s = a;
	while (s && i < ac)
	{
		a->next = ft_stack_new(ft_atoi(av[i++]));
		a = a->next;
	}
    return (s);
}
