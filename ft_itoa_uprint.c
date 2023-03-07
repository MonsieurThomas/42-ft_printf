/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:58:12 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/19 13:18:41 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_itoa_uprint_2ndpart(char *str, int len, unsigned int n)
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
	while (str[++i])
		write(1, &str[i], 1);
	free(str);
}

int	ft_itoa_uprint(unsigned int n)
{
	int		len;
	char	*str;

	len = 0;
	len = ft_get_len(n);
	str = malloc(sizeof(char) * len + 1);
	ft_itoa_uprint_2ndpart(str, len, n);
	return (len);
}
