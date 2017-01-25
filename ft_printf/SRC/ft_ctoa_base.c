/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 13:40:41 by fhuang            #+#    #+#             */
/*   Updated: 2016/09/02 16:08:46 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n(unsigned char n, int base)
{
	int					ret;

	ret = 1;
	while (n / base)
	{
		ret++;
		n /= base;
	}
	return (ret);
}

char		*ft_ctoa_base(char n, int base, t_bool is_uin, t_bool *is_neg)
{
	char				pattern[17];
	char				*ret;
	unsigned char		uin;
	int					len;
	t_bool				neg;

	ft_strcpy(pattern, "0123456789abcdef");
	neg = (base == 10 && n < 0) ? 1 : 0;
	neg && is_uin == false ? ABS(n) : 1;
	uin = (unsigned char)n;
	len = count_n(uin, base);
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	ret[len--] = 0;
	while (len >= 0)
	{
		ret[len] = pattern[uin % base];
		uin /= base;
		len--;
	}
	*is_neg = is_uin == false ? neg : 0;
	return (ret);
}
