/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:30:58 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 16:31:00 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*buf;
	const char	*s;
	char		ch;

	buf = dest;
	ch = c;
	s = src;
	while (n > 0)
	{
		if (*s == ch)
		{
			*buf = *s;
			buf++;
			return ((void *)buf);
		}
		*buf = *s;
		buf++;
		s++;
		n--;
	}
	return (0);
}
