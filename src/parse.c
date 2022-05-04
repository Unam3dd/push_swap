/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:44:44 by stales            #+#    #+#             */
/*   Updated: 2022/05/04 14:32:15 by stales           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <limits.h>

t_stack	*ft_parse_tokenize(char *av, t_pswap *ps)
{
	t_stack	*a;
	t_stack	*s;
	t_stack	*p;
	char	*token;

	token = ft_strtok(av, " ");
	if (!token || ft_check_charset(token) || ft_atoi(token) > INT_MAX)
		return (NULL);
	a = ft_stack_new(ft_atoi(token), 0);
	s = a;
	p = a;
	while (token)
	{
		ps->s++;
		token = ft_strtok(NULL, " ");
		if (!token)
			break ;
		if (ft_check_charset(token) || ft_atoi(token) > INT_MAX)
			return (NULL);
		a->next = ft_stack_new(ft_atoi(token), 0);
		a->next->prev = p;
		a = a->next;
		p = a;
	}
	return (s);
}

t_stack	*ft_parse_args(int ac, char **av, t_pswap *ps)
{
	t_stack	*a;
	t_stack	*s;
	t_stack	*p;
	int		i;

	if (ac < 3)
		return (ft_parse_tokenize(av[1], ps));
	if (ft_check_charset(av[1]) || ft_atoi(av[1]) > INT_MAX)
		return (NULL);
	i = 1;
	a = ft_stack_new(ft_atoi(av[i++]), 0);
	s = a;
	p = a;
	while (s && i < ac)
	{
		if (ft_check_charset(av[i]) || ft_atoi(av[i]) > INT_MAX)
			return (NULL);
		a->next = ft_stack_new(ft_atoi(av[i++]), 0);
		a->next->prev = p;
		a = a->next;
		p = a;
	}
	ps->s = i - 1;
	return (s);
}

int	ft_stack_check_duplicate(t_stack *a, t_stack *actual)
{
	t_stack	*tmp;

	if (!actual)
		return (0);
	tmp = a;
	while (tmp)
	{
		if (tmp != actual && (tmp->value == actual->value))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_check_errors(t_pswap *p)
{
	t_stack	*tmp;

	if (!p->a)
		return (ft_putstr("Error\n", 0));
	tmp = p->a;
	while (tmp)
	{
		if (ft_stack_check_duplicate(p->a, tmp))
		{
			ft_stack_free(&p->a);
			return (ft_putstr("Error\n", 0));
		}
		tmp = tmp->next;
	}
	return (0);
}
