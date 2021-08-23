/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:33:06 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 00:45:10 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	sizes1;
	size_t	size;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	sizes1 = ft_strlen(s1);
	size = sizes1 + ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * size + 1);
	if (!new)
		return (NULL);
	while (i < sizes1)
	{
		new[i] = *s1++;
		i++;
	}
	while (i < size)
	{
		new[i] = *s2++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
