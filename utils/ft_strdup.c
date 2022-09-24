/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:36:36 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/01 16:49:34 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(char *str)
{
	int		count;
	int		index;
	char	*arr;

	count = ft_strlen(str);
	arr = malloc(sizeof(char) * (count + 1));
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
	return (arr);
}
