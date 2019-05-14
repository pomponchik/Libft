/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin_counter_out.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:20:29 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/14 16:33:46 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin_counter_out(t_list *lst, size_t *counter)
{
	char	*result;
	void	*temp;
	size_t	size;

	if (!lst || !(result = (char *)malloc(ft_lst_strlen(lst) + 1)))
		return (NULL);
	temp = (void *)result;
	*counter = 0;
	while (lst)
	{
		size = ft_strlen((char *)lst->content);
		*counter += size;
		ft_memcpy(temp, lst->content, size);
		temp = ft_jump_pointer_size_t(temp, size);
		lst = lst->next;
	}
	result[*counter] = '\0';
	return (result);
}