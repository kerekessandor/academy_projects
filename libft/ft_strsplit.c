/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 15:17:10 by azaha             #+#    #+#             */
/*   Updated: 2015/10/27 17:29:34 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**matrix;
	size_t	nr_of_lines;
	size_t	word_length;
	size_t	index;

	index = 0;
	word_length = 1;
	nr_of_lines = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			while (*s != c)
			{
				word_length++;
				s++;
			}
			*(matrix + index) = (char**)malloc(sizeof(char) * word_length);
			while (word_length > 0)
			{
				**matrix = *(s - word_length);
				*matrix++;
				word_length--;
			}
			index++;
		}
		s++;
		nr_of_lines++;
	}
	matrix = (char*)malloc(sizeof(char) * nr_of_lines);
	
	return (matrix);
}
