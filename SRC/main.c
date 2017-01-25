/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 14:45:56 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/22 16:35:21 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			g_fd;

int			main(int ac, char **av)
{
	t_env	e;

	if (ac > 1)
	{
		if ((e.fd = open("/dev/tty", O_RDWR)) == -1)
			return (1);
		e.screen_row = e.list_len;
		e.screen_col = 1;
		g_fd = e.fd;
		create_list(&e, av, ac);
		if (e.lst == NULL)
			return (0);
		if (init_term(&e) == -1)
			return (1);
		display_on_screen(&e);
		if (e.list_len != 0)
			exit_result(e.lst);
		exit_free(&e);
		if (close(e.fd) == -1)
			return (1);
	}
	return (0);
}
