/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 11:57:58 by azaha             #+#    #+#             */
/*   Updated: 2015/11/06 18:26:31 by azaha            ###   ########.fr       */
/*   Updated: 2015/10/27 15:56:16 by azaha            ###   ########.fr       */
/*   Updated: 2015/10/25 17:21:52 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void	ft_upper(unsigned int index, char *c)
{
	while (*c)
	{
		*c = *c - 32 + index;
		c++;
		index++;
	}
}

int		main()
{
	char *s = "nimic";
	ft_striteri(s, &ft_upper);
	printf("%s\n",s);
	
	return (0);
}
