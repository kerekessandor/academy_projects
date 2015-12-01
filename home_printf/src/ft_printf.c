#include "../includes/ft_printf.h"

static	void	check_descriptor_validity(char *descriptor, va_list *ap, int *chrs)
{
	int length;

	length = ft_strlen(descriptor);
	if (ft_strchr(IDENTIFIERS, descriptor[length - 1]))
		*chrs += process_descriptor(descriptor, ap);
}

static	int		get_dsc_len(const char *format)
{
	unsigned int dsc_len;

	dsc_len = 1;
	if (format[dsc_len] == '\0')
		return (0);
	while (ft_strchr(FLAGS, format[dsc_len]) && format[dsc_len] != '\0')
		dsc_len++;
	if (ft_strchr(IDENTIFIERS, format[dsc_len]) && format[dsc_len] != '\0')
		return (dsc_len + 1);
	else if (format[dsc_len] == '%' && format[dsc_len - 1] == '%')
		return (dsc_len);
	else
		return (dsc_len);
}

static	int		go_through_format(const char *format, va_list *ap)
{
	int		chrs;
	int		dsc_len;
	char	*descriptor;

	chrs = 0;
	while (*format)
		if (*format == '%')
		{
			if ((dsc_len = get_dsc_len(format)) > 0)
			{
				descriptor = ft_strsub(format, 0, dsc_len);
				check_descriptor_validity(descriptor, ap, &chrs);
				format += dsc_len;
			}
			else
				format++;
		}
		else
		{
			ft_putchar(*format);
			chrs++;
			format++;
		}
	return (chrs);
}

int				ft_printf(const char *format, ...)
{
	va_list ap;
	int chrs;

	chrs = 0;
	va_start(ap, format);
	chrs = go_through_format(format, &ap);
	va_end(ap);
	return (chrs);
}