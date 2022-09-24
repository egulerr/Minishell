/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_delete_2_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:53:32 by eguler            #+#    #+#             */
/*   Updated: 2022/09/09 16:22:23 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_quotes_malloc_flag2(char *str)
{
	int	i;
	int	j;
	int	count;
	int	len;

	len = 0;
	count = 0;
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '\"')
			count++;
		while (str[j] && str[j] != '=')
		{
			len++;
			j++;
		}
		i++;
	}
	return (count - len - 1);
}

int	ft_quotes_malloc_flag3(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (str[i] != '\"')
			count++;
		i++;
	}
	return (count + 1);
}

char	*ft_return_equal_2(char *str, char *command)
{
	int		i;
	int		j;
	char	*s;

	s = ft_calloc(sizeof(char), ft_len_for_malloc(command, 3) + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			i++;
		else
			s[j++] = command[i++];
	}
	s[j] = '\0';
	return (s);
}

char	*ft_return_equal_com(char *com)
{
	int		x;
	int		i;
	char	*command;

	i = 0;
	x = 0;
	while (com[i])
	{
		if (com[i] != '\"' && com[i] != '\'')
			x++;
		i++;
	}
	command = ft_calloc(sizeof(char), x + 1);
	i = 0;
	x = 0;
	while (com[i])
	{
		if (com[i] != '\"' && com[i] != '\'')
			command[x++] = com[i];
		i++;
	}
	free(com);
	return (command);
}
