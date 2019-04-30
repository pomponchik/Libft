/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_fix_width_of_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 22:51:56 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/30 21:32:45 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fix_join_width(char *str, char filler, size_t len, char *flags)
{
	size_t	different;
	size_t	half;
	size_t	size;

	size = ft_strlen(str);
	different = len - size;
	half = different / 2;
	if (flags && (ft_strstr(flags, "alignment: right") \
	|| ft_strstr(flags, "align: right")))
		return (ft_strjoin_free_2(str, ft_strnew_filler(different, filler)));
	if (flags && (ft_strstr(flags, "alignment: left") \
	|| ft_strstr(flags, "align: left")))
		return (ft_strjoin_free_1(ft_strnew_filler(different, filler), str));
	if (half)
		str = ft_strjoin_free_1(ft_strnew_filler(half, filler), str);
	if ((half = different - half))
		str = ft_strjoin_free_both(str, ft_strnew_filler(half, filler));
	return (str);
}

static char	*ft_fix_crop_begin(char *str, size_t len, size_t size)
{
	char	*result;

	ft_mem_reverse(str, 1, size);
	if (!(result = ft_strdup_n(str, len)))
	{
		//ft_mem_reverse(str, 1, size);
		return (NULL);
	}
	// ft_mem_reverse(result, 1, len);
	// ft_mem_reverse(str, 1, len);
	return (result);
}

char		*ft_str_fix_width_of_line(char *str, char filler, \
	size_t len, char *flags)
{
	size_t	size;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	if (len > size)
		return (ft_fix_join_width(str, filler, len, flags));
	if (len < size)
	{
		if (flags && ft_strstr(flags, "crop: begin"))
			return (ft_fix_crop_begin(str, len, size));
		if (flags && (ft_strstr(flags, "crop: no") || \
		ft_strstr(flags, "not crop")))
			return (str);
		return (ft_strdup_n(str, len));
	}
	return (str);
}
