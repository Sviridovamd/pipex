/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:31:13 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 16:31:16 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n > 0)
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
