/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 22:08:14 by jpancorb          #+#    #+#             */
/*   Updated: 2024/03/10 20:24:05 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static void	ft_putnbr(int n)
{
	unsigned int	nb;
	char			c;

	if (n < 0)
	{
		nb = -n;
		write(1, "-", 1);
	}
	else
		nb = n;
	if (nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + 48;
	write(1, &c, 1);
}

static void	handle_signal(int signal)
{
	static unsigned char	curr_chr;
	static int				bit_i;

	curr_chr |= (signal == SIGUSR1);
	bit_i++;
	if (bit_i == 8)
	{
		write(1, &curr_chr, 1);
		bit_i = 0;
		curr_chr = 0;
	}
	else
		curr_chr <<= 1;
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
