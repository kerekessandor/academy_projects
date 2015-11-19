/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/19 13:48:37 by azaha             #+#    #+#             */
/*   Updated: 2015/11/19 14:02:00 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 1)
		return (0);
	*argv = NULL;
	fd = 0;
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	close(fd);
	return (0);
}
