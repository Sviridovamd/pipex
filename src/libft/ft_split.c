/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:32:46 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 00:32:48 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **mas, int i)
{
	i--;
	while (i >= 0)
	{
		free(mas[i]);
		i--;
	}
	free(mas);
	return (NULL);
}

static int	ft_check_sep(char const *s, char c)
{
	int		flag;
	int		count;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (flag == 0 && *s != c)
		{
			flag = 1;
			count++;
		}
		if (flag == 1 && *s == c)
		{
			flag = 0;
		}
		s++;
	}
	return (count);
}

static int	ft_l(char const *s, char c)
{
	int		l;

	l = 0;
	while (*s && *s != c)
	{
		l++;
		s++;
	}
	return (l);
}

static char	**ft_creat_mas(char **mas, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
			{
				mas[i] = (char *)malloc(sizeof(char) * (ft_l(s, c) + 1));
				if (!mas[i])
					return (ft_free(mas, i));
				j = 0;
				while (*s && *s != c)
					mas[i][j++] = *s++;
			}
			mas[i++][j] = '\0';
		}
		else
			s++;
	}
	mas[i] = NULL;
	return (mas);
}

char	**ft_split(char const *s, char c)
{
	char	**mas;
	char	**mas2;

	if (!s)
		return (0);
	mas = (char **)malloc(sizeof(char *) * (ft_check_sep(s, c) + 1));
	if (!mas)
		return (0);
	mas2 = ft_creat_mas(mas, s, c);
	return (mas2);
}
