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

/*----------Defines---------------*/

# define IDENTIFIERS "sSpdDioOuUxXcC"
# define FLAGS "0123456789.#hljz +-"

/*----------Structures------------*/

typedef	struct		s_flag
{
	int				has_dot;
	int				has_hash;
	int				has_zero;
	int				has_plus;
	int				has_minus;
	int				has_space;
	int				mod_h;
	int				mod_hh;
	int				mod_l;
	int				mod_ll;
	int				mod_j;
	int				mod_z;
	unsigned int	width;
	unsigned int	dot_width;
}					t_flag;

/*---------Prototypes-----------*/

int					ft_printf(const char *format, ...);
char				*case_string(char *descriptor, va_list *ap, t_flag *flag);
void				ft_compute_flags(char *descriptor, t_flag flag);

#endif
