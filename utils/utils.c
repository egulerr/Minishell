/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:41:30 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/06 15:01:31 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cpyenv(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	g_mini->env = ft_calloc(sizeof(char *), (i + 1));
	i = 0;
	while (env[i])
	{
		g_mini->env[i] = ft_strdup(env[i]);
		i++;
	}
	g_mini->env[i] = NULL;
	ft_addenv();
}

void	ft_cpyexport(char **env)
{
	int		i;
	char	*temp;
	char	*buff;

	i = 0;
	while (env[i])
		i++;
	g_mini->export = ft_calloc(sizeof(char *), (i + 1));
	i = 0;
	while (env[i])
	{
		g_mini->export[i] = ft_strdup(env[i]);
		i++;
	}
	g_mini->export[i] = NULL;
	i = 0;
	while (g_mini->export[i])
	{
		temp = ft_export_allocation(g_mini->export[i]);
		buff = ft_add_quotes(g_mini->export[i]);
		free(g_mini->export[i]);
		g_mini->export[i] = ft_strjoin(temp, buff);
		free(buff);
		i++;
	}
}

void	ft_free_cpyenv(char	**env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	g_mini->env = ft_calloc(sizeof(char *), (i + 1));
	i = 0;
	while (env[i])
	{
		g_mini->env[i] = ft_strdup(env[i]);
		i++;
	}
	g_mini->env[i] = NULL;
	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

char	**ft_env_cpy(char **env)
{
	int		i;
	char	**arr;

	i = 0;
	while (env[i])
		i++;
	arr = ft_calloc(sizeof(char *), (i + 1));
	i = 0;
	while (env[i])
	{
		arr[i] = ft_strdup(env[i]);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
