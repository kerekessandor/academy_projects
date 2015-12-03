#include "libft.h"

char	*ft_itoa_base16(unsigned int nbr, const char *trans_table)
{
	char	*new;
	int		i;

	i = 0;
	new = (char*)malloc(sizeof(char) * 30);
	if (nbr == 0)
		new[i++] = '0';
	while (nbr > 0)
	{
		new[i++] = trans_table[nbr % 16];
		nbr /= 16;
	}
	new[i] = '\0';
	new = ft_strrev(new);
	return (new);
}
