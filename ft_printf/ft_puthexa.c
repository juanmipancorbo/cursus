/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:09:54 by jpancorb          #+#    #+#             */
/*   Updated: 2023/10/17 18:54:25 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(char *hexdig, unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
	{
		ret = ft_puthexa(hexdig, n / 16);
		if (ret == -1)
			return (-1);
		if (write (1, &hexdig[n % 16], 1) == -1)
			return (-1);
		ret++;
	}
	else if (n < 16)
	{
		if (write (1, &hexdig[n], 1) == -1)
			return (-1);
		ret++;
	}
	return (ret);
}
