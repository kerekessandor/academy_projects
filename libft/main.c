/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 11:57:58 by azaha             #+#    #+#             */
/*   Updated: 2015/10/25 17:21:52 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char a[200] = "nimic";
	//char b[200];
	//char c[200];
	//char d[200];
	
	printf("%zu\n", ft_strlen(a));
	//printf("%d\n", ft_memcmp(a, c, 1));
	
	char *ptr;
	ptr = NULL;
	ptr = ft_memalloc(ft_strlen(a));
	printf("%s\n", ptr);
	ft_memdel(&ptr);
	return (0);
}
