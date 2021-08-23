/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:35:37 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 00:50:45 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*buf;

	buf = NULL;
	while (*str)
	{
		if (*str == ch)
			buf = (char *)(str);
		str++;
	}
	if (!ch)
		return ((char *)(str));
	return (buf);
}
