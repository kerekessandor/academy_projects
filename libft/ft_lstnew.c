/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 17:49:02 by azaha             #+#    #+#             */
/*   Updated: 2015/11/08 18:34:13 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_node;

	if (!(new_node = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	else
	{
		if (content_size != 0)
		{
			new_node->content = (void*)malloc(content_size);
			ft_memcpy(new_node->content, content, content_size);
			new_node->content_size = content_size;
			new_node->next = NULL;
		}
		else
		{
			new_node->content = NULL;
			new_node->content_size = 0;
			new_node->next = NULL;
		}
	}
	return (new_node);
}

int		main(void)
{
	long unNumar = 5432;
	t_list *unNod = ft_lstnew(&unNumar, sizeof(long));
	unNumar = 41234;
	printf("content value: %lu\n", *((long*)unNod->content));
	return (0);
}
