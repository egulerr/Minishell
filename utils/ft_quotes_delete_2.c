/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_delete_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:35:50 by eguler            #+#    #+#             */
/*   Updated: 2022/09/09 16:22:17 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_len_for_malloc(char *str, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (str[i])
		{
			if (str[i] == '=')
				break ;
			i++;
		}
		return (i + 1);
	}
	if (flag == 2)
		return (ft_quotes_malloc_flag2(str));
	if (flag == 3)
		return (ft_quotes_malloc_flag3(str));
	return (0);
}

char	*ft_return_equal(char *command)
{
	int		i;
	int		j;
	char	*str;
	char	*s;

	j = 0;
	i = 0;
	str = ft_calloc(sizeof(char), ft_len_for_malloc(command, 1) + 1);
	while (command[i])
	{
		str[j++] = command[i];
		if (command[i] == '=')
			break ;
		i++;
	}
	j++;
	str[j] = '\0';
	s = ft_return_equal_2(str, command);
	free(str);
	return (s);
}

char	*ft_return_string(char *command)
{
	int		i;
	int		j;
	char	*str;

	str = ft_calloc(sizeof(char), ft_len_for_malloc(command, 2) + 1);
	i = 0;
	while (command[i] != '=')
		i++;
	i++;
	j = 0;
	while (command[i])
	{
		if (command[i] == '\"')
			i++;
		else
			str[j++] = command[i++];
	}
	str[j] = '\0';
	return (str);
}

char	*ft_delete_quotes_ey(char *command)
{
	char	*str;
	char	*s;

	s = ft_return_equal(command);
	str = ft_return_string(command);
	free(command);
	s = ft_strjoin(s, "\"");
	s = ft_strjoin(s, str);
	s = ft_strjoin(s, "\"");
	free(str);
	return (s);
}
