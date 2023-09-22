/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:31:47 by ialves-m          #+#    #+#             */
/*   Updated: 2022/12/20 16:47:01 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_printer {
	va_list		args;
	int			count;
}	t_fprinter;

int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_base(long long int nbr, char *base);
int		ft_putnbr_hexa(unsigned long long nbr, char *base);
int		ft_putstr(char *s);
int		ft_printf(const char *num_args, ...);
size_t	ft_strlen(const char *s);

#endif
