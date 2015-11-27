/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:28:24 by azaha             #+#    #+#             */
/*   Updated: 2015/11/27 19:41:05 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	void	check_modifiers(char **descriptor, t_flag flag)
{
	if (**descriptor == 'h' && *(*descroptor + 1) == 'h')
	{
		flag->has_hh = 1;
		*descriptor++;
	}
	else
		flag->has_h = 1;
}

void	ft_compute_flags(char *descriptor, t_flag flag)
{
	while (*descriptor)
	{
		check_modifiers(&descriptor, &flag);
		descriptor++;
	}
}
