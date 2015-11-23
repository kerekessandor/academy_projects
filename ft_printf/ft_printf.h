/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:04:30 by azaha             #+#    #+#             */
/*   Updated: 2015/11/23 18:57:50 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

# define "sSpdDioOuUxXcC%" KNOWN_FLAGS

int		ft_printf(const char *format, ...);



#endif
