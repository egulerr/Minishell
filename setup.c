/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 10:11:51 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/21 13:48:40 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_minisetup(char **env)
{
	char	*command;

	(void)env;
	while (1)
	{
		signal(SIGINT, ft_signal);
		signal(SIGQUIT, SIG_IGN);
		command = readline("./minishell@>_ ");
		add_history(command);
		if (command == NULL)
		{
			printf("exit\n");
			exit(g_mini->dolar_number);
		}
		if (ft_space_cont(command))
			free(command);
		else if (ft_pipe_control(command))
		{
			if (g_mini->pipe_count == 1)
				ft_norm_start(command);
			else if (g_mini->pipe_count > 1)
				ft_pipe_start(command);
		}
		g_mini->pipe_count = 0;
	}
}

void	ft_pipe_start(char *command)
{
	int	i;
	int	flag;

	i = 0;
	g_mini->pipe_command = ft_split_quote(command, '|');
	flag = ft_pipe_cont();
	if (flag == 1)
	{
		while (g_mini->pipe_command[i])
		{
			g_mini->pipe_command[i] = ft_strtrim(g_mini->pipe_command[i], " ");
			i++;
		}
		ft_pipe();
		ft_double_free(g_mini->pipe_command);
		ft_double_free_int(g_mini->fd);
		free(g_mini->pid_list);
		free(command);
	}
	else
	{
		ft_check_error_2(2, 0);
		ft_double_free(g_mini->pipe_command);
		free(command);
	}
}

void	start(char *command)
{
	g_mini->command = ft_split_quote(command, ' ');
	if (!ft_command())
	{
		if (ft_strchr(g_mini->command[0], '/'))
		{
			ft_dot_exec();
		}
		else
		{
			ft_exec();
		}
	}
	free(command);
	ft_free();
}

void	ft_norm_start(char *command)
{
	command = ft_dolar(command);
	command = ft_strtrim(command, " ");
	if (command == NULL)
		ft_putstr_fd("exit\n", 2);
	else if (ft_op_control(command))
	{
		g_mini->redir_command = ft_strdup(command);
		g_mini->op_command = ft_split_quote(command, ' ');
		ft_redir_cont();
		ft_redir_start();
		ft_double_free(g_mini->op_command);
		ft_double_free(g_mini->operator);
		free(g_mini->redir_command);
		free(command);
	}
	else
	{
		if (command[0] != 0)
			start(command);
		else
			free(command);
	}
}
