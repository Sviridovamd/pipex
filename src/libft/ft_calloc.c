/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmadison <wmadison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:27:40 by wmadison          #+#    #+#             */
/*   Updated: 2020/11/13 16:27:41 by wmadison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	size *= nmemb;
	memory = (void *)malloc(size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
