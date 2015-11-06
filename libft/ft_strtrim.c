/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 14:05:59 by azaha             #+#    #+#             */
/*   Updated: 2015/11/06 18:52:53 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strtrim(char const *s)
{
	char	*ptr;
	char	*aux;
	size_t	i;

	ptr = (char*)s;
	while (*ptr == ' ' || *ptr == '\n' || *ptr == '\t')
		ptr++;
	aux = ptr;
	i = ft_strlen(ptr) - 1;
	while (*(aux + i) == ' ' || *(aux + i) == '\n' || *(aux + i) == '\t')
		i--;
	ptr = (char*)malloc(sizeof(char) * (i + 1));
	ptr = aux;
	*(ptr + i + 1) = '\0';
	return (ptr);
}
