/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/24 15:39:46 by azaha             #+#    #+#             */
/*   Updated: 2015/11/06 18:51:23 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t length;

	length = 0;
	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0')
	{
		dst_len++;
		length++;
	}
	while (src[src_len] != '\0')
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
		length++;
	}
	if (size < dst_len)
		return (size + src_len);
	else
		return (length);
}
