/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 14:32:17 by fhuang            #+#    #+#             */
/*   Updated: 2016/07/07 12:18:10 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		no_type_conversion(t_print *link)
{
	static void	(*p[5])(t_print *link, char *str, int len, t_bool neg);
	int			len;
	char		*str;
	int			i;

	str = NULL;
	len = WIDTH > 0 ? WIDTH : 1;
	if ((str = ft_strnew(len)) == NULL)
		exit(EXIT_FAILURE);
	ft_strncpy(str, &C, 1);
	LEN = 1;
	p[0] = transform_zero;
	p[1] = transform_plus;
	p[2] = transform_space;
	p[3] = transform_hash;
	p[4] = transform_minus;
	i = -1;
	while (++i < 5)
		(*p[i])(link, str, len, false);
	WIDTH ? PUSH_FRONT(' ', WIDTH - ft_strlen(str)) : 0;
	RET = str;
}
