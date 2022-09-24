/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:27:20 by malasaha          #+#    #+#             */
/*   Updated: 2022/08/30 13:49:57 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	s_cut(char const *s, char c)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c)
			index++;
		else
		{
			count++;
			while (s[index] != '\0' && s[index] != c)
				index++;
		}
	}
	return (count);
}

char	*news_copy(char *newstr, const char *s, int index, int len)
{
	int	count;

	count = 0;
	while (len > 0)
	{
		newstr[count] = s[index - len];
		len--;
		count++;
	}
	newstr[count] = '\0';
	return (newstr);
}

void	*news_split(char **newstr, char const *s, char c, int count)
{
	int	n_index;
	int	n_count;
	int	len;

	n_index = 0;
	n_count = 0;
	len = 0;
	while (n_count < count)
	{
		while (s[n_index] != '\0' && s[n_index] == c)
			n_index++;
		while (s[n_index] != '\0' && s[n_index] != c)
		{
			n_index++;
			len++;
		}
		newstr[n_count] = ft_calloc(sizeof(char), (len + 1));
		if (!newstr[n_count])
			return (NULL);
		news_copy(newstr[n_count], s, n_index, len);
		n_count++;
		len = 0;
	}
	newstr[n_count] = NULL;
	return (newstr[n_count]);
}

char	**ft_split(char const *s, char c)
{
	int		s_say;
	char	**newstr;

	if (s != NULL)
	{
		s_say = s_cut(s, c);
		newstr = ft_calloc(sizeof(char *), (s_say + 1));
		if (!newstr)
		{
			return (NULL);
		}
		news_split(newstr, s, c, s_say);
		return (newstr);
	}
	return (0);
}
