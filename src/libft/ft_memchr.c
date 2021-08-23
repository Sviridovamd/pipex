/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:31:06 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 16:31:09 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;
	char	*src;

	src = (char *)s;
	count = 0;
	while (count < n)
	{
		if (src[count] == c)
			return ((void *)(src + count));
		count++;
	}
	return (NULL);
}
