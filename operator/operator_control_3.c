/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_control_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:51:26 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/08 14:58:59 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_redir_bigger_start(void)
{
	int		pid;
	char	**str;

	str = ft_split_quote(g_mini->redir_command, '>');
	pid = fork();
	if (pid == 0)
	{
		dup2(g_mini->r_lastfd, 1);
		close(g_mini->r_lastfd);
		op_start(str[0]);
		exit(0);
	}
	close(g_mini->r_lastfd);
	wait(NULL);
	ft_double_free(str);
}

void	ft_redir_little_start(void)
{
	int		pid;
	char	**str;

	str = ft_split_quote(g_mini->redir_command, '<');
	pid = fork();
	if (pid == 0)
	{
		dup2(g_mini->l_lastfd, 0);
		close(g_mini->l_lastfd);
		op_start(str[0]);
		exit(0);
	}
	close(g_mini->l_lastfd);
	wait(NULL);
	ft_double_free(str);
}

void	ft_redir_double_penetration(void)
{
	int		pid;
	char	**str;

	str = ft_redir_stabilizer();
	pid = fork();
	if (pid == 0)
	{
		dup2(g_mini->l_lastfd, 0);
		dup2(g_mini->r_lastfd, 1);
		close(g_mini->l_lastfd);
		close(g_mini->r_lastfd);
		op_start(str[0]);
		exit(0);
	}
	close(g_mini->l_lastfd);
	close(g_mini->r_lastfd);
	wait(NULL);
	ft_double_free(str);
}

void	ft_redir_double_little(void)
{
	int		pid;
	char	**str;

	str = ft_redir_stabilizer();
	pid = fork();
	if (pid == 0)
	{
		close(g_mini->ll_pipe[1]);
		dup2(g_mini->ll_pipe[0], 0);
		close(g_mini->ll_pipe[0]);
		if (g_mini->r_flag == 1)
		{
			dup2(g_mini->r_lastfd, 1);
			close(g_mini->r_lastfd);
		}
		op_start(str[0]);
		exit(0);
	}
	close(g_mini->ll_pipe[1]);
	close(g_mini->ll_pipe[0]);
	wait(NULL);
	ft_double_free(str);
}
