/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:10:38 by jpancorb          #+#    #+#             */
/*   Updated: 2023/10/18 18:06:38 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	ret;

	ret = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0 && ++ret)
	{
		if (write(1, "-", 1) != 1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		ret += ft_putnbr(n / 10);
		if (ret == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_putchar ('0' + n) == -1)
			return (-1);
		ret++;
	}
	return (ret);
}
