/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:41:22 by malasaha          #+#    #+#             */
/*   Updated: 2022/08/22 12:42:18 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memset(void *str, int a, size_t len)
{
	size_t	count;
	char	*n_str;

	count = 0;
	n_str = (char *)str;
	while (count < len)
	{
		n_str[count] = a;
		count++;
	}
	return (n_str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*b;

	b = (void *)malloc(size * count);
	if (b == NULL)
	{
		return (NULL);
	}
	return (ft_memset (b, 0, (size * count)));
}
