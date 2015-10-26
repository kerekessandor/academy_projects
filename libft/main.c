/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 11:57:58 by azaha             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/10/26 15:43:57 by azaha            ###   ########.fr       */
=======
/*   Updated: 2015/10/25 17:21:52 by azaha            ###   ########.fr       */
>>>>>>> edb4c5ddc614812effcc6673dab657f12650fdb7
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int		main(void)
{
<<<<<<< HEAD
	//char a[200] = "nimic";
=======
	char a[200] = "nimic";
>>>>>>> edb4c5ddc614812effcc6673dab657f12650fdb7
	//char b[200];
	//char c[200];
	//char d[200];
	
<<<<<<< HEAD
	//printf("%zu\n", ft_strlen(a));
=======
	printf("%zu\n", ft_strlen(a));
>>>>>>> edb4c5ddc614812effcc6673dab657f12650fdb7
	//printf("%d\n", ft_memcmp(a, c, 1));
	
	char *ptr;
	ptr = NULL;
<<<<<<< HEAD
	//ptr = ft_memalloc(ft_strlen(a));
	//printf("%s\n", ptr);
	ft_memdel((void*)&ptr);
=======
	ptr = ft_memalloc(ft_strlen(a));
	printf("%s\n", ptr);
	ft_memdel(&ptr);
>>>>>>> edb4c5ddc614812effcc6673dab657f12650fdb7
	return (0);
}
