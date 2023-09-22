/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:01:23 by ialves-m          #+#    #+#             */
/*   Updated: 2022/12/20 16:36:28 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long long nbr, char *base)
{
	unsigned long	blen;
	unsigned long	result;

	blen = ft_strlen(base);
	result = 0;
	if (nbr >= blen)
	{
		result += ft_putnbr_hexa((nbr / blen), base);
		result += ft_putnbr_hexa((nbr % blen), base);
	}
	else
		result += ft_putchar(base[nbr]);
	return (result);
}
