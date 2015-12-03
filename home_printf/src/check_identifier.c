#include "../includes/ft_printf.h"

static	int 	check_char_identifiers(char *descriptor, va_list *ap, t_flag flag)
{
	if (*descriptor == 's')
		return(edit_string(ap, flag));
	if (*descriptor == 'c')
		return(edit_char(ap, flag));
	return (0);
}

static	int 	check_nbr_identifiers(char *descriptor, va_list *ap, t_flag flag)
{
	if (*descriptor == 'd' || *descriptor == 'i')
		return(edit_integer(ap, flag));
	if (*descriptor == 'x')
		return(edit_hexa(ap, flag));
/*	if (*descriptor == 'p')
		return(edit_address(ap, flag));
	if (*descriptor == 'o')
		return(edit_octal(ap, flag));
	if (*descriptor == 'u')
		return(edit_unsigned_decimal(ap, flag));*/
	return (0);
}

int				check_identifier(char *descriptor, va_list *ap, t_flag flag)
{
	int chrs;

	chrs = 0;
	chrs += check_char_identifiers(descriptor, ap, flag);
	chrs += check_nbr_identifiers(descriptor, ap, flag);
	return(chrs);
}