/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quotes_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 13:34:04 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/06 14:22:28 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_delete_quotes(void)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	while (g_mini->command[0][++i])
	{
		if (g_mini->command[0][i] != '"' && g_mini->command[0][i] != '\'')
			j++;
	}
	str = ft_calloc(sizeof(char), j + 1);
	i = 0;
	j = 0;
	while (g_mini->command[0][i])
	{
		if (g_mini->command[0][i] != '"' && g_mini->command[0][i] != '\'')
			str[j++] = g_mini->command[0][i++];
		else
			i++;
	}
	str[j] = '\0';
	free(g_mini->command[0]);
	g_mini->command[0] = ft_strdup(str);
	free(str);
}

void	ft_delete_quotes_param(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != '"' && str[i] != '\'')
			j++;
	}
	s = ft_calloc(sizeof(char), j + 1);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '"' && str[i] != '\'')
			s[j++] = str[i++];
		else
			i++;
	}
	s[j] = '\0';
	free(str);
	str = ft_strdup(s);
	free(s);
}

int	ft_dolar_quotes(char **str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\'')
			{
				ft_double_free(str);
				return (0);
			}
			j++;
		}
		i++;
	}
	ft_double_free(str);
	return (1);
}
