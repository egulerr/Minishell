/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:56:42 by eguler            #+#    #+#             */
/*   Updated: 2022/09/20 23:37:01 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_add_quotes(char *export)
{
	int		i;
	char	*str;

	i = 0;
	while (export[i])
	{
		if (export[i] == '=')
			break ;
		i++;
	}
	str = ft_strjoin(ft_strdup("\""), export + i + 1);
	str = ft_strjoin(str, "\"");
	return (str);
}

char	*ft_export_allocation(char *str)
{
	int		i;
	char	*arr;

	i = 0;
	while (str && str[i] && str[i] != '=')
		i++;
	arr = ft_calloc(sizeof(char), i + 2);
	i = 0;
	while (str && str[i] && str[i] != '=')
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '=';
	i++;
	arr[i] = '\0';
	return (arr);
}

void	ft_sort_export(void)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (g_mini->export[i])
	{
		j = 0;
		while (g_mini->export[j])
		{
			if (g_mini->export[i][0] < g_mini->export[j][0])
			{
				temp = ft_strdup(g_mini->export[i]);
				free(g_mini->export[i]);
				g_mini->export[i] = ft_strdup(g_mini->export[j]);
				free(g_mini->export[j]);
				g_mini->export[j] = ft_strdup(temp);
				free(temp);
			}
			j++;
		}
		i++;
	}
	free(g_mini->export[i - 1]);
	g_mini->export[i - 1] = NULL;
}

void	ft_sortenv(void)
{
	int		i;
	char	*buff;

	i = 0;
	while (g_mini->cpyenv[i])
		i++;
	buff = g_mini->cpyenv[i - 1];
	g_mini->cpyenv[i - 1] = g_mini->cpyenv[i - 2];
	g_mini->cpyenv[i - 2] = buff;
	i = 0;
	while (g_mini->env[i])
		i++;
	buff = g_mini->env[i - 1];
	g_mini->env[i - 1] = g_mini->env[i - 2];
	g_mini->env[i - 2] = buff;
}

void	ft_addenv(void)
{
	int		i;

	if (g_mini->cpyenv != NULL)
		ft_double_free(g_mini->cpyenv);
	i = 0;
	while (g_mini->env[i])
		i++;
	g_mini->cpyenv = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (g_mini->env[i])
	{
		g_mini->cpyenv[i] = ft_strdup(g_mini->env[i]);
		ft_delete_quotes_param(g_mini->cpyenv[i]);
		i++;
	}
	g_mini->cpyenv[i] = NULL;
	ft_sortenv();
}
