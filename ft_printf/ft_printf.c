/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:19:51 by azaha             #+#    #+#             */
/*   Updated: 2015/11/25 18:02:02 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



static	int	ft_flag_length(char const *s)
{
	int index;
	int flag_end;

	index = 1;
	flag_end = 0;
	while (ft_strchr(INNER_FLAGS, s[index]) && s[index] != '\0')
	{
		flag_end++;
		index++;
	}
	if (ft_strchr(END_FLAGS, s[index]) && s[index] != '\0')
	{
		flag_end++;
		ft_putstr("valid flag -> ");
	}
	else
		ft_putstr("not a valid flag -> ");
	return (flag_end);
}

static	int	process_string(char const *format, va_list *ap)
{
	int		value;
	int		flag_end;
	char	*flag;

	ap = 0;
	value = 0;
	flag_end = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			flag_end = ft_flag_length(format);
			flag = ft_strsub(format, 0, flag_end + 1);
			ft_putstr(flag);
			ft_putchar('\n');
			format += flag_end + 1;
		}
	/*	else
			ft_putchar(*format);*/
		format++;
	}
	return(value);
}

int		ft_printf(char const *format, ...)
{
	va_list ap;
	int		value;

	value = 0;
	va_start(ap, format);
	value = process_string(format, &ap);
	va_end(ap);
	return (value);
}
