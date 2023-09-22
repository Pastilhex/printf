/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:06:57 by ialves-m          #+#    #+#             */
/*   Updated: 2022/12/14 20:48:31 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	result;

	result = 0;
	if (!s)
		s = "(null)";
	if (s)
		while (s[result] != '\0')
			result += ft_putchar(s[result]);
	return (result);
}
