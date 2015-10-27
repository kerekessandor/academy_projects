/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 11:41:31 by azaha             #+#    #+#             */
/*   Updated: 2015/10/27 15:11:31 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*rez;
	size_t	index;

	index = 0;
	if (start < ft_strlen(s) && len <= (ft_strlen(s) - start))
	{
		rez = (char*)malloc(sizeof(char) * (len + 1));
		while (index < len)
		{
			*(rez + index) = *(s + start + index);
			index++;
		}
	}
	else
		rez = NULL;
	return (rez);
}
