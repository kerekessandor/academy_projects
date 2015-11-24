/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:52:11 by azaha             #+#    #+#             */
/*   Updated: 2015/11/24 17:27:04 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	process_string(const char *format, va_list *ap, size_t nr_of_bytes)
{
	char *next_arg;

	if (*format == '\0')
		return (nr_of_bytes);
	next_arg = ft_strchr(format, '%');
	if (next_arg == NULL)
	{
		ft_putstr(format);
		return (nr_of_bytes + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return (process_string(next_arg, ap, nr_of_bytes + (next_arg - format)));
	}
	else
	{

	}
}

int			ft_printf(const char * format, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	va_start(ap, format);
	ret = process_string(format, &ap, 0);
	va_end(ap);
	return (ret);
}
