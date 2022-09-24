/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:01:07 by eguler            #+#    #+#             */
/*   Updated: 2022/09/20 23:37:40 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_control(int a)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (g_mini->command[a][i])
	{
		if (g_mini->command[a][i] == '=')
			flag++;
		i++;
	}
	if (flag > 0)
		return (1);
	else
		return (0);
}

int	ft_env_check(int a)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (g_mini->command[a][len] && g_mini->command[a][len] != '=')
		len++;
	while (g_mini->env[i])
	{
		if (!ft_strncmp(g_mini->env[i], g_mini->command[a], len))
		{
			if (g_mini->env[i][len] == '=')
			{
				g_mini->env_flag = i;
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	ft_export_check(int a)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (g_mini->command[a][len] && g_mini->command[a][len] != '=')
		len++;
	while (g_mini->export[i])
	{
		if (!ft_strncmp(g_mini->export[i], g_mini->command[a], len))
		{
			if (g_mini->export[i][len] == '\0' || g_mini->export[i][len] == '=')
			{
				g_mini->export_flag = i;
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	ft_numeric_cont(int a)
{
	if ((g_mini->command[a][0] >= 'a' && g_mini->command[a][0] <= 'z') || \
		(g_mini->command[a][0] >= 'A' && g_mini->command[a][0] <= 'Z') || \
		(g_mini->command[a][0] == '_'))
	{
		return (1);
	}
	return (0);
}

int	ft_quotes_check(int index)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while (g_mini->command[index][j])
	{
		if (g_mini->command[index][j] == '\"')
			count++;
		j++;
	}
	if (count > 0)
		return (1);
	return (0);
}
