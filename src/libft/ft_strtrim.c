/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:35:44 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 00:35:49 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(const char *set, char s1)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*newstr;

	start = 0;
	end = 0;
	len = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (ft_set(set, s1[start]) && s1[start])
		start++;
	while (ft_set(set, s1[end]) && end > start)
		end--;
	newstr = (char *)malloc(end - start + 2);
	if (!newstr)
		return (NULL);
	while (start < end + 1)
		newstr[len++] = s1[start++];
	newstr[len] = '\0';
	return (newstr);
}
