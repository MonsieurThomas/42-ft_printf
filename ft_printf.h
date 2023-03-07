/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthomas <rthomas@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:48:59 by rthomas           #+#    #+#             */
/*   Updated: 2022/04/19 13:17:41 by rthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int			ft_printf(const char *s, ...);
int			ft_putchar_print(char c);
int			ft_putstr_print(char *str);
int			ft_itoa_print(int n);
int			ft_itoa_uprint(unsigned int n);
int			ft_itoa_print_hex(unsigned int n, int Ox, int min);
int			ft_print_p(unsigned long long n);

#endif