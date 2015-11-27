/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:04:30 by azaha             #+#    #+#             */
/*   Updated: 2015/11/27 18:29:20 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define IDENTIFIERS "sSpdDioOuUxXcC"
# define FLAGS "0123456789.#hljz +-"

typedef	struct		s_flag
{
	int				has_hashtag;
	int				has_plus;
	int				has_minus;
	int				has_zero;
	int				has_h;
	int				has_l;
	int				has_j;
	int				has_z;
	int				has_dot;
	int				has_hh;
	int				has_ll;
	int				has_space;
	unsigned int	width;
	unsigned int	dot_width;
}					t_flag;

int					ft_printf(const char *format, ...);
char				*case_string(char *descriptor, va_list *ap, t_flag *flag);
void				ft_compute_flags(char *descriptor, t_flag flag);
#endif
