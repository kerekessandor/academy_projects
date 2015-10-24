/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 11:57:58 by azaha             #+#    #+#             */
/*   Updated: 2015/10/24 20:31:39 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char a[200] = "axb";
	char b[200] = "ax";
	//char c[200] = "asdasdasddala";
	//char d[200] = "l";
	printf("%d\n", strncmp(a, b, 3));
	printf("%d\n", ft_strncmp(a, b, 3));
	return (0);
}
