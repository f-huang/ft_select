/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:04:18 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/22 16:57:28 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		padding(int n, int fd)
{
	char	*ret;

	if (!(ret = ft_strnew(n)))
		exit(EXIT_FAILURE);
	while (n > 0)
	{
		ret = ft_strcat(ret, " ");
		n--;
	}
	ft_putstr_fd(ret, fd);
	ft_strdel(&ret);
}

static void	print_list_name_if(t_env *e, t_elem *ptr)
{
	char	*area;

	area = NULL;
	if (ptr == e->cursor)
	{
		TPUTS(UL, 1);
	}
	if (ptr->selected == 1)
	{
		TPUTS(VR, 1);
		ft_putstr_fd(GRAY, e->fd);
	}
	ft_putstr_fd(ptr->name, e->fd);
	if (ptr == e->cursor || ptr->selected == 1)
	{
		TPUTS(STOP, 1);
		ft_putstr_fd(COLOR_RESET, e->fd);
	}
	padding(e->max_len - ft_strlen(ptr->name) + 1, e->fd);
}

static void	list_index(t_env *e, int index, void (f)(t_env *, t_elem *))
{
	t_elem	*ptr;
	int		i;

	i = 0;
	ptr = e->lst;
	while (ptr->next != e->lst)
	{
		if (index == i)
		{
			f(e, ptr);
			return ;
		}
		ptr = ptr->next;
		i++;
	}
	if (index == i)
		f(e, ptr);
}

void		print_list_on_screen(t_env *e, char *area)
{
	int		i;
	int		index;
	int		tmp_row;

	tmp_row = e->screen_row;
	i = 0;
	while (tmp_row)
	{
		index = i;
		if (e->screen_col > 1)
			padding((e->win.ws_col - ((e->max_len + 1) * e->screen_col)) / 2,\
				e->fd);
		while (index <= e->list_len - 1)
		{
			list_index(e, index, print_list_name_if);
			index += e->screen_row;
		}
		tmp_row--;
		i++;
		ft_putchar_fd('\n', e->fd);
	}
}
