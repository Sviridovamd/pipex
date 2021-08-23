/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:33:32 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 00:49:18 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	size;
	char			*newstr;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	newstr = (char *)malloc(sizeof(char) * size + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		newstr[i] = f(i, *s);
		s++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
