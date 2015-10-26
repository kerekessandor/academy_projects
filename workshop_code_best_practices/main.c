/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 16:44:36 by azaha             #+#    #+#             */
/*   Updated: 2015/10/26 18:18:44 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef	struct	s_struct
{
	char	buff[255];
	char	first_name[20];
    char	last_name[20];
	char	e_mail[20]; 
	char	location[20];
	char	grade[5];
}				student;

int		main(void)
{
	FILE	 *fp;
	int 	index;
	int		word;
	int		letter;

	fp = fopen("students.csv", "r");

	while (fscanf(fp, "%s", buff) > 0)
	{
		index = 0;
		word = 0;
		letter = 0;
		while (buff[index] != 0)
		{
			if (buff[index] == ';')
			{
				word++;
				letter = 0;
			}
			else
			{
				if (word == 0)
				{
					first_name[letter] = buff[index];
					if (buff[index + 1] == ';')
						first_name[letter + 1] = '\0';
				}
				letter++;
			}
			index++;
		}
		if ((strcmp(location, "Cluj") == 0) && atoi(grade) > 8.00)
		{
			printf("%s %s\n", first_name, last_name);
		}
	}
	return (0);
}
