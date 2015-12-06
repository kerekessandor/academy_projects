#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

/* ----- DEFINES ----- */

# define IDENTIFIERS "sSpdDioOuUxXcC"
# define FLAGS "0123456789 hljz#+-."

/* ----- STRUCTURES ----- */

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

/* ----- PROTOTYPES ----- */

int 				ft_printf(const char *format, ...);
int					process_descriptor(char *descriptor, va_list *ap);
int					check_identifier(char *descriptor, va_list *ap, t_flag flag);
int					edit_s_string(va_list *ap, t_flag flag);
int					edit_c_char(va_list *ap, t_flag flag);
int					edit_di_integer(va_list *ap, t_flag flag);
int					edit_x_hexa(va_list *ap, t_flag flag);
int					edit_X_hexa(va_list *ap, t_flag flag);
/*
int					edit_address(va_list *ap, t_flag flag);
int					edit_octal(va_list *ap, t_flag flag);
int					edit_unsigned_decimal(va_list *ap, t_flag flag);
*/
#endif