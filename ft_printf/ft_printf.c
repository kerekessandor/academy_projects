/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:19:51 by azaha             #+#    #+#             */
/*   Updated: 2015/11/27 19:42:05 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	set_flags_to_zero(t_flag *flag)
{
	flag->has_dot = 0;
	flag->has_hash = 0;
	flag->has_zero = 0;
	flag->has_plus = 0;
	flag->has_minus = 0;
	flag->has_space = 0;
	flag->mod_h = 0;
	flag->mod_hh = 0;
	flag->mod_l = 0;
	flag->mod_ll = 0;
	flag->mod_j = 0;
	flag->mod_z = 0;
	flag->width = 0;
	flag->dot_width = 0;
}

static	char	*get_identifier(char *descriptor, va_list *ap, int len, t_flag *flag)
{
	if (descriptor[len] == 's')
		return(case_flags(descriptor, ap, flag));
	else if (descriptor[len] == 'd')
		descriptor = ft_itoa(va_arg(*ap, int));
	return (descriptor);
}

static	int		ft_descriptor_length(char const *format)
{
	int len;

	len = 1;
	while (ft_strchr(FLAGS, format[len]) && format[len] != '\0')
		len++;
	if (ft_strchr(IDENTIFIERS, format[len]) && format[len] != '\0')
		return (len + 1);
	else if (format[len] == '\0' || !ft_strchr(IDENTIFIERS, format[len]))
		return (len - 1);
	else
		return (len);
}

static	int		process_string(char const *format, va_list *ap)
{
	int		value;
	int		descript_len;
	char	*descriptor;
	t_flag	flag;
	char	*to_print;

	value = 0;
	descript_len = 0;
	to_print = NULL;
	while (*format != '\0')
		if (*format == '%')
		{
			set_flags_to_zero(&flag);
			descript_len = ft_descriptor_length(format);
			descriptor = ft_strsub(format, 0, descript_len);
			compute_flag(descriptor, &flags);
			if (descript_len > 0)
			{
				to_print = get_identifier(descriptor, ap, descript_len - 1, &flag);
				value += ft_strlen(to_print);
				format += descript_len;
			}
			else
				format++;
		}
		else
		{
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
