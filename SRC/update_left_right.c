/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_left_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 14:22:55 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/22 15:42:49 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	get_diff(t_env *e)
{
	int		tmp;
	int		diff;

	diff = 0;
	if (e->list_len % e->screen_col != 0)
	{
		tmp = e->screen_row * e->screen_col;
		while (tmp != e->list_len)
		{
			diff++;
			tmp--;
		}
	}
	return (diff);
}

static void	link_left_right(t_env *e, t_elem **ptr, t_elem **right, int index)
{
	while (index > 0)
	{
		*right = (*right)->next;
		index--;
	}
	(*ptr)->right = *right;
	(*right)->left = *ptr;
}

void		update_left_right(t_env *e)
{
	t_elem	*ptr;
	t_elem	*right;
	int		i;
	int		diff;

	if (e->screen_row == -1 || e->screen_col == -1)
		return ;
	diff = get_diff(e);
	i = 1;
	ptr = e->lst;
	while (ptr->next != e->lst)
	{
		right = ptr;
		link_left_right(e, &ptr, &right, e->screen_row -\
			(diff && i > e->list_len - e->screen_row + diff ? diff : 0) +\
			(diff && i > e->list_len - e->screen_row && i <= \
			e->screen_row * (e->screen_col - 1) ? e->screen_row - diff : 0));
		i++;
		ptr = ptr->next;
	}
	right = ptr;
	link_left_right(e, &ptr, &right, e->screen_row -\
		(diff && i > e->list_len - e->screen_row + diff ? diff : 0) +\
		(diff && i > e->list_len - e->screen_row && i <= \
			e->screen_row * (e->screen_col - 1) ? e->screen_row - diff : 0));
}
