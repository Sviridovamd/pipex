/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:32:59 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 00:33:01 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		len;
	char	*p;

	len = 0;
	while (src[len] != '\0')
		len++;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		p[len] = src[len];
		len++;
	}
	p[len] = '\0';
	return (p);
}
