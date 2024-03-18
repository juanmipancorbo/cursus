/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexapoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:08:43 by jpancorb          #+#    #+#             */
/*   Updated: 2023/10/17 22:06:22 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pointohexa(char *hexdigit, unsigned long point, int ret)
{
	if (point >= 16)
	{
		ret = pointohexa(hexdigit, point / 16, ret);
		if (!ret)
			return (-1);
		if (!(write (1, &hexdigit[point % 16], 1)))
			return (-1);
		ret++;
	}
	else if (point < 16)
	{
		if (!(write (1, &hexdigit[point], 1)))
			return (-1);
		ret++;
	}
	return (ret);
}

int	ft_hexapoint(void *point)
{
	int		ret;

	ret = 0;
	if (write(1, "0x", 2) != 2)
		return (-1);
	ret = pointohexa("0123456789abcdef", (unsigned long)point, ret);
	if (ret == -1)
		return (-1);
	ret += 2;
	return (ret);
}
