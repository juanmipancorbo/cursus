/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpancorb <jpancorb@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:05:48 by jpancorb          #+#    #+#             */
/*   Updated: 2023/10/17 21:56:04 by jpancorb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const	char *str, ...);
int				ft_putchar(int c);
int				ft_putstr(char *s);
int				ft_hexapoint(void *point);
int				ft_putnbr(int n);
unsigned int	ft_unsnbr(unsigned int num);
int				ft_puthexa(char *hexdig, unsigned int n);

#endif
