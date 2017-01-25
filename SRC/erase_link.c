/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:33:48 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/26 14:09:00 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	free_link(t_env *e, t_elem *ptr)
{
	if (ptr->prev)
		ptr->prev->next = e->cursor->next;
	if (ptr->next)
		ptr->next->prev = ptr->prev;
	if (e->cursor->next != e->lst)
		e->cursor = e->cursor->next;
	else
		e->cursor = e->cursor->prev;
	if (ptr == e->lst)
		e->lst = ptr->next;
	free(ptr->name);
	ptr->name = NULL;
	free(ptr);
	ptr = NULL;
}

void		erase_link(t_env *e)
{
	t_elem	*ptr;

	e->list_len--;
	ptr = e->lst;
	while (ptr->next != e->lst)
	{
		if (ptr == e->cursor)
		{
			free_link(e, ptr);
			break ;
		}
		ptr = ptr->next;
	}
	if (ptr == e->cursor)
		free_link(e, ptr);
}
