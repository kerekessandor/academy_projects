/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 12:05:34 by azaha             #+#    #+#             */
/*   Updated: 2015/11/08 15:02:43 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*rez;
	size_t	size;

	size = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(rez = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	else
		rez = ft_strcat((char*)s1, (char*)s2);
	return (rez);
}
