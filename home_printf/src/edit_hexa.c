#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static	int		case_zero(char *spaces, t_flag flag)
{
	if (flag.width > 0)
	{
		spaces = ft_memalloc(flag.width);
		if (flag.has_zero == 1)
			spaces = ft_memset(spaces, '0', flag.width - 1);
		else
			spaces = ft_memset(spaces, ' ', flag.width - 1);
	}
	else
	{
		ft_putstr("0");
		return(1);
	}
	if (flag.has_minus == 1)
	{
		ft_putstr("0");
		ft_putstr(spaces);
	}
	else
	{
		ft_putstr(spaces);
		ft_putstr("0");
	}
	return(ft_strlen(spaces) + 1);
}

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

static	int	print_text_hash(char *text, char *spaces, char *sign, t_flag flag)
{
	if (flag.has_minus == 1)
	{
		ft_putstr(sign);
		ft_putstr(text);
		ft_putstr(spaces);
	}
	else
	{
		if (flag.has_zero == 1)
		{
			ft_putstr(sign);
			ft_putstr(spaces);
			ft_putstr(text);
		}
		else
		{
			ft_putstr(spaces);
			ft_putstr(sign);
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

static	int	edit_order(char *text, char *spaces, char *sign, t_flag flag)
{
	if (flag.has_hash == 1)
		return(print_text_hash(text, spaces, sign, flag));
	else
		return(print_text_no_hash(text, spaces, flag));
}

static	int	case_no_width(char *text, char *sign, t_flag flag)
{
	if (flag.has_hash == 1)
	{
		ft_putstr(sign);
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
	char			*sign;

	spaces = NULL;
	sign = ft_memalloc(2);
	ft_strcpy(sign, "0x");
	if ((nbr = va_arg(*ap, unsigned int)) == 0)
		return(case_zero(spaces, flag));
	text = ft_itoa_base16(nbr, "0123456789abcdef");
	if (flag.width > ft_strlen(text))
	{
		spaces = edit_spaces(text, spaces, flag);
		return(edit_order(text, spaces, sign, flag));
	}
	else
		return(case_no_width(text, sign, flag));
}

int			edit_uppercase_hexa(va_list *ap, t_flag flag)
{
	unsigned int	nbr;
	char			*text;
	char			*spaces;
	char			*sign;

	spaces = NULL;
	sign = ft_memalloc(2);
	ft_strcpy(sign, "0X");
	if ((nbr = va_arg(*ap, unsigned int)) == 0)
		return(case_zero(spaces, flag));
	text = ft_itoa_base16(nbr, "0123456789ABCDEF");
	if (flag.width > ft_strlen(text))
	{
		spaces = edit_spaces(text, spaces, flag);
		return(edit_order(text, spaces, sign, flag));
	}
	else
		return(case_no_width(text, sign, flag));
}