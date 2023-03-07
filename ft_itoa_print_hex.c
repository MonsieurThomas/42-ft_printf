/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_print_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:45:58 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/13 17:45:59 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_len(long int n)
{
	int	i;

	i = 1;
	while (n > (16 - 1))
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_itoa_print_hex_2ndpart(char *str, int len, unsigned int n, int min)
{
	int	i;

	i = -1;
	str[len] = '\0';
	while (--len >= 0)
	{
		if ((n % 16) < 10)
			str[len] = (n % 16) + '0';
		else if (min == 0)
			str[len] = (n % 16) + '7';
		else if (min == 1)
			str[len] = (n % 16) + 87;
		n = n / 16;
	}
	while (str[++i])
		write(1, &str[i], 1);
	free(str);
}

int	ft_itoa_print_hex(unsigned int n, int Ox, int min)
{
	int				len;
	char			*str;
	long long int	nbr;

	nbr = n;
	len = ft_get_len(n);
	while (len > 10)
	{
		n = n / 10;
		len--;
	}	
	if (Ox == 1)
		write(1, "0x", 2);
	if (n < 0)
		n *= -1;
	str = malloc(sizeof(char) * len + 1);
	ft_itoa_print_hex_2ndpart(str, len, n, min);
	if (Ox == 1)
		len += 2;
	return (len);
}
