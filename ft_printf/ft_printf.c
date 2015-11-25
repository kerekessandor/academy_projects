/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:19:51 by azaha             #+#    #+#             */
/*   Updated: 2015/11/25 18:43:19 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	edit_flag(char *flag, va_list *ap)
{
	flag = va_arg(*ap, char*);
	if (ft_strcmp(flag, "%s"))
	{
		ft_putstr(flag);
	}
}

static	int		ft_flag_length(char const *s)
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
	return (flag_end + 1);
}

static	int		process_string(char const *format, va_list *ap)
{
	int		value;
	int		flag_end;
	char	*flag;

	value = 0;
	flag_end = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			flag_end = ft_flag_length(format);
			flag = ft_strsub(format, 0, flag_end + 1);
			edit_flag(flag, ap);
			format += flag_end;
		}
		else
			ft_putchar(*format);
		format++;
		value++;
	}
	return (value);
}

int				ft_printf(char const *format, ...)
{
	va_list ap;
	int		value;

	value = 0;
	va_start(ap, format);
	value = process_string(format, &ap);
	va_end(ap);
	return (value);
}
