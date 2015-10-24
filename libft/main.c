/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 11:57:58 by azaha             #+#    #+#             */
/*   Updated: 2015/10/24 16:42:06 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char a[200] = "alandala";
	//char b[200] = "ziua";
	//char c[200] = "buna";
	//char d[200] = "ziua";
	printf("%s\n", strchr(a, 'd'));
	//printf("%s\n", ft_strlcat(c, d, 3));
	return (0);
}
