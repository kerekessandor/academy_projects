#include "../includes/ft_printf.h"

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

static	void	check_flags(char **descriptor, t_flag *flag)
{
	if (**descriptor == '#')
		flag->has_hash = 1;
	if (**descriptor == '0')
		flag->has_zero = 1;
	if (**descriptor == '+')
		flag->has_plus = 1;
	if (**descriptor == '-')
		flag->has_minus = 1;
	if (**descriptor == ' ')
		flag->has_space = 1;
}

static	void	check_mods(char **descriptor, t_flag *flag)
{
	if (**descriptor == 'h' && (*(*descriptor + 1) == 'h'))
	{
		flag->mod_hh = 1;
		(*descriptor)++;
	}
	else if (**descriptor == 'l' && (*(*descriptor + 1) == 'l'))
	{
		flag->mod_ll = 1;
		(*descriptor)++;
	}
	else if (**descriptor == 'h')
		flag->mod_h = 1;
	else if (**descriptor == 'l')
		flag->mod_l = 1;
	else if (**descriptor == 'j')
		flag->mod_j = 1;
	else if (**descriptor == 'z')
		flag->mod_z = 1;
}

static	void	check_precision(char **descriptor, t_flag *flag)
{
	if (ft_isdigit(**descriptor))
	{
		flag->width = 0;
		while (ft_isdigit(**descriptor))
		{
			flag->width = flag->width * 10 + (**descriptor - '0');
			(*descriptor)++;
		}
		(*descriptor)--;
	}
	else if (**descriptor == '.')
	{
		flag->has_dot = 1;
		flag->dot_width = 0;
		while (ft_isdigit(**descriptor))
		{
			flag->dot_width = flag->dot_width * 10 + (**descriptor + '0');
			(*descriptor)++;
		}
		(*descriptor)--;
	}
}

int					process_descriptor(char *descriptor, va_list *ap)
{
	int chrs;
	t_flag flag;

	chrs = 0;
	set_flags_to_zero(&flag);

	while (*descriptor != '\0')
	{
		check_flags(&descriptor, &flag);
		check_mods(&descriptor, &flag);
		if (*descriptor != '0')
			check_precision(&descriptor, &flag);
		if (ft_strchr(IDENTIFIERS, *descriptor))
			chrs = check_identifier(descriptor, ap, flag);
		descriptor++;
	}
	return(chrs);
}