/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 15:35:01 by azaha             #+#    #+#             */
/*   Updated: 2015/11/10 16:13:08 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new_node;
	t_list *link;

	new_node = NULL;
	link = NULL;
	while (lst != NULL)
	{
		if (new_node == NULL)
		{
			new_node = f(lst);
			link = new_node;
		}
		else
		{
			link->next = f(lst);
		}
	}
	return (new_node);
}
