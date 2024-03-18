/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:51:26 by jpancorb          #+#    #+#             */
/*   Updated: 2024/03/14 21:34:04 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - 48);
	return (result * sign);
}

static void	send_signal(int pid, unsigned char chr)
{
	int				i;
	unsigned char	temp_chr;

	i = 8;
	temp_chr = chr;
	while (i-- > 0)
	{
		temp_chr = chr >> i;
		if (temp_chr % 2)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}

static void	confirm_signal(int signal)
{
	if (signal == SIGUSR2)
		usleep(50);
	else if (signal == SIGUSR1)
		write(1, "Signal sended.\n", 15);
}

static int	check_args(char **argv)
{
	int	i;

	i = 0;
	if (argv[1])
	{
		while (argv[1][i])
		{
			if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
			{
				write(1, "Invalid server_PID.\n", 20);
				return (1);
			}
			i++;
		}
		if (!argv[2][0])
		{
			write(1, "Invalid or empty message. Example: \"message\"\n", 45);
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		if (check_args(argv))
			return (1);
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			signal(SIGUSR1, confirm_signal);
			signal(SIGUSR2, confirm_signal);
			send_signal(pid, argv[2][i]);
			i++;
		}
		send_signal(pid, '\n');
	}
	else
	{
		write(1, "Wrong arguments. Try <./...> <PID> \"message\"\n", 45);
		return (1);
	}
	return (0);
}
