/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:00:05 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/22 15:41:37 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_env	*g_e;

static void	handle_ctrlz(int signum)
{
	const char	cp[2] = {g_e->term.c_cc[VSUSP], 0};

	if (signum == SIGTSTP)
	{
		reset_term(g_e);
		signal(SIGTSTP, SIG_DFL);
		signal(SIGCONT, signal_handler);
		ioctl(0, TIOCSTI, cp);
	}
	else if (signum == SIGCONT)
	{
		init_term(g_e);
		update_screen(g_e, NULL);
		signal(SIGTSTP, signal_handler);
	}
}

static void	signal_handler(int signum)
{
	if (signum == SIGWINCH)
		update_screen(g_e, NULL);
	else if (signum == SIGINT || signum == SIGQUIT)
	{
		reset_term(g_e);
		exit_free(g_e);
		exit(EXIT_SUCCESS);
	}
	else if (signum == SIGTSTP || signum == SIGCONT)
		handle_ctrlz(signum);
}

void		check_for_signals(void)
{
	signal(SIGWINCH, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
}
