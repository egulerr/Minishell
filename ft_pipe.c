/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 09:55:52 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/20 23:36:18 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe_control(char *command)
{
	int		i;
	int		flag;
	char	**str;

	i = -1;
	flag = 0;
	if (command != NULL)
	{
		str = ft_split_quote(command, ' ');
		if (command == 0)
			return (1);
		while (str[++i])
		{
			flag = ft_cont_quote(str[i]);
			ft_howmany_pipe(str, flag, i);
		}
		g_mini->pipe_count += 1;
		ft_double_free(str);
		return (1);
	}
	return (0);
}

void	ft_pipe(void)
{
	int	i;

	i = -1;
	g_mini->fd = malloc(sizeof(int *) * g_mini->pipe_count);
	while (++i < g_mini->pipe_count)
	{
		g_mini->fd[i] = malloc(sizeof(int) * 2);
		pipe(g_mini->fd[i]);
	}
	i = -1;
	g_mini->pid_list = malloc(sizeof(int) * g_mini->pipe_count);
	while (++i < g_mini->pipe_count)
	{
		g_mini->pid_list[i] = fork();
		if (g_mini->pid_list[i] == 0)
		{
			ft_fork(i);
			ft_norm_start(g_mini->pipe_command[i]);
			exit (0);
		}
		ft_close(i);
	}
	i = 0;
	while (i++ < g_mini->pipe_count)
		wait(NULL);
}

void	ft_fork(int i)
{
	if (i == 0)
	{
		dup2(g_mini->fd[i + 1][1], STDOUT_FILENO);
		ft_close(i);
	}
	else if ((i + 1) == (g_mini->pipe_count + 1))
	{
		dup2(g_mini->fd[i][0], STDIN_FILENO);
		ft_close(i);
	}
	else
	{
		dup2(g_mini->fd[i][0], STDIN_FILENO);
		if ((i + 1) != g_mini->pipe_count)
			dup2(g_mini->fd[i + 1][1], STDOUT_FILENO);
		ft_close(i);
	}
}

void	ft_close(int i)
{
	close(g_mini->fd[i][0]);
	close(g_mini->fd[i][1]);
}
