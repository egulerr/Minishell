/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 01:07:22 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/08 15:03:38 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	l_run_op(void)
{
	int	pid;
	int	i;

	i = 0;
	while (g_mini->op_command[i])
		i++;
	i--;
	pid = fork();
	if (pid == 0)
	{
		dup2(g_mini->l_lastfd, 0);
		close(g_mini->l_lastfd);
		op_start(g_mini->op_command[0]);
		exit(0);
	}
	close(g_mini->l_lastfd);
	wait(NULL);
}

void	r_run_op(void)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(g_mini->r_lastfd, 1);
		close(g_mini->r_lastfd);
		op_start(g_mini->op_command[0]);
		kill(getpid(), SIGTERM);
	}
	close(g_mini->r_lastfd);
	wait(NULL);
}

void	op_start(char *command)
{
	g_mini->command = ft_split(command, ' ');
	if (!ft_command())
		ft_exec_op();
}

void	ft_exec_op(void)
{
	int		i;
	char	*comm;
	char	*com;

	i = 0;
	ft_joinpath();
	com = ft_strdup(g_mini->command[0]);
	while (g_mini->pathlst[i])
	{
		comm = ft_strdup(g_mini->pathlst[i]);
		comm = ft_strjoin(comm, "/");
		comm = ft_strjoin(comm, com);
		if (access(comm, X_OK) == 0)
			ft_exec_op_run(comm);
		i++;
	}
}

void	ft_exec_op_run(char *s)
{
	int	pid;

	pid = 0;
	if (pid == 0)
	{
		execve(s, &g_mini->command[0], g_mini->env);
		kill(getpid(), SIGTERM);
	}
	else
		wait(NULL);
}
