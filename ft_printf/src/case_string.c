/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:27:27 by azaha             #+#    #+#             */
/*   Updated: 2015/11/27 18:14:29 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

char	*case_string(char *descriptor, va_list *ap, t_flag *flag)
{
	size_t index;

	index = 1;
	while ((index < (ft_strlen(descriptor) - 1)) && ft_isdigit(descriptor[index]))
	{
			flag->width = flag->width * 10 + (descriptor[index] - '0');
			index++;
	}
	descriptor = va_arg(*ap, char*);
	while (flag->width > ft_strlen(descriptor))
	{
		ft_putchar(' ');
		flag->width--;
	}

	ft_putstr(descriptor);
	return (descriptor);
}
