/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 10:40:19 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/20 23:38:59 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec2(char *com, int *flag, int i)
{
	char	*comm;

	comm = ft_strdup(g_mini->pathlst[i]);
	comm = ft_strjoin(comm, "/");
	comm = ft_strjoin(comm, com);
	if (access(comm, X_OK) == 0)
	{
		ft_exec_run(comm);
		*flag = 1;
	}
	else if (access(com, X_OK) == 0)
	{
		ft_exec_run_2(com);
		*flag = 1;
	}
	if (comm != NULL)
		free(comm);
}

void	ft_exec(void)
{
	int		i;
	int		flag;
	char	*com;

	i = 0;
	flag = 0;
	if (ft_joinpath())
	{
		com = ft_strdup(g_mini->command[0]);
		while (g_mini->pathlst[i])
		{
			if (flag == 0)
				ft_exec2(com, &flag, i);
			i++;
		}
		free(com);
		ft_freepath();
		if (flag == 0)
		{
			g_mini->dolar_number = 32512 / 256;
			ft_check_error(1, 0);
		}
	}
	else
		ft_check_error(2, 0);
}

void	ft_exec_run_2(char *s)
{
	pid_t	pid;
	int		i;

	i = -1;
	pid = fork();
	while (g_mini->command[++i])
		g_mini->command[i] = ft_return_equal_com(g_mini->command[i]);
	if (pid == 0)
	{
		execve(s, g_mini->command, g_mini->env);
		exit(0);
	}
	else
	{
		waitpid(pid, &g_mini->dolar_number, 0);
		if (WIFSIGNALED(g_mini->dolar_number))
			g_mini->dolar_number = 130;
		else
			g_mini->dolar_number = WEXITSTATUS(g_mini->dolar_number);
	}
}

void	ft_exec_run(char *s)
{
	pid_t	pid;
	int		i;

	i = -1;
	pid = fork();
	while (g_mini->command[++i])
		g_mini->command[i] = ft_return_equal_com(g_mini->command[i]);
	if (pid == 0)
	{
		execve(s, &g_mini->command[0], g_mini->env);
		exit(0);
	}
	else
	{
		waitpid(pid, &g_mini->dolar_number, 0);
		if (WIFSIGNALED(g_mini->dolar_number))
			g_mini->dolar_number = 130;
		else
			g_mini->dolar_number = WEXITSTATUS(g_mini->dolar_number);
	}
}
