/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:31:32 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 16:31:35 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count;
	size_t	len;
	size_t	len2;

	len = 0;
	count = ft_strlen(src);
	while (len < size && *dst)
	{
		len++;
		dst++;
	}
	len2 = len;
	if (size != 0)
	{
		while (*src && len < size - 1)
		{
			*dst = *src;
			dst++;
			src++;
			len++;
		}
	}
	if (len < size)
		*dst = '\0';
	return (count + len2);
}
