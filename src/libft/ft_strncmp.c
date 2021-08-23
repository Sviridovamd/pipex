/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:33:38 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 00:33:40 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	if (num == 0)
		return (0);
	while ((*string1 || *string2) && num > 0)
	{
		if (*string1 != *string2)
			return ((unsigned char)*string1 - (unsigned char)*string2);
		string1++;
		string2++;
		num--;
	}
	return (0);
}
