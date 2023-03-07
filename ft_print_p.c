/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:20:43 by ajordan-          #+#    #+#             */
/*   Updated: 2022/04/19 13:18:58 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_p_len(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_p(unsigned long long num)
{
	if (num > 15)
	{
		ft_put_p(num / 16);
		ft_put_p(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_print_p(unsigned long long n)
{
	int	len;

	len = 2;
	write(1, "0x", 2);
	if (n == 0)
	{
		len += 1;
		write(1, "0", 1);
	}
	else
	{
		ft_put_p(n);
		len += ft_p_len(n);
	}
	return (len);
}
