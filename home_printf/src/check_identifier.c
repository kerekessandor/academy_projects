#include "../includes/ft_printf.h"

static	int 	check_char_identifiers(char *descriptor, va_list ap, t_flag flag)
{
	if (*descriptor == 's')
		return(edit_string(ap, flag));
	//if (*descriptor == 'c')
	//	return(edit_char(ap, flag));
	return (0);
}

int				check_identifier(char *descriptor, va_list ap, t_flag flag)
{
	int chrs;

	chrs = 0;
	chrs += check_char_identifiers(descriptor, ap, flag);
	//chrs += check_nbr_identifiers(descriptor, ap, flag);
	return(chrs);
}