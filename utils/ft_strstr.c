/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 12:31:03 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/05 17:47:56 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strstr(char *s1, char *s2)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	if (s2[i] == '\0')
	{
		return ((char *)s1);
	}
	while (s1[i] != '\0')
	{
		c = 0;
		while (s2[c] && s1[i + c] == s2[c])
		{
			c++;
		}
		if (s2[c] == '\0')
		{
			return ((char *)(s1 + i + c));
		}
		i++;
	}
	return (NULL);
}

int	ft_is_dolar_question_mark(char *s1, char *s2)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	while (s1[i] != '\0')
	{
		c = 0;
		while (s2[c] && s1[i + c] == s2[c])
			c++;
		if (s2[c] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strstr2(char *s1, char *s2)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	if (s2[i] == '\0')
	{
		return ((char *)s1);
	}
	while (s1[i] != '\0')
	{
		c = 0;
		while (s2[c] && s1[i + c] == s2[c])
		{
			c++;
		}
		if (s2[c] == '\0')
		{
			return ((char *)(s1 + i + c + 1));
		}
		i++;
	}
	return (NULL);
}
