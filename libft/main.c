/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 11:57:58 by azaha             #+#    #+#             */
/*   Updated: 2015/10/24 20:04:41 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char a[200] = "asdasdadala";
	char b[200] = "l";
	char c[200] = "asdasdasddala";
	char d[200] = "l";
	printf("%s\n", strnstr(a, b, 20));
	printf("%s\n", ft_strnstr(c, d, 20));
	return (0);
}
