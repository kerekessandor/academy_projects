/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:23:38 by azaha             #+#    #+#             */
/*   Updated: 2015/11/13 15:24:37 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef	struct	student
{
	char	first_name[30];
	char	last_name[30];
	char	e_mail[30];
	char	grade[5];
	char	country[20];
}				student;

void	print_students(student student)
{
	if (strcmp(student.country, "Cluj") == 0 && atoi(student.grade) >= 8.00)
		printf("%s %s\n", student.first_name, student.last_name);
}

void	fill_columns(char *to_complete, char *buff, int word_index, int line_index)
{
	to_complete[word_index] = buff[line_index];
	if (buff[line_index + 1] == ';' || buff[line_index + 1] == 0)
		to_complete[word_index + 1] = '\0';
}

void	go_through_file(FILE *fp)
{
	char	buff[255];
	int		buff_index;
	int		word_index;
	int		column;

	while (fscanf(fp, "%s", buff) > 0)
	{
		student student;
		buff_index = 0;
		word_index = 0;
		column = 0;
		while (buff[buff_index] != '\0')
		{
			if (buff[buff_index] == ';')
			{
				column++;
				word_index = 0;
			}
			else
			{
				if (column == 0)
					fill_columns (student.first_name, buff, word_index, buff_index);
				if (column == 1)
					fill_columns (student.last_name, buff, word_index, buff_index);
				if (column == 2)
					fill_columns (student.e_mail, buff, word_index, buff_index);
				if (column == 3)
					fill_columns (student.grade, buff, word_index, buff_index);
				if (column == 4)
					fill_columns (student.country, buff, word_index, buff_index);
				word_index++;
			}
			buff_index++;
		}
		print_students(student);
	}
}


int		main(void)
{
	FILE	*fp;
	fp = fopen("students.csv", "r");
	go_through_file(fp);
	return (0);
}
