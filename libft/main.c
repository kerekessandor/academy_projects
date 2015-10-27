/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 11:57:58 by azaha             #+#    #+#             */
/*   Updated: 2015/10/27 15:56:16 by azaha            ###   ########.fr       */
/*   Updated: 2015/10/25 17:21:52 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int		main(void)
{
	char s[200] = "**buna****ziua";
	char **matr;
	matr = ft_strsplit(s, '*');
	//while (matr)
	//	printf("%s", *matr);
	return (0);
}
