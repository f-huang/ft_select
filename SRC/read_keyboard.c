/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_keyboard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:01:51 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/26 14:06:28 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	arrow_up(t_env *e)
{
	char				*area;

	if (e->screen_row == -1)
		return ;
	area = NULL;
	e->cursor = e->cursor->prev;
	TPUTS(UP, 1);
}

static void	arrow_down(t_env *e)
{
	char				*area;

	if (e->screen_row == -1)
		return ;
	area = NULL;
	e->cursor = e->cursor->next;
	TPUTS(DOWN, 1);
}

static void	arrow_right(t_env *e)
{
	char				*area;

	if (e->screen_row == -1)
		return ;
	area = NULL;
	e->cursor = e->cursor->right;
	TPUTS(RIGHT, 1);
}

static void	arrow_left(t_env *e)
{
	char				*area;

	if (e->screen_row == -1)
		return ;
	area = NULL;
	e->cursor = e->cursor->left;
	TPUTS(LEFT, 1);
}

void		read_keyboard(t_env *e, char buffer[5], char *area)
{
	const t_pattern		pattern[] = {
		{{27, 0, 0, 0, 0}, exit_free},
		{{27, 91, 65, 0, 0}, arrow_up},
		{{27, 91, 66, 0, 0}, arrow_down},
		{{27, 91, 67, 0, 0}, arrow_right},
		{{27, 91, 68, 0, 0}, arrow_left},
		{{27, 91, 51, 126, 0}, erase_link},
		{{DEL, 0, 0, 0, 0}, erase_link},
		{{NL, 0, 0, 0, 0}, NULL},
		{{SP, 0, 0, 0, 0}, NULL},
	};
	int					i;

	i = -1;
	while (++i < 7)
		if (ft_strcmp(pattern[i].buffer, buffer) == 0)
			pattern[i].f(e);
	if (ft_strcmp(pattern[i++].buffer, buffer) == 0)
		e->cursor = NULL;
	else if (e->screen_row != -1 && ft_strcmp(pattern[i++].buffer, buffer) == 0)
	{
		e->cursor->selected = e->cursor->selected ? 0 : 1;
		e->cursor = e->cursor->next;
	}
}
