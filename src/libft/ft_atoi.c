/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:29:55 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 00:30:04 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	n;
	int	num;

	i = 0;
	n = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9' && str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * n);
}
