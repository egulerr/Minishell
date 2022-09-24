/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:23:13 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/21 13:52:29 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dot_exec(void)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		if (access(g_mini->command[0], X_OK) == 0)
		{
			execve(g_mini->command[0], g_mini->command, g_mini->env);
			exit(0);
		}
		else
			ft_check_error(2, 0);
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

void	ft_dot_exec2(char *com, char **com2)
{
	int		i;
	char	*command;

	i = 0;
	command = ft_calloc(1, 1);
	while (com2[i])
	{
		command = ft_strjoin(command, com2[i++]);
		if (com2[i] != NULL)
			command = ft_strjoin(command, "/");
	}
	printf("%s\n", command);
	if (access(command, X_OK) == 0)
	{
		printf("acces\n");
		ft_dot_run(command, com);
		free(command);
	}
	else
	{
		ft_check_error(2, 0);
		free(command);
	}
}

void	ft_dot_run(char *command, char *com)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(command, &com, g_mini->env);
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
