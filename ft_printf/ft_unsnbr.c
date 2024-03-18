/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:11:27 by jpancorb          #+#    #+#             */
/*   Updated: 2023/10/16 20:11:49 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_unsnbr(unsigned int num)
{
	int	ret;

	ret = 0;
	if (num > 9)
	{
		ret = ft_unsnbr(num / 10);
		if (ret == -1)
			return (-1);
		num = num % 10;
	}
	if (num <= 9)
	{
		if (ft_putchar (('0' + num)) == -1)
			return (-1);
		ret++;
	}
	return (ret);
}
