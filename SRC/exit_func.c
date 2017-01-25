/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:39:04 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/22 16:41:03 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern int	g_fd;

void		exit_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

static int	count_selected(t_elem *lst)
{
	int		n;
	t_elem	*ptr;

	n = 0;
	ptr = lst;
	while (ptr->next != lst)
	{
		if (ptr->selected == 1)
			n++;
		ptr = ptr->next;
	}
	if (ptr->selected == 1)
		n++;
	return (n);
}

void		exit_result(t_elem *lst)
{
	t_elem	*ptr;
	int		selected;

	if (lst == NULL || (selected = count_selected(lst)) == 0)
		return ;
	ptr = lst;
	while (selected && ptr->next != lst)
	{
		if (ptr->selected == 1)
		{
			selected--;
			ft_putstr_fd(ptr->name, 1);
			selected ? ft_putchar_fd(' ', 1) : 0;
		}
		ptr = ptr->next;
	}
	if (ptr->selected == 1)
		ft_putstr_fd(ptr->name, 1);
	ft_putchar_fd('\n', 1);
}

void		exit_free(t_env *e)
{
	t_elem	*ptr;
	t_elem	*tmp;

	if (e->lst == NULL)
		return ;
	ptr = e->lst;
	while (ptr->next != e->lst)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp->name);
		free(tmp);
		tmp = NULL;
	}
	tmp = ptr;
	ptr = ptr->next;
	free(tmp->name);
	free(tmp);
	tmp = NULL;
	e->list_len = 0;
}
