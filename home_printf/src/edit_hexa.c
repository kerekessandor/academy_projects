#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static	int	case_width(char *text, t_flag flag, char fill)
{
	char *spaces;

	if (flag.has_hash == 1)
	{
		spaces = ft_memalloc(flag.width - ft_strlen(text) - 1);
		spaces = ft_memset(spaces, fill, flag.width - ft_strlen(text) - 2);
		ft_putstr(spaces);
		ft_putstr("0x");
		ft_putstr(text);
		return(ft_strlen(text) + 2);
	}
	else
	{
		spaces = ft_memalloc(flag.width - ft_strlen(text) + 1);
		spaces = ft_memset(spaces, fill, flag.width - ft_strlen(text));
		ft_putstr(spaces);
		ft_putstr(text);
		return(ft_strlen(text));
	}
}

static	int	case_width_zero(char *text, t_flag flag, char fill)
{
	char *spaces;

	if (flag.has_hash == 1)
	{
		spaces = ft_memalloc(flag.width - ft_strlen(text) - 1);
		spaces = ft_memset(spaces, fill, flag.width - ft_strlen(text) - 2);
		ft_putstr("0x");
		ft_putstr(spaces);
		ft_putstr(text);
		return(ft_strlen(text) + 2);
	}
	else
	{
		spaces = ft_memalloc(flag.width - ft_strlen(text) + 1);
		spaces = ft_memset(spaces, fill, flag.width - ft_strlen(text));
		ft_putstr(spaces);
		ft_putstr(text);
		return(ft_strlen(text));
	}
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
	char			fill;
	char			*text;

	fill = ' ';
	if (flag.has_zero == 1)
		fill = '0';
	nbr = va_arg(*ap, unsigned int);
	if (nbr == 0)
	{	
		ft_putstr("0");
		return(1);
	}
	text = ft_itoa_base16(nbr, "0123456789abcdef");
	if (flag.width > ft_strlen(text))
	{
		if (fill == ' ')
			return(case_width(text, flag, fill));
		else
			return(case_width_zero(text, flag, fill));
	}
	else
		return(case_no_width(text, flag));
	return(0);
}