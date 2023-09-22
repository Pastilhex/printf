/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialves-m <ialves-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:20:10 by ialves-m          #+#    #+#             */
/*   Updated: 2022/12/20 16:40:00 by ialves-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int		slen;
	char	*ptr;
	int		last;

	last = ft_strlen(s);
	ptr = (char *)s;
	slen = 0;
	if (c == '\0')
		return (ptr + last);
	while (s[slen] != '\0')
	{
		if (s[slen] == c)
			return ((char *)s + slen);
		slen++;
	}
	return (NULL);
}

int	first(char digit, t_fprinter *estrutura)
{
	unsigned long long	ptr;
	int					count;

	count = 0;
	if (digit == 'c')
		count += ft_putchar(va_arg(estrutura->args, int));
	else if (digit == 's')
		count += ft_putstr(va_arg(estrutura->args, char *));
	else if (digit == 'p')
	{
		ptr = va_arg(estrutura->args, unsigned long long);
		if (!ptr)
			count += ft_putstr("(nil)");
		else if (ptr)
		{
			count += ft_putstr("0x");
			count += ft_putnbr_hexa(ptr, "0123456789abcdef");
		}
	}
	else if (digit == 'd' || digit == 'i')
		count += ft_putnbr(va_arg(estrutura->args, int));
	return (count);
}

int	check(char digit, t_fprinter *estrutura)
{
	int	count;

	count = 0;
	if (ft_strchr("cspdi", digit))
		count += first(digit, estrutura);
	else if (digit == 'u')
		count += ft_putnbr_u(va_arg(estrutura->args, unsigned int));
	else if (digit == 'x')
		count += ft_putnbr_hexa(va_arg(estrutura->args, unsigned int),
				"0123456789abcdef");
	else if (digit == 'X')
		count += ft_putnbr_hexa(va_arg(estrutura->args, unsigned int),
				"0123456789ABCDEF");
	else if (digit == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *num_args, ...)
{
	t_fprinter	*estrutura;
	int			i;
	int			result;

	i = 0;
	result = 0;
	estrutura = (t_fprinter *)malloc(sizeof(t_fprinter));
	estrutura->count = 0;
	va_start(estrutura->args, num_args);
	while (num_args[i] != '\0')
	{
		if (num_args[i] == '%')
			result += check(num_args[++i], estrutura);
		else
			result += ft_putchar(num_args[i]);
		i++;
	}
	va_end(estrutura->args);
	free (estrutura);
	return (result);
}
