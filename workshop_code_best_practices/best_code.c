/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:23:38 by azaha             #+#    #+#             */
/*   Updated: 2015/11/13 18:08:18 by azaha            ###   ########.fr       */
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
	char	county[20];
}				student;

void	print_students(student student)
{
	if (strcmp(student.county, "Cluj") == 0 && atoi(student.grade) >= 8.00)
		printf("%s %s\n", student.first_name, student.last_name);
}

void	fill_columns(char *to_complete, char *buff, int word_index, int buff_index)
{
	to_complete[word_index] = buff[buff_index];
	if (buff[buff_index + 1] == ';' || buff[buff_index + 1] == 0)
		to_complete[word_index + 1] = '\0';
}

int		is_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		is_number(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int		check_word(char *word, int *valid_student)
{
	while (*word)
	{
		if (is_alpha(*word) == 0)
			*valid_student = 0;
		word++;
	}
	return (*valid_student);
}

int		check_e_mail(char *e_mail, int *valid_student)
{
	int	is_valid = 0;

	while (*e_mail)
	{
		if (*e_mail == '@')
			is_valid++;
		if (*e_mail == '.')
			is_valid++;
		e_mail++;
	}
	if(is_valid != 2)
		*valid_student = 0;
	return (*valid_student);
}

int		check_grade(char *grade, int *valid_student)
{
	int points = 0;

	while (*grade)
	{
		if (*grade == '.')
			points++;
		else if (is_number(*grade) == 0)
			*valid_student = 0;
		grade++;
	}
	if (points > 1)
		*valid_student = 0;
	return (*valid_student);
}

void	go_through_file(FILE *fp)
{
	char	buff[255];
	int		buff_index;
	int		word_index;
	int		column;
	int		valid_student;

	while (fscanf(fp, "%s", buff) > 0)
	{
		student student;
		buff_index = 0;
		word_index = 0;
		column = 0;
		valid_student = 1;
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
					fill_columns (student.county, buff, word_index, buff_index);
				word_index++;
			}
			buff_index++;
		}
		check_word(student.first_name, &valid_student);
		check_word(student.last_name, &valid_student);
		check_e_mail(student.e_mail, &valid_student);
		check_word(student.county, &valid_student);
		check_grade(student.grade, &valid_student);
		if(valid_student == 1)
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
