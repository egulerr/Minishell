/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguler <eguler@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:36:51 by eguler            #+#    #+#             */
/*   Updated: 2022/09/12 12:09:47 by eguler           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_check_error(int flag, int index)
{
	if (flag == 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(g_mini->command[0], 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	if (flag == 2)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(g_mini->command[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	if (flag == 3)
	{
		ft_putstr_fd("minishell: export: '", 2);
		ft_putstr_fd(g_mini->command[index], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	if (flag == 4)
	{
		ft_putstr_fd("minishell: unset: '", 2);
		ft_putstr_fd(g_mini->command[index], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
}

void	ft_check_error_2(int flag, int index)
{
	if (flag == 1)
	{
		if (ft_redir_op(g_mini->operator[index + 1]))
		{
			ft_putstr_fd("minishell: syntax error near ", 2);
			ft_putstr_fd("unexpected token ", 2);
			ft_putstr_fd("`", 2);
			ft_putstr_fd(g_mini->operator[index + 1], 2);
			ft_putstr_fd("\'", 2);
			ft_putstr_fd("\n", 2);
		}
		else
		{
			ft_putstr_fd("minishell: syntax error ", 2);
			ft_putstr_fd("near unexpected token `newline'\n", 2);
		}
	}
	if (flag == 2)
	{
		ft_putstr_fd("minishell: syntax error near ", 2);
		ft_putstr_fd("unexpected token `|'\n", 2);
	}
}

int	ft_pipe_cont(void)
{
	int	i;

	i = 0;
	while (i < g_mini->pipe_count)
	{
		if (g_mini->pipe_command[i])
			i++;
		else
			return (0);
	}
	return (1);
}
