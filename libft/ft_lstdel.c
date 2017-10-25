/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:54:45 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/13 10:39:13 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	void *getnext;

	while (*alst)
	{
		getnext = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = getnext;
	}
	*alst = NULL;
}
