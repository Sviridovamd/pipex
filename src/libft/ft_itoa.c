/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:30:48 by wmadison          #+#    #+#             */
/*   Updated: 2021/06/29 17:25:32 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revstring(char *str)
{
	int				i;
	int				size;
	char			c;

	i = 0;
	size = ft_strlen(str) - 1;
	while (i < size)
	{
		c = str[i];
		str[i++] = str[size];
		str[size--] = c;
	}
	return (str);
}

int	ft_size(long long int num)
{
	int				si;

	si = 0;
	if (num < 0)
	{
		num = -num;
		si++;
	}
	if (num == 0)
		return (si += 1);
	while (num > 0)
	{
		num /= 10;
		si++;
	}
	return (si);
}

char	*ft_num_str(long long int n, unsigned int size)
{
	char			*dest;
	int				i;
	long long int	num;

	dest = NULL;
	dest = (char *)malloc(sizeof(char) * 1 + size);
	if (!dest)
		return (NULL);
	if (n < 0)
		num = n * -1;
	else
		num = n;
	i = 0;
	while (num > 0)
	{
		dest[i++] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		dest[i++] = '-';
	else if (n == 0)
		dest[i++] = '0';
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	unsigned int	size;
	char			*numstr;

	numstr = NULL;
	size = ft_size(n);
	numstr = ft_num_str(n, size);
	if (!numstr)
		return (0);
	return (ft_revstring(numstr));
}
