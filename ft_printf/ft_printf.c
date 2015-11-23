/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:52:11 by azaha             #+#    #+#             */
/*   Updated: 2015/11/23 18:57:46 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char * format, ...)
{
	va_list ap;

	va_start(ap, format);
	while(*format)
	{
		if (*format == '%')
		{
			format++;
			while (!(ft_strchr(KNOWN_FLAGS, *format)))
			{

				format++;
			}
		}
		else
			ft_putchar(*format);
		format++;
	}
}
