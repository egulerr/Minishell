/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 13:01:31 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/06 16:13:40 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env_add(int a)
{
	int		i;
	char	*buff;
	char	*temp;

	i = 0;
	buff = ft_merge(g_mini->env);
	while (g_mini->env[i])
		free(g_mini->env[i++]);
	free(g_mini->env);
	buff = ft_strjoin(buff, " ");
	buff = ft_export_add_3(buff, g_mini->command[a]);
	temp = buff;
	g_mini->env = ft_split_quote(buff, ' ');
	free(temp);
	ft_addenv();
}

void	ft_env_update(int a)
{
	free(g_mini->env[g_mini->env_flag]);
	g_mini->env[g_mini->env_flag] = ft_strdup(g_mini->command[a]);
	ft_addenv();
}

void	ft_export_add(int a)
{
	int		i;
	char	*buff;
	char	*temp;

	i = 0;
	buff = ft_merge(g_mini->export);
	while (g_mini->export[i])
		free(g_mini->export[i++]);
	free(g_mini->export);
	buff = ft_strjoin(buff, " ");
	buff = ft_export_add_3(buff, g_mini->command[a]);
	temp = buff;
	g_mini->export = ft_split_quote(buff, ' ');
	free(temp);
}

void	ft_export_add_2(int a)
{
	int		i;
	char	*buff;
	char	*temp;

	i = 0;
	buff = ft_merge(g_mini->export);
	while (g_mini->export[i])
		free(g_mini->export[i++]);
	free(g_mini->export);
	buff = ft_strjoin(buff, " ");
	buff = ft_export_add_4(buff, g_mini->command[a]);
	temp = buff;
	g_mini->export = ft_split_quote(buff, ' ');
	free(temp);
}

void	ft_export_update(int a)
{
	char	*s;

	s = ft_calloc(sizeof(char), 1);
	free(g_mini->export[g_mini->export_flag]);
	s = ft_export_add_3(s, g_mini->command[a]);
	g_mini->export[g_mini->export_flag] = ft_strdup(s);
	free(s);
}
