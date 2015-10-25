/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 15:53:12 by azaha             #+#    #+#             */
/*   Updated: 2015/10/25 17:04:59 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t *ptr;

	ptr = NULL;
	if (size == 0)
		return (ptr);
	else
	{
		ptr = (size_t*)malloc(sizeof(size_t) * size);
		ft_bzero(ptr, size);
	}
	return (ptr);
}
