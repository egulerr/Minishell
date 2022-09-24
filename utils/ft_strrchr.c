/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:26:42 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/06 14:45:09 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strrchr(char *s, int c)
{
	int	count;

	count = ft_strlen(s);
	if (c == '\0')
	{
		return ((char *)&s[count]);
	}
	count--;
	while (count >= 0)
	{
		if (s[count] == c)
		{
			return ((char *)&s[count + 1]);
		}
		count--;
	}
	return (NULL);
}
