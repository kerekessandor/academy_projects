#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static	char	*edit_spaces(char *text, char *spaces, t_flag flag)
{
	if (flag.has_hash == 1)
	{
		spaces = ft_memalloc(flag.width - ft_strlen(text) - 1);
		if (flag.has_zero == 1 && flag.has_minus == 0)
			spaces = ft_memset(spaces, '0', flag.width - ft_strlen(text) - 2);
		else
			spaces = ft_memset(spaces, ' ', flag.width - ft_strlen(text) - 2);
	}
	else
	{
		spaces = ft_memalloc(flag.width - ft_strlen(text) + 1);
		if (flag.has_zero == 1 && flag.has_minus == 0)
			spaces = ft_memset(spaces, '0', flag.width - ft_strlen(text));
		else
			spaces = ft_memset(spaces, ' ', flag.width - ft_strlen(text));
	}
	return(spaces);
}

static	int	print_text_hash(char *text, char *spaces, t_flag flag)
{
	if (flag.has_minus == 1)
	{
		ft_putstr("0x");
		ft_putstr(text);
		ft_putstr(spaces);
	}
	else
	{
		if (flag.has_zero == 1)
		{
			ft_putstr("0x");
			ft_putstr(spaces);
			ft_putstr(text);
		}
		else
		{
			ft_putstr(spaces);
			ft_putstr("0x");
			ft_putstr(text);
		}
	}
	return(ft_strlen(text) + ft_strlen(spaces) + 2);
}

static	int	print_text_no_hash(char *text, char *spaces, t_flag flag)
{
	if (flag.has_minus == 1)
	{
		ft_putstr(text);
		ft_putstr(spaces);	
	}
	else
	{
		ft_putstr(spaces);
		ft_putstr(text);
	}
	return(ft_strlen(text) + ft_strlen(spaces));
}

static	int	print_order(char *text, char *spaces, t_flag flag)
{
	if (flag.has_hash == 1)
		return(print_text_hash(text, spaces, flag));
	else
		return(print_text_no_hash(text, spaces, flag));
}

static	int	case_no_width(char *text, t_flag flag)
{
	if (flag.has_hash == 1)
	{
		ft_putstr("0x");
		ft_putstr(text);
		return(ft_strlen(text) + 2);
	}
	else
	{
		ft_putstr(text);
		return(ft_strlen(text));
	}
}

int			edit_hexa(va_list *ap, t_flag flag)
{
	unsigned int	nbr;
	char			*text;
	char			*spaces;

	spaces = NULL;
	nbr = va_arg(*ap, unsigned int);
	text = ft_itoa_base16(nbr, "0123456789abcdef");
	if (flag.width > ft_strlen(text))
	{
		spaces = edit_spaces(text, spaces, flag);
		return(print_order(text, spaces, flag));
	}
	else
		return(case_no_width(text, flag));
}