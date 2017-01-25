/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 18:11:26 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/22 16:43:14 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			ft_putc(int c)
{
	extern	int g_fd;

	if (write(g_fd, &c, 1) == -1)
		return (-1);
	return (0);
}

static void	get_list_len(t_env *e)
{
	t_elem	*ptr;

	ptr = e->lst;
	e->list_len = 0;
	while (ptr->next != e->lst)
	{
		e->list_len++;
		ptr = ptr->next;
	}
	e->list_len++;
}

int			init_term(t_env *e)
{
	char	*termtype;
	char	*area;

	if (!(termtype = getenv("TERM")))
		exit_error("[EXIT] : 'TERM' variable not found.\n");
	if (tgetent(NULL, termtype) == ERR)
		exit_error("[EXIT] : 'tgetent' error.\n");
	if (tcgetattr(0, &e->term) == -1)
		return (-1);
	e->term.c_lflag &= ~(ICANON);
	e->term.c_lflag &= ~(ECHO);
	e->term.c_cc[VMIN] = 1;
	e->term.c_cc[VTIME] = 0;
	get_list_len(e);
	if (tcsetattr(0, TCSADRAIN, &e->term) == -1)
		return (-1);
	area = NULL;
	return (0);
}

int			reset_term(t_env *e)
{
	char	*area;

	area = NULL;
	TPUTS(CLEAR, 0);
	TPUTS(CURNORM, 0);
	e->term.c_lflag |= ICANON;
	e->term.c_lflag |= ECHO;
	if (tcsetattr(0, TCSANOW, &e->term) == -1)
		return (-1);
	return (0);
}
