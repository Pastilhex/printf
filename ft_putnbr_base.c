/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:01:23 by ialves-m          #+#    #+#             */
/*   Updated: 2022/12/20 15:50:30 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calc(long long int nbr, int blen, char *base)
{
	int	count;

	count = 0;
	if (nbr >= blen)
	{
		count += ft_calc((nbr / blen), blen, base);
		count += ft_calc((nbr % blen), blen, base);
	}
	else
	{
		count += putchar(base[nbr]);
	}
	return (count);
}

int	check_double(char *base, int blen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (blen > 1)
	{
		while (base[i] != '\0' && base[i] != '+' && base[i] != '-')
		{
			j = i + 1;
			while (j < blen)
			{
				if (base[i] == base[j])
					return (0);
				j++;
			}
			i++;
		}
	}
	else
	{
		return (0);
	}
	return (1);
}

int	ft_putnbr_base(long long int nbr, char *base)
{
	int	blen;
	int	count;

	count = 0;
	blen = ft_strlen(base);
	if (nbr > 0 && (check_double(base, blen) == 1))
	{
		count += ft_calc(nbr, blen, base);
	}
	else
	{
		nbr *= -1;
		count += ft_calc(nbr, blen, base);
	}
	return (count);
}
