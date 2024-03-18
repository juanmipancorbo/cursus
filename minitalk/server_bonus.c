/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:51:16 by jpancorb          #+#    #+#             */
/*   Updated: 2024/03/12 19:16:38 by jpancorb         ###   ########.fr       */
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

static void	handle_signal(int signal, siginfo_t *t_sig_info, void *oact)
{
	static unsigned char	curr_chr;
	static int				bit_i;

	(void)oact;
	curr_chr |= (signal == SIGUSR1);
	bit_i++;
	if (bit_i == 8)
	{
		write(1, &curr_chr, 1);
		kill(t_sig_info->si_pid, SIGUSR1);
		bit_i = 0;
		curr_chr = 0;
	}
	else
	{
		curr_chr <<= 1;
		kill(t_sig_info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	s_sig;

	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	s_sig.sa_sigaction = handle_signal;
	sigemptyset(&s_sig.sa_mask);
	s_sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
	while (1)
		pause();
	return (0);
}
