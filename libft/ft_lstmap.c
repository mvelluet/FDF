/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelluet <mvelluet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 20:40:28 by mvelluet          #+#    #+#             */
/*   Updated: 2016/11/13 10:38:17 by mvelluet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;

	temp = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	temp = (*f)(lst);
	if (temp && lst->next)
		temp->next = ft_lstmap(lst->next, f);
	return (temp);
}
