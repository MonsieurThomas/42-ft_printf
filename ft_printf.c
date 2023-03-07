/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:56:00 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/19 13:13:00 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar_print(va_arg(args, int));
	if (c == 's')
		len = ft_putstr_print(va_arg(args, char *));
	if (c == 'p')
		len = ft_print_p(va_arg(args, unsigned long long));
	if (c == 'd')
		len = ft_itoa_print(va_arg(args, long int));
	if (c == 'i')
		len = ft_itoa_print(va_arg(args, long int));
	if (c == 'u')
		len = ft_itoa_uprint(va_arg(args, unsigned int));
	if (c == 'x')
		len = ft_itoa_print_hex(va_arg(args, unsigned int), 0, 1);
	if (c == 'X')
		len = ft_itoa_print_hex(va_arg(args, unsigned int), 0, 0);
	if (c == '%')
		len = ft_putchar_print('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_type(args, s[i]);
		}
		else
		{
			ft_putchar_print(s[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
