#include "libft.h"

char	*ft_itoa_base(unsigned int nbr, const char *table, int base)
{
	char	*new;
	int		i;

	i = 0;
	new = (char*)malloc(sizeof(char) * 30);
	if (nbr == 0)
		new[i++] = '0';
	while (nbr > 0)
	{
		new[i++] = table[nbr % base];
		nbr /= base;
	}
	new[i] = '\0';
	new = ft_strrev(new);
	return (new);
}
