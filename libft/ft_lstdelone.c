/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azaha <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 12:41:54 by azaha             #+#    #+#             */
/*   Updated: 2015/11/10 15:02:44 by azaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void(*del)(void*, size_t))
{
	del(&((*alst)->content), (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
