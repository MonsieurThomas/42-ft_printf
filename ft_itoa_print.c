/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:44:22 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/19 13:09:10 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_get_len(long int n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_itoa_print_2ndpart(char *str, int len, long int n, int nbr)
{
	int	i;

	i = -1;
	str[len] = '\0';
	while (--len >= 0)
	{
		if ((n % 10) < 10)
			str[len] = (n % 10) + '0';
		else
			str[len] = (n % 10) + '7';
		n = n / 10;
	}
	if (nbr < 0)
		str[0] = '-';
	while (str[++i])
		write(1, &str[i], 1);
	free(str);
}

int	ft_itoa_print(int n)
{
	int			len;
	char		*str;
	long int	nbr;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	nbr = n;
	len = 0;
	if (nbr < 0)
		n *= -1;
	len = ft_get_len(n);
	if (nbr < 0)
		len++;
	str = malloc(sizeof(char) * len + 1);
	ft_itoa_print_2ndpart(str, len, n, nbr);
	return (len);
}
