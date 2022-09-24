/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:10:18 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/07 12:32:03 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(void)
{
	int		flag;

	flag = 0;
	if (!(g_mini->new_pwd && g_mini->old_pwd))
		flag = 1;
	if (g_mini->command[1] == NULL)
	{
		free(g_mini->old_pwd);
		g_mini->old_pwd = getcwd(NULL, 0);
		chdir(getenv("HOME"));
		free(g_mini->new_pwd);
		g_mini->new_pwd = getcwd(NULL, 0);
	}
	else if (g_mini->command[1][0] == '-')
		ft_dash();
	else
		ft_dot_or_twodots();
	if (flag != 1)
		ft_updates();
}

void	ft_updatexport(void)
{
	int	i;

	i = 0;
	while (g_mini->export[i])
	{
		if (ft_strcmp(g_mini->export[i], "PWD="))
		{
			free(g_mini->export[i]);
			g_mini->export[i] = ft_strdup("PWD=");
			g_mini->export[i] = ft_strjoin(g_mini->export[i], g_mini->new_pwd);
		}
		if (ft_strcmp(g_mini->export[i], "OLDPWD="))
		{
			free(g_mini->export[i]);
			g_mini->export[i] = ft_strdup("OLDPWD=");
			g_mini->export[i] = ft_strjoin(g_mini->export[i], g_mini->old_pwd);
		}
		i++;
	}
}

void	ft_updatenv(void)
{
	int	i;

	i = 0;
	while (g_mini->env[i])
	{
		if (ft_strcmp(g_mini->env[i], "PWD="))
		{
			free(g_mini->env[i]);
			g_mini->env[i] = ft_strdup("PWD=");
			g_mini->env[i] = ft_strjoin(g_mini->env[i], g_mini->new_pwd);
		}
		if (ft_strcmp(g_mini->env[i], "OLDPWD="))
		{
			free(g_mini->env[i]);
			g_mini->env[i] = ft_strdup("OLDPWD=");
			g_mini->env[i] = ft_strjoin(g_mini->env[i], g_mini->old_pwd);
		}
		i++;
	}
}
