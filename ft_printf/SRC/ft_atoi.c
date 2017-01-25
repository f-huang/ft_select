/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:53:44 by fhuang            #+#    #+#             */
/*   Updated: 2016/07/01 16:26:37 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			i;
	int			res;
	const char	*ptr;
	int			negatif;

	i = 0;
	res = 0;
	negatif = 1;
	ptr = str;
	while (*ptr && ft_isspace(*ptr))
		ptr++;
	negatif = *ptr == '-' ? -1 : 1;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (*ptr && ft_isdigit(*ptr))
	{
		res *= 10;
		res += negatif * (*ptr - '0');
		ptr++;
	}
	return (res);
}
