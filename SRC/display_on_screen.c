/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_on_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 10:25:09 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/22 15:46:14 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_env	*g_e;

static void	window_screen_size(t_env *e, int ascii_art)
{
	int			rest;
	int			prev;

	rest = 0;
	if (e->screen_row >= 2 && e->win.ws_col > 70)
		ascii_art = 1;
	if (e->screen_row == -1)
	{
		e->screen_col = 1;
		e->screen_row = e->list_len;
	}
	while (e->screen_row + (ascii_art ? 10 : 1) >= e->win.ws_row)
	{
		rest = e->screen_row;
		e->screen_row /= 2;
		if (e->screen_row == 0)
			break ;
		e->screen_col *= 2;
		if ((rest %= 2))
			e->screen_row++;
	}
	if (((e->max_len + 1) * (e->screen_col)) > e->win.ws_col ||\
		e->screen_row + (ascii_art ? 10 : 0) > e->win.ws_row)
		e->screen_row = -1;
	update_left_right(e);
}

static void	ascii_ft_select(t_env *e, int ascii_art)
{
	const char	*art[] = {
		" _______ _______     _______ _______ ___    _______ _______ ________",
		"|       |       |   |       |       |   |   |      |       |       |",
		"|    ___|_     _|   |  _____|    ___|   |   |   ___|       |_     _|",
		"|   |___  |   |     | |_____|   |___|   |   |  |___|       | |   |",
		"|    ___| |   |     |_____  |    ___|   |___|   ___|      _| |   |",
		"|   |     |   |_____ _____| |   |___|       |  |___|     |_  |   |",
		"|___|     |___|_____|_______|_______|_______|______|_______| |___|\n",
		NULL
	};
	int			pad;
	int			i;

	if (e->screen_row != -1 && e->win.ws_col > 70 &&\
		e->screen_row + 9 < e->win.ws_row && (i = -1))
	{
		pad = (e->win.ws_col - 70) / 2;
		while (art[++i] && (ascii_art = 1))
		{
			padding(pad, e->fd);
			ft_printf_fd(e->fd, "^GREEN^%s^EOC^%s\n",\
				art[i], (art[i + 1] ? "" : "\n"));
		}
	}
	e->screen_row == -1 ? window_screen_size(e, ascii_art) : 0;
}

void		update_screen(t_env *e, char *area)
{
	int			ascii_art;

	ascii_art = 0;
	TPUTS(CLEAR, 0);
	ioctl(0, TIOCGWINSZ, &e->win);
	e->screen_col = 1;
	e->screen_row = e->list_len;
	window_screen_size(e, ascii_art);
	ascii_ft_select(e, ascii_art);
	if (e->lst && e->screen_row > 0)
		print_list_on_screen(e, area);
	else if (e->screen_row == -1)
		ft_putendl_fd("/!\\SCREEN SIZE TOO SMALL\n", e->fd);
	TPUTS(CURINV, 0);
}

int			display_on_screen(t_env *e)
{
	char		buffer[5];

	e->cursor = e->lst;
	update_screen(e, NULL);
	while (1)
	{
		g_e = e;
		check_for_signals();
		ft_bzero(buffer, 5);
		if (e->list_len == 0 || e->cursor == NULL)
		{
			e->list_len == 0 ? e->lst = NULL : 0;
			break ;
		}
		update_screen(e, NULL);
		if (read(0, buffer, 5) == -1)
			return (-1);
		read_keyboard(e, buffer, NULL);
	}
	reset_term(e);
	return (0);
}
