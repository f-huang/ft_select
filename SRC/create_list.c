/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 12:05:50 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/22 14:16:49 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	new_elem(t_elem **lst, char *name)
{
	t_elem	*new;

	if ((new = (t_elem*)ft_memalloc(sizeof(t_elem))) == NULL)
		exit(EXIT_FAILURE);
	if ((new->name = ft_strdup(name)) == NULL)
		exit(EXIT_FAILURE);
	new->selected = 0;
	if (*lst == NULL)
	{
		*lst = new;
		(*lst)->next = new;
		(*lst)->prev = new;
	}
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		new->prev->next = new;
		(*lst)->prev = new;
		*lst = new;
	}
}

void		create_list(t_env *e, char **av, int ac)
{
	int		av_len;

	e->lst = NULL;
	e->max_len = 0;
	while (--ac > 0)
	{
		av_len = 0;
		if ((av_len = ft_strlen(av[ac])) > e->max_len)
			e->max_len = av_len;
		if (av_len == 0)
			continue ;
		new_elem(&e->lst, av[ac]);
	}
}
