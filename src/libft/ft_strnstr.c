/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:33:44 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 00:33:47 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lit_len;

	lit_len = 0;
	lit_len = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (*big && len >= lit_len)
	{
		if (!ft_strncmp(little, big, lit_len) && *little == *big)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
