/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 14:23:38 by azaha             #+#    #+#             */
/*   Updated: 2015/11/13 19:02:17 by azaha            ###   ########.fr       */
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
		printf("\033[32;1m%s %s has grade bigger than or equal to 8.\033[0m\n", student.first_name, student.last_name);
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

int		check_first_name(student student, int *valid_student)
{
	int index = 0;

	while (student.first_name[index])
	{
		if (is_alpha(student.first_name[index]) == 0)
			*valid_student = 0;
		index++;
	}
	if (*valid_student == 0)
		printf("\033[31;1m%s is not a valid first name.\033[0m\n", student.first_name);
	return (*valid_student);
}

int		check_last_name(student student, int *valid_student)
{
	int index = 0;

	while (student.last_name[index])
	{
		if (is_alpha(student.last_name[index]) == 0)
			*valid_student = 0;
		index++;
	}
	if (*valid_student == 0)
		printf("\033[31;1m%s is not a valid last name.\033[0m\n", student.last_name);
	return (*valid_student);
}

int		check_county(student student, int *valid_student)
{
	int index = 0;
	
	while (student.county[index])
	{
		if (is_alpha(student.county[index]) == 0)
			*valid_student = 0;
		index++;
	}
	if (*valid_student == 0)
		printf("\033[31;1m%s is not a valid county.\033[0m\n", student.county);
	return(*valid_student);

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

int		check_grade(student student, int *valid_student)
{
	int points = 0;
	int index = 0;

	while (student.grade[index])
	{
		if (student.grade[index] == '.')
			points++;
		else if (is_number(student.grade[index]) == 0)
			*valid_student = 0;
		index++;
	}
	if (points > 1)
		*valid_student = 0;
	if (*valid_student == 0)
		printf("\033[31;1m%s %s does not have a valid grade.\033[0m\n", student.first_name, student.last_name);
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
		check_first_name(student, &valid_student);
		check_last_name(student, &valid_student);
		check_e_mail(student.e_mail, &valid_student);
		check_county(student, &valid_student);
		check_grade(student, &valid_student);
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

// \033[31;1m ... \033[0m
