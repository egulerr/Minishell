/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_control_4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:58:07 by malasaha          #+#    #+#             */
/*   Updated: 2022/09/12 20:35:57 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_redir_run(void)
{
	if (g_mini->ll_flag == 1)
	{
		ft_redir_double_little();
		return ;
	}
	if (g_mini->r_flag == 1 && g_mini->l_flag == 1)
		ft_redir_double_penetration();
	else if (g_mini->l_flag == 0 && g_mini->r_flag == 1)
		ft_redir_bigger_start();
	else if (g_mini->l_flag == 1 && g_mini->r_flag == 0)
		ft_redir_little_start();
}

void	ft_redir_double_run(char *str)
{
	char	*command;

	while (1)
	{
		command = readline(">_ ");
		if (!ft_strcmp2(command, str))
		{
			close(g_mini->ll_pipe[1]);
			break ;
		}
		else
		{
			write(g_mini->ll_pipe[1], command, ft_strlen(command));
			write(g_mini->ll_pipe[1], "\n", 1);
		}
	}
}

void	ft_operator_initialize(void)
{
	g_mini->r_lastfd = 0;
	g_mini->l_lastfd = 0;
	g_mini->l_flag = 0;
	g_mini->r_flag = 0;
}

int	ft_operator_error(char **str, int a)
{
	ft_check_error_2(1, a);
	ft_double_free(str);
	return (1);
}
