/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:26:56 by malasaha          #+#    #+#             */
/*   Updated: 2022/08/30 13:43:03 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strtrim(char *s1, char *set)
{
	size_t	index;
	size_t	s1_len;
	int		count;
	char	*dest;

	if (s1 != NULL)
	{
		s1_len = ft_strlen(s1);
		index = 0;
		while (s1[index] != '\0' && ft_strchr(set, s1[index]))
			index++;
		while (s1_len > index && ft_strchr(set, s1[s1_len - 1]))
			s1_len--;
		dest = ft_calloc(sizeof(char), (s1_len - index + 1));
		if (!dest)
			return (NULL);
		count = 0;
		while (index < s1_len)
			dest[count++] = s1[index++];
		dest[count] = '\0';
		free(s1);
		return (dest);
	}
	return (0);
}
