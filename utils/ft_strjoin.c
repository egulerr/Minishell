/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:26:25 by malasaha          #+#    #+#             */
/*   Updated: 2022/08/30 13:41:48 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		index;
	int		count;
	char	*arr;
	size_t	len;

	index = 0;
	count = 0;
	if (s1 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		arr = ft_calloc(sizeof(char), len);
		if (arr == NULL)
			return (0);
		while (s1[index] != '\0')
			arr[count++] = s1[index++];
		index = 0;
		while (s2[index] != '\0')
			arr[count++] = s2[index++];
		arr[count] = '\0';
		free(s1);
		return (arr);
	}
	return (0);
}
