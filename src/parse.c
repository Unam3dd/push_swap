/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stales <stales@student.42.angouleme.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:44:44 by stales            #+#    #+#             */
/*   Updated: 2022/04/21 20:24:16 by stales           ###   ########.fr       */
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
	t_stack	*a;
	t_stack	*s;
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

int ft_check_errors(t_pswap *p)
{
	t_stack	*tmp;

	tmp = p->a;
	while (tmp)
	{
		if (ft_stack_check_duplicate(p->a, tmp))
		{
			ft_stack_free(&p->a);
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}