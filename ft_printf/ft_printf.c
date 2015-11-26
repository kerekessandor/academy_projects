/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:19:51 by azaha             #+#    #+#             */
/*   Updated: 2015/11/26 18:29:16 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	set_flags_to_zero(t_flag *farg)
{
	farg->has_hashtag = 0;
	farg->has_plus = 0;
	farg->has_zero = 0;
	farg->has_h = 0;
	farg->has_l = 0;
	farg->has_j = 0;
	farg->has_z = 0;
	farg->has_dot = 0;
	farg->has_hh = 0;
	farg->has_ll = 0;
	farg->has_space = 0;
	farg->width = 0;
	farg->dot_width = 0;
}

static	char	*set_descriptor(char *descriptor, va_list *ap, int descript_end)
{
	if (descriptor[descript_end] == 'd')
		descriptor = ft_itoa(va_arg(*ap, int));
	else if (descriptor[descript_end] == 's')
		descriptor = va_arg(*ap, char*);
	return (descriptor);
}
/*
static	void	edit_descriptor()
{

}
*/
static	int		ft_descriptor_length(char const *s)
{
	int index;
	int descript_end;

	index = 1;
	descript_end = 0;
	while (ft_strchr(FLAGS, s[index]) && s[index] != '\0')
	{
		descript_end++;
		index++;
	}
	return (descript_end -1);
}

static	int		process_string(char const *format, va_list *ap)
{
	int		value;
	int		descript_end;
	char	*descriptor;
	t_flag	flag;

	value = 0;
	descript_end = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			descript_end = ft_descriptor_length(format);
			descriptor = ft_strsub(format, 0, descript_end + 1);
			set_flags_to_zero(&flag);
			if (ft_strchr(IDENTIFIERS, format[descript_end]))
				ft_putstr(set_descriptor(descriptor, ap, descript_end));
			format += descript_end;
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
