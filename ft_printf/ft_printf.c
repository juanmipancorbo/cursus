/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:21:46 by jpancorb          #+#    #+#             */
/*   Updated: 2023/10/17 21:55:45 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	wr_args(char c, va_list ap)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_hexapoint(va_arg(ap, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_unsnbr(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_puthexa("0123456789abcdef", (va_arg(ap, int))));
	if (c == 'X')
		return (ft_puthexa("0123456789ABCDEF", (va_arg(ap, int))));
	return (0);
}

static int	wr_format(const char *format, va_list ap, int ret)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				ret += write(1, "%", 1);
			else
				ret += wr_args(format[i + 1], ap);
			if (ret == -1)
				return (-1);
			i++;
		}
		else
		{
			if (write (1, &format[i], 1) != 1)
				return (-1);
			ret++;
		}
		i++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	ret = 0;
	va_start(ap, format);
	ret = wr_format(format, ap, ret);
	va_end(ap);
	return (ret);
}
