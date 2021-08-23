/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:35:53 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 00:35:56 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	if ((size_t)ft_strlen((char *)s) > start)
	{
		while (len > 0)
		{
			substring[i] = s[start + i];
			i++;
			len--;
		}
	}
	substring[i] = '\0';
	return (substring);
}
