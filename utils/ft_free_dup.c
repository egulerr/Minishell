/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:39:09 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/06 14:43:39 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_free_dup(char *str)
{
	int		count;
	int		index;
	char	*arr;

	count = ft_strlen(str);
	arr = ft_calloc(sizeof(char), (count + 1));
	if (!arr)
	{
		return (0);
	}
	index = 0;
	while (index < count)
	{
		arr[index] = str[index];
		index++;
	}
	arr[index] = '\0';
	free(str);
	return (arr);
}
